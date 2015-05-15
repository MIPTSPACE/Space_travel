package com.company;

import org.json.simple.JSONArray;
import org.json.simple.JSONValue;

/**
 * Created by user on 23.04.2015.
 */

public class Rocket {

    public double I; //�������� ������� ���������
    public double k;    //�����������, ������������, ����� ���������� ������� ���������� �� ������� ����� �����������,
                        //������� ����� �� ���������� ��������� ������� - ����� ���� �������
    public double m0; //����� ��������� �����
    public int n1 = 1; // ���������� �������� ��� ������ �� �������� ������

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
