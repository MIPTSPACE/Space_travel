#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include<stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Planets_data{
private:
        void getdata(string h,int i){
            data[i]=h;
        }
        void datanull(){
        for (int i=0;i<200;i++)
            data[i]="$%^";
        }
        string convertInt(int number)
        {
           stringstream ss;
           ss << number;
           return ss.str();
        }
        bool planetdataexist(char* q){
            ifstream f;
             f.open(q,ios_base::in);
             if (f.is_open()==0 ) {
                 f.close();
                 return false;
             }
             else{
                 f.close();
                 return true;
             }
        }

public:
        string data[200];

        void downloaddataplanet(char *q){
           string s="";
           ifstream f;

           s+=q;
           f.open(s.c_str(),ios_base::in);
           datanull();
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
        void changedataplanet(string h,int what,char* planet){
            ofstream f1;
            downloaddataplanet(planet);
            data[what].clear();
            std::string mystr;
            mystr=convertInt(what);
            mystr+="***";
            data[what]=mystr+h+"\n";
            string s;
            s=planet;
            f1.open(s.c_str(),ios_base::out);
            for(int i=1;i<200;i++){
                if(data[i]!="$%^"){
                        if(i==what) f1.write(data[i].c_str(),data[i].length());
                        else{
                        mystr.clear();
                        mystr=convertInt(i);
                        data[i]=mystr+"***"+data[i]+"\n";
                        f1.write(data[i].c_str(),data[i].length());
                    }

                }
            }
            f1.close();

        }
        void deletesomedata(int what,char*planet){
            if (!planetdataexist(planet)) cout<<"there is not such file"<<endl;
            else{

                    string s;
                    s=planet;


                    downloaddataplanet(planet);
                    ofstream f;
                     f.open(s.c_str(),ios_base::out);
                    data[what]="$%^";
                    for(int i=1;i<200;i++){
                        if(data[i]!="$%^"){
                            s.clear();
                            s=convertInt(i);
                            data[i]=s+"***"+data[i]+"\n";
                           f.write(data[i].c_str(),data[i].length());
                            }

                    }

                 f.close();
             }

        }
        void deletedataplanet(char*planet){
            cout<<remove(planet);
        }
   /*     void creatdataplanet(char *planet,int argc,char *arg){
            if (planetdataexist(planet)) cout <<"error"<<endl;
            else{
                datanull();
                string s=planet;
                ofstream f;
                 f.open(s.c_str(),ios_base::out);

               for(int i=1;i<argc;i++){
                   s.clear();
                   s=convertInt(i);
                   data[i]=s+"***"+argv[i]+"\n";
                   f.write(data[i].c_str(),data[i].length());
                   data[i].clear();
                   data[i]=argv[i];
               }

            }
        }*/
};

int main(int argc, char *argv[])
{   Planets_data A;
   // A.downloaddata(argv[1]);
    //A.deletedata(13,argv[1]);
  //   A.creatdataplanet(3,1,"hello");
  // A.changedata("jjjj",2,argv[1]);
   // int i;
   // for (i=0;i<23;i++)
     //     cout<<A.data[i]<<endl;

    return 0;
}

