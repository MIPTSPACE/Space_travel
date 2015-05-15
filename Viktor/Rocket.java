package com.company;

import org.json.simple.JSONArray;
import org.json.simple.JSONValue;

/**
 * Created by user on 23.04.2015.
 */

public class Rocket {

    public double I; //удельный импульс двигателя
    public double k;    //коэффициент, показывающий, какое количество топлива приходится на единицу массы конструкции,
                        //зависит также от усреднённой плотности топлива - выбор вида топлива
    public double m0; //масса полезного груза
    public int n1 = 1; // количество ступеней для вывода на круговую орбиту

    public double mStart;
    public double mOnCircularOrbit;
    public double mOnTransitionalOrbit;
    public double mOnEllipticalOrbit;
    public double mLandingModule;

    public double mStageCorrection;
    public double mStageToTransitionalOrbit;
    public double mStageToCircularOrbit;

    private int cost; //Cost per launch, $
    private int massEmpty; //in kg
    private int massFuel;

    public void read(String s) {
        Object obj= JSONValue.parse(s);
        JSONArray array=(JSONArray)obj;
        I = Double.parseDouble(array.get(0).toString());
        k = Double.parseDouble(array.get(1).toString());
        m0 = Double.parseDouble(array.get(2).toString());
    }
}
