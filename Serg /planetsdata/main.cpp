#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Planets_data{
public:
        string data[23];
        string Orbitalchar="Orbitalnye harakteristiki";
        string Fchar= "Fizicheskie harakteristiki   ";


       void getdata(string h,int i){
             data[i]=h;
        }
};
int main(int argc, char *argv[])
{   Planets_data A;
    //read data
    ifstream f;
    string s="../../Program_data/Planets/Characteristics/";
    //s+=argv[1];
    s+="1";

    cout <<s.c_str()<<endl;
    f.open(s.c_str(),ios_base::in);
    cout<<f.is_open();
    s="";
    for (int i=0;i<23;i++){
        f>>s;
         A.getdata(s,i);
       f>>s;
    }

    f.close();
    cout<<A.data[2]<<endl;

    return 0;
}

