#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <time.h>
#define DAYLENGTH   86400 //seconds per day
#define HOURLENGTH  3600//seconds per hour
//doxygen
using namespace std;

class Sunsystem_body{
private:
//data
    static const double G= 6671919999e-20;
//functions

    void changenumberofplanet(){
        for(unsigned int i=0;i<plmas.size();i++)
            plmas[i].number=i;
    }

public:
    Sunsystem_body(){
       countofplanets=0;
    }
//data
unsigned int countofplanets;

    struct planet{
        int number;
        string name;
        double posx;
        double posy;
        double mass;
        double speedx;
        double speedy;
    };
    vector <planet> plmas;
    vector <planet> plmas1;
    vector <planet> sunsys1;
//functions
    void makecopyofplanets(){
        plmas1=plmas;
    }
    void addplanet(string myname,double myposx,double myposy,double mymass,double myspeedx,double myspeedy){
    //data to our struct
    planet n;
    n.name=myname;
    n.mass=mymass;
    n.posx=myposx;
    n.posy=myposy;
    n.speedx=myspeedx;
    n.speedy=myspeedy;
    bool isExist=false;
    for (unsigned int i=0;i<plmas.size();i++){
        if (plmas[i].name==myname) isExist=true;
    }
    if (!isExist) {
        n.number=countofplanets;
        ++countofplanets;
        plmas.insert(plmas.end(),n);
        }
    }//заполнить информацию о планете

     int findplanetbyname(string myname){//-1 not exist
    for( unsigned int i=0;i<plmas.size();i++)
        if (plmas[i].name==myname) return i;
    return -1;
    }//возвращает номер планеты -1 если она не существует

    short deleteplanet(unsigned int number){ //-1 не получилось удалить 0 --ok
    if (number>=plmas.size())  return -1;
    else{
        plmas.erase(plmas.begin()+number);
        changenumberofplanet();
        return 0;
    }

    }//удаляет планету с номером


    int stod(const char *s, double *v)
    {
        enum signs {NEG = -1, NONE = 0, POS = 1};

        int i, dot, x, bError, bExp;
        enum signs sign, esign;
        double d, f;

        sign = esign = NONE;
        i = x = bError = bExp = 0;
        dot = -1;
        d = f = 0.0;
        while (!bError)
        {
            switch (*s)
            {
            case '+':
                if (!bExp)
                {


                    if (sign)
                        bError = 1;
                    else sign = POS;
                }
                else
                {


                    if (esign)
                        bError = 1;
                    else esign = POS;
                }
                   if (i && isdigit(*(s - 1))) bError = 1;
                break;
            case '-':

                if (!bExp)
                {


                    if (sign)
                        bError = 1;
                    else sign = NEG;
                }
                else
                {


                    if (esign)
                        bError = 1;
                    else esign = NEG;
                }



                if (i && isdigit(*(s - 1))) bError = 1;
                break;
            case '.':




                if (!bExp)
                {

                    if (dot > -1) bError = 1;
                    else dot++;
                }
                else bError = 1;
                break;
            case 'e':
            case 'E':



                if (bExp) bError = 1;
                else bExp = 1;
                break;
            default:



                if (isdigit(*s))
                {
                    if (bExp)
                        x = x*10 + (*s - '0');
                    else
                    {
                        if (dot > -1)
                        {
                            f = f*10 + (*s - '0');
                            dot++;
                        }
                        else d = d*10 + (*s - '0');
                    }
                }
                else
                {

                    if (*s == '\0')
                    {

                        *v = d + f*pow(10, -dot);
                        if (x != 0.0) *v *= pow(10, x*(sign == NEG ? -1:1));
                        if (sign == NEG) *v *= -1;
                        return 0;
                    }
                    else bError = 1;
                }
            }
            s++;
            i++;
        }


        return i;
    }

