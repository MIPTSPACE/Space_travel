package com.company;
import java.net.*;
import java.io.*;
import org.json.simple.JSONObject;
import org.json.simple.JSONArray;
import org.json.simple.JSONValue;

public class Main {
    public static void main(String[] args) {
        /*
        ��������:
        �������(1-� ���): {"radius":double, "averageRadiusOfOrbit":double, "massOfPlanet":double, "radiusSphereOfInfluence:double}
        �������(��� ���������): {"timeOfLanding":double, "distance":double} - ����� ����� ����������� (��� ������ t = 0) � ���������� � ������ t
        � ���� ���� ���������� {"

         */
        String sPlanet = "[3389500, 6.4185e23, 0.577e9, 227.941e9, 24.13e3]";//"radius":double, "massOfPlanet":double, "radiusSphereOfInfluence:double, "averageRadiusOfOrbit":double, "velociry":double
        String sEarth = "[6371000, 5.9726e24, 0.925e9, 149.59787e9, 29.783e3]";
        String sSun = "[0, 1.9891e30, 0, 0, 0]";
        String sRocket = "[2900, 9, 10000]";

        Planet thePlanet = new Planet();
        thePlanet.read(sPlanet);
        Planet earth = new Planet();
        earth.read(sEarth);
        Planet sun = new Planet();
        sun.read(sSun);                     //checked
        Rocket theRocket = new Rocket();
        theRocket.read(sRocket);
        Flight theFlight = new Flight();
    /*
        //Server
        int port = 71035; // ���� (����� ���� ����� ����� �� 1025 �� 65535)
        try {
            ServerSocket ss = new ServerSocket(port); // ������� ����� ������� � ����������� ��� � �������������� �����
            Socket socket = ss.accept(); // ���������� ������ ����� �����������
            // ����� ������� � �������� ������ ������.
            InputStream sin = socket.getInputStream();
            OutputStream sout = socket.getOutputStream();
            // ������ ����� �������� � �������� ������ �������.
            // ������������ ������ � ������ ���, ���� ����� ������������ ��������� ���������.
            DataInputStream in = new DataInputStream(sin);
            DataOutputStream out = new DataOutputStream(sout);

            thePlanet.read(in.readUTF());
            earth.read(in.readUTF());
            sun.read(in.readUTF());
            theRocket.read(in.readUTF());

            theFlight.calcVKepler(thePlanet, earth, sun);
            theFlight.calcV0(earth);
            theFlight.fuelCalculate(theRocket, earth, thePlanet);

            String line = null;
            boolean work = true;
            while(work) {
                line = in.readUTF(); // ������� ���� ������ ������� ������ ������.
                if (line == "exit\n")   // ����
                    work = false;
                else {
                    double distance = Double.parseDouble(line);
                    if (distance < thePlanet.rSphereOfInfluence)
                        work = false;
                    else {
                        theFlight.calcCorrection(sun, distance);
                        out.writeUTF(Double.toString(theFlight.vKeplerStart + theFlight.vCorrection)); // �������� ������� ������� ������ ������.
                        out.flush(); // ���������� ����� ��������� �������� ������.
                    }
                }
            }
            theFlight.fuelCalculate(theRocket, earth, thePlanet);
            out.writeUTF(line); // ���� ������� ������ ��� �������!
        } catch(Exception x) { x.printStackTrace(); }
    */
        theFlight.calcVKepler(thePlanet, earth, sun);
        theFlight.calcV0(earth);
        theFlight.fuelCalculate(theRocket, earth, thePlanet);
    }
}
