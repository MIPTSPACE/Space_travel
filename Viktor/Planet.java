package com.company;
import org.json.simple.JSONObject;
import org.json.simple.JSONArray;
import org.json.simple.JSONValue;

/**
 * Created by user on 29.04.2015.
 */

public class Planet {
    public double rPlanet;
    public double mass;
    public double rSphereOfInfluence;
    public double rOrbit; // рассто€ние планеты от —олнца в момент, когда корабль находитс€ близко к ней
    public double v; // скорость планеты в —.ќ. —олнца в момент, когда корабль находитс€ близко к ней

    public void read(String s) {
        Object obj=JSONValue.parse(s);
        JSONArray array=(JSONArray)obj;
        rPlanet = Double.parseDouble(array.get(0).toString());
        mass = Double.parseDouble(array.get(1).toString());
        rSphereOfInfluence = Double.parseDouble(array.get(2).toString());
        rOrbit = Double.parseDouble(array.get(3).toString());
        v = Double.parseDouble(array.get(4).toString());
    }

}