    short deleteplanet(string name){//-1 не получилось удалить 0---ok
     int i=findplanetbyname(name);

     if (i==-1) return -1;
     else{
         plmas.erase(plmas.begin()+i);
         changenumberofplanet();
         return 0;
     }
    }//удаляeт планету по названию

    short changeplanetdata(unsigned int numplanet,string myname){//-1 не получилось удалить 0---ok
    if (numplanet>=plmas.size()) return -1;
    else{
        plmas[numplanet].name=myname;
        return 0;
    }
    }//изменяет имя планеты по ее номеру

    short changeplanetdata(string lastname, string myname){
    int i=findplanetbyname(lastname);
    if (i==-1) return -1;
    else{
        plmas[i].name=myname;
        return 0;
    }
    }//изменяет имя планеты по старому имени

    short changeplanetdata(unsigned int numplanet,int what,double val){//-1 не получилось изменить 0---ok
    if (numplanet>=plmas.size()) return -1;
    else{
        switch (what){
        case 1:     {
                        plmas[numplanet].posx=val;
                        break;
        }
        case 2:     {
                        plmas[numplanet].posy=val;
                        break;
        }
        case 3:     {
                        plmas[numplanet].mass=val;
                        break;
        }
        case 4:     {
                        plmas[numplanet].speedx=val;
                        break;
        }
        case 5:     {
                        plmas[numplanet].speedy=val;
                        break;
        }
        default:     return -1;
        }//enum
        return 0;
    }

    }//изменяет значения характеристики планеты по ее номеру

    short changeplanetdata(string numplanet,int what,double val){//-1 не получилось изменить 0---ok
    int i=findplanetbyname(numplanet);
    if (i==-1) return -1;
    else {
        switch (what){
        case 1:     {
                        plmas[i].posx=val;
                        break;
        }
        case 2:     {
                        plmas[i].posy=val;
                        break;
        }
        case 3:     {
                        plmas[i].mass=val;
                        break;
        }
        case 4:     {
                        plmas[i].speedx=val;
                        break;
        }
        case 5:     {
                        plmas[i].speedy=val;
                        break;
        }
        default:     return -1;
        }
        return 0;

    }

    }//изменяет  значения характеристики планеты по ее названию

    short planet_from_file(string path){//-1 файл не найден 0--ok
    ifstream f;
    string s;
    planet myplanet;
    f.open(path.c_str(),ios::in);
    if (!f.is_open()) return -1;
    else{
        while (!f.eof()){
            getline(f,s);
            myplanet.name=s;
            if (f.eof()) break;
            getline(f,s);
            stod(s.c_str(),&myplanet.posx);
            if (f.eof()) break;
            getline(f,s);
            stod(s.c_str(),&myplanet.posy);
            if (f.eof()) break;
            getline(f,s);
            stod(s.c_str(),&myplanet.mass);
            if (f.eof()) break;
            getline(f,s);
            stod(s.c_str(),&myplanet.speedx);
            if (f.eof()) break;
            getline(f,s);
            stod(s.c_str(),&myplanet.speedy);
            addplanet(myplanet.name,myplanet.posx,myplanet.posy,myplanet.mass,myplanet.speedx,myplanet.speedy);

        }
    }
    f.close();
    return 0;

}

  //data for parser
    struct speedans{
        double speed;
        bool errorrr;
    };

