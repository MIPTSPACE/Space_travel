#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include<stdio.h>
#include <stdlib.h>

using namespace std;

class Planets_data{
private:
        void getdata(string h,int i){
            data[i]=h;
        }


public:
        string data[200];

        void downloaddata(char *q){
           string s="";
           ifstream f;

           s+=q;
           f.open(s.c_str(),ios_base::in);
           if (f.is_open()==0 ) cout<<"there is not a file with such planet"<<endl;
           else{
                s="";
                int i;

                string::size_type cheker;
                while (!f.eof()){
                      getline(f,s);
                      cheker=s.find("***");
                      if (cheker != string::npos){
                          i=atoi((s.substr(0,cheker)).c_str());
                          s=s.substr(cheker+3,s.length());
                          getdata(s,i);
                          i=0;
                      }
                      s.clear();

                      }

                }

                f.close();
              }




        void changedata(string h,int i){

        }
};
int main(int argc, char *argv[])
{   Planets_data A;

   A.downloaddata(argv[1]);
    int i;
    for (i=0;i<23;i++)
          cout<<A.data[i]<<endl;

    return 0;
}

