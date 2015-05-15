package com.company;

import static java.lang.Math.*;
/**
 * Created by user on 25.04.2015.
 */

public class Flight {
    final double G = 6.67384e-11;

    public void set(Rocket theRocket) {
        theRocket.I = 2900; //тест
        theRocket.k = 9;
        theRocket.m0 = 10^4;
        theRocket.n1 = 1;
    }

    public double rEarthCircularOrbit;
    private double vEarthCircularOrbit;
    private double vEarthParabolicOrbit;
    private double vAfterCircularEarthOrbit;
    public double vKeplerStart; // скорость вначале полета в поле притяжения Солнца (и его С.О.)
    public double vKeplerFinish; // скорость вконце полета в поле притяжения Солнца (и его С.О.)
    public double vLoss; // предполагаемые потери на запуске на круговую орбиту
    public double vExitEarthSphere; //в C.О. Земли
    public double vEnterPlanetSphere; //в C.О. Земли
    public double vStart; // d C.O. Солнца ск. в начале гелиоцентрической орбиты (эту скорость и будем корректировать)
    public double vCorrection = 0;


    public void calcVKepler(Planet thePlanet, Planet earth, Planet sun) {
        double a = (earth.rOrbit + thePlanet.rOrbit) / 2;
        double mu = G * sun.mass;
        vKeplerStart = sqrt(mu * (2 / earth.rOrbit - 1 / a));
        vKeplerFinish = sqrt(mu * (2 / thePlanet.rOrbit - 1 / a));
        vAfterCircularEarthOrbit = sqrt(pow(vEarthCircularOrbit, 2) - pow(vEarthParabolicOrbit, 2) * (1 - earth.rOrbit / earth.rSphereOfInfluence));
    }

    public void calcV0(Planet earth) {
        rEarthCircularOrbit = earth.rPlanet * 1.5;
        vEarthCircularOrbit = sqrt(G * earth.mass / rEarthCircularOrbit);
        vEarthParabolicOrbit = sqrt(2) * vEarthCircularOrbit;
        vAfterCircularEarthOrbit = sqrt(pow(vKeplerStart, 2) + pow(vEarthParabolicOrbit, 2) * (1 - rEarthCircularOrbit / earth.rSphereOfInfluence));
    }

    private double mFuel(double V, double m0, double I, double k) {   //возвращает необходимую массу топлива
                                                        //(ракета, характеристическая скорость)
        double e = exp(V / I);
        return m0 * k * (e - 1) / (k + 1 - e); // надо делать проверку какой знак!
    }


    public void fuelCalculate(Rocket theRocket, Planet earth, Planet thePlanet) {
        theRocket.mLandingModule = 0; // !нужно придумать как оценить массу посадочного модуля!
        theRocket.mOnEllipticalOrbit = theRocket.m0 + theRocket.mLandingModule;
        double stageMassFactor = (1 / theRocket.k + 1);
        // (Stage 3) коррекция орбиты на (условной)границе сферы Земли и переход на элиптическую орбиту:
        vStart = vKeplerStart; //!написать расчет коррекции vStart! - здесь будет цикл
        theRocket.mStageCorrection = stageMassFactor * mFuel(vKeplerStart - vStart, theRocket.mOnEllipticalOrbit, theRocket.I, theRocket.k);
        theRocket.mOnTransitionalOrbit = theRocket.mOnEllipticalOrbit + theRocket.mStageCorrection;
        // (Stage 2) разгон после круговой орбиты и выход на транзитную орбиту:
        double t = 0; // time
        vExitEarthSphere = abs(vKeplerStart - earth.v);
        vEnterPlanetSphere = abs(vKeplerFinish - thePlanet.v);
        theRocket.mStageToTransitionalOrbit = stageMassFactor * mFuel(vAfterCircularEarthOrbit - vEarthCircularOrbit, theRocket.mOnTransitionalOrbit, theRocket.I, theRocket.k);
        theRocket.mOnCircularOrbit = theRocket.mOnTransitionalOrbit + theRocket.mStageToTransitionalOrbit;
        // (Stage 1) выход на круговую орбиту:
        vLoss = vEarthCircularOrbit / 5; // оценим vLoss в 20%
        theRocket.mStageToCircularOrbit = stageMassFactor * mFuel(vEarthCircularOrbit + vLoss, theRocket.mOnCircularOrbit, theRocket.I, theRocket.k);
        theRocket.mStart = theRocket.mOnCircularOrbit + theRocket.mStageToCircularOrbit;
    }

    public void calcCorrection(Planet sun, double distance) {
        vCorrection += G * sun.mass * distance / (2 * vCorrection * pow(distance, 2));
    }

    /*
    public boolean criterion(double k, double V, double I) {
        return k + 1 > exp(V / I);
    }
    */
}
