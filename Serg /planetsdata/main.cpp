#include <iostream>
#include <string>
#include <fstream>
#include<stdio.h>

using namespace std;

class Planets_data{

public:
        string data[23];

        void getdata(string h,int i){
             data[i]=h;
        }
        void changedata(string h,int i){

        }
};
int main(int argc, char *argv[])
{   Planets_data A;
    //read data
    ifstream f;
   // s+=argv[1];
    f.open(s.c_str(),ios_base::in);
    if (f.is_open()==0 ) cout<<"there is not a file with such planet"<<endl;
    else{
        s="";
        for (int i=0;i<23;i++){
            getline(f,s);
            A.getdata(s,i);
            }

            f.close();
            cout<<"I'm here"<<endl;

}
    return 0;
}

