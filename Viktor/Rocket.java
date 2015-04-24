package com.company;

/**
 * Created by user on 23.04.2015.
 */

public class Rocket {
    private String name;
    private String function;
    private String origin; //Country of origin
    private int cost; //Cost per launch, $
    private int height; //Height, metres
   // private int stages; //Stages number
    private int massEmpty; //in kg
    private int massFuel;
    private int thrust; // kN
    private int specificImpulse; // seconds,  F(thrust) = SI * g * dm/dt;

    public void launch() {
        System.out.println("3...2...1...launch");
    }
}