   //functions for parser
//сила в ньютонах  ==
    double findforse1by2x(unsigned int whom,unsigned  int who){// кого  кто возращает силу, которая действует на "кого"  по оси х
       double chisl=G*plmas1[whom].mass*plmas1[who].mass*(plmas1[whom].posx-plmas1[who].posx);
       double znam=pow((pow((plmas1[whom].posx-plmas1[who].posx),2)+pow((plmas1[whom].posy-plmas1[who].posy),2)),(3.0/2.0));
        return -(chisl)/(znam);
}
    double findforse1by2y(unsigned int whom,unsigned int who){// кого  кто возращает силу, которая действует на "кого"  по оси y
        double chisl=G*plmas1[whom].mass*plmas1[who].mass*(plmas1[whom].posy-plmas1[who].posy);
        double znam=pow((pow((plmas1[whom].posx-plmas1[who].posx),2)+pow((plmas1[whom].posy-plmas1[who].posy),2)),(3.0/2.0));
         return -(chisl)/(znam);
}
    double findFinalForseX(unsigned int who){
        double rez=0;
        for(unsigned int i=0;i<plmas1.size();i++)
            if(who!=i) rez+=findforse1by2x(who,i);
        return rez;
    }
    double findFinalForseY(unsigned int who){
        double rez=0;
        for(unsigned int i=0;i<plmas1.size();i++)
            if(who!=i) rez+=findforse1by2y(who,i);
        return rez;
    }

    struct speedans showspeedx(unsigned int numplanet){
        struct speedans ans;
        if (numplanet>plmas.size()){
            ans.errorrr=true;
            return ans;
         }
        else{
            ans.speed=plmas[numplanet].speedx;
            ans.errorrr=false;
            return ans;
        }

    }
    struct speedans showspeedy(unsigned int numplanet){
        struct speedans ans;
        if (numplanet>plmas.size()){
            ans.errorrr=true;
            return ans;
         }
        else{
            ans.speed=plmas[numplanet].speedy;
            ans.errorrr=false;
            return ans;
        }
    }
    struct speedans showspeedx(string planetname){
         int i=findplanetbyname(planetname);
          struct speedans ans;
         if (-1==i){
             ans.errorrr=true;
             return ans;
         } else {
             return showspeedx((unsigned int )i);
         }

    }
    struct speedans showspeedy(string planetname){
        int i=findplanetbyname(planetname);
         struct speedans ans;
        if (-1==i){
            ans.errorrr=true;
            return ans;
        } else {
            return showspeedy((unsigned int)(i));
        }

    }
//cheker metka
 //data for runge kutta
 struct KuttaAns{
    double posX;
    double posY;
    double speeDX;
    double speeDY;
    };
void OnestepKutta(double h,unsigned int who){
    double v1x,v2x,v3x,v4x,v1y,v2y,v3y,v4y;//koef for speed
    double p1x,p2x,p3x,p4x,p1y,p2y,p3y,p4y;//koef for position
    this->makecopyofplanets();
    vector <planet> copyofbegdata;
    double vx,vy;
    vx=plmas1[who].speedx;
    vy=plmas1[who].speedy;
    copyofbegdata=plmas1;
    v1x=h*findFinalForseX(who)/plmas1[who].mass;
    v1y=h*findFinalForseY(who)/plmas1[who].mass;
    p1x=h*vx;
    p1y=h*vy;
    plmas1[who].posx+=p1x/2.0;
    plmas1[who].posy+=p1y/2.0;
    v2x=h*findFinalForseX(who)/plmas1[who].mass;
    v2y=h*findFinalForseY(who)/plmas1[who].mass;
    p2x=h*(vx+v1x/2.0);
    p2y=h*(vy+v1y/2.0);
    plmas1=copyofbegdata;
    plmas1[who].posx+=p2x/2.0;
    plmas1[who].posy+=p2y/2.0;
    v3x=h*findFinalForseX(who)/plmas1[who].mass;
    v3y=h*findFinalForseY(who)/plmas1[who].mass;
    p3x=h*(vx+v2x/2.0);
    p3y=h*(vy+v2y/2.0);
    plmas1=copyofbegdata;
    plmas1[who].posx+=p3x/2.0;
    plmas1[who].posy+=p3y/2.0;
    v4x=h*findFinalForseX(who)/plmas1[who].mass;
    v4y=h*findFinalForseY(who)/plmas1[who].mass;
    p4x=h*(vx+v3x/2.0);
    p4y=h*(vy+v3y/2.0);
    plmas[who].posx+=(p1x+2*p2x+2*p3x+p4x)*1.0/6.0;
    plmas[who].posy+=(p1y+2*p2y+2*p3y+p4y)*1.0/6.0;
    plmas[who].speedx+=(v1x+2*v2x+2*v3x+v4x)*1.0/6.0;
    plmas[who].speedy+=(v1y+2*v2y+2*v3y+v4y)*1.0/6.0;


}
void OnestepKuttaforall(double h){
    for(unsigned int i=0;i<plmas.size();i++){
        OnestepKutta(h,i);
    }
}
void DayofstepsKutta(long days){
    long i;
    for(i=0;i<days;i++){
        OnestepKuttaforall(DAYLENGTH);
    }

}
//functions for movements from one system to another

bool insusys_exist(){
    if (sunsys1.size()>0) return true;
    else return false;
}
void creatsunsys1(){
    planet p;
    for (unsigned i=0;i<plmas.size();i++)
        sunsys1.insert(sunsys1.end(),p);
}
 void  insusys(){
       if (!insusys_exist()) creatsunsys1();
      for(int i=1;i<plmas.size();i++){
          sunsys1[i].name=plmas[i].name;
          sunsys1[i].mass=plmas[i].mass;
          sunsys1[i].posx-=plmas[0].posx;
          sunsys1[i].posy-=plmas[0].posy;
          sunsys1[i].speedx-=plmas[0].speedx;
          sunsys1[i].speedy-=plmas[0].speedy;

      }
 }
//[0] Sun system

//functions for rockets

};

int main(int argc, char *argv[])
{
    Sunsystem_body A;
       A.addplanet("Earth",0,0,5.974e24,0,0);
       A.addplanet("Moon",0,384.4e6,7.3477e22,1000,0);
       A.makecopyofplanets();
       cout<<"Moon"<<endl;
       cout<<"posx="<<A.plmas[1].posx<<endl;
       cout<<"posy="<<A.plmas[1].posy<<endl;
       cout<<"speedx="<<A.plmas[1].speedx<<endl;
       cout<<"speedy="<<A.plmas[1].speedy<<endl;
       cout<<"Earth"<<endl;
       cout<<"posx="<<A.plmas[0].posx<<endl;
       cout<<"posy="<<A.plmas[0].posy<<endl;
       cout<<"speedx="<<A.plmas[0].speedx<<endl;
       cout<<"speedy="<<A.plmas[0].speedy<<endl;
       cout<<endl<<endl;
       cout<<(sqrt((A.plmas[0].posx-A.plmas[1].posx)*(A.plmas[0].posx-A.plmas[1].posx)+(A.plmas[0].posy-A.plmas[1].posy)*(A.plmas[0].posy-A.plmas[1].posy)))<<endl;
       for(int i=0; i<24*273*6*30;i++){
           A.OnestepKuttaforall(20);
       }
       cout<<(sqrt((A.plmas[0].posx-A.plmas[1].posx)*(A.plmas[0].posx-A.plmas[1].posx)+(A.plmas[0].posy-A.plmas[1].posy)*(A.plmas[0].posy-A.plmas[1].posy)))<<endl;
       cout<<"Moon"<<endl;
A.insusys();
       cout<<"posx="<<A.plmas[1].posx<<endl;
       cout<<"posy="<<A.plmas[1].posy<<endl;
       cout<<"speedx="<<A.plmas[1].speedx<<endl;
       cout<<"speedy="<<A.plmas[1].speedy<<endl;
       cout<<"Earth"<<endl;
       cout<<"posx="<<A.plmas[0].posx<<endl;
       cout<<"posy="<<A.plmas[0].posy<<endl;
       cout<<"speedx="<<A.plmas[0].speedx<<endl;
       cout<<"speedy="<<A.plmas[0].speedy<<endl;
       cout<<endl<<endl;

  // while(fabs(A.plmas[1].posx-384.4e6)>100){
    //    A.OnestepKuttaforall(1);
   // }

    return 0;
}

