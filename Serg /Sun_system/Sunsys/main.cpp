#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
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

    double findforse1by2x(unsigned int whom,unsigned  int who){// кого  кто возращает силу, которая действует на "кого"  по оси х
       double chisl=G*plmas[whom].mass*plmas[who].mass*(plmas[whom].posx-plmas[who].posx);
       double znam=pow((pow((plmas[whom].posx-plmas[who].posx),2)+pow((plmas[whom].posy-plmas[who].posy),2)),(3.0/2.0));
        return -(chisl)/(znam);
}

    double findforse1by2y(unsigned int whom,unsigned int who){// кого  кто возращает силу, которая действует на "кого"  по оси y
        double chisl=G*plmas[whom].mass*plmas[who].mass*(plmas[whom].posy-plmas[who].posy);
        double znam=pow((pow((plmas[whom].posx-plmas[who].posx),2)+pow((plmas[whom].posy-plmas[who].posy),2)),(3.0/2.0));
         return -(chisl)/(znam);
}
    double findFinalForseX(unsigned int who){
        double rez=0;
        for(unsigned int i=0;i<plmas.size();i++)
            if(who!=i) rez+=findforse1by2x(who,i);
        return rez;
    }
    double findFinalForseY(unsigned int who){
        double rez=0;
        for(unsigned int i=0;i<plmas.size();i++)
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

 //data for runge kutta
 struct KuttaAns{
    double posX;
    double posY;
    double speeDX;
    double speeDY;
    };
void OnestepKutta(KuttaAns * data,double h,unsigned int who){
    double v1x,v2x,v3x,v4x,v1y,v2y,v3y,v4y;//koef for speed
    double p1x,p2x,p3x,p4x,p1y,p2y,p3y,p4y;//koef for position
    //SPEED
   // v1x=findFinalForseX(who);
    //v1y=findFinalForseY(who);


}


};

int main(int argc, char *argv[])
{
    Sunsystem_body A;
   A.addplanet("Mars",0,0,1,0,0);
    A.addplanet("Earth",6378000,0,5976e21,0,0);


    cout<<A.findforse1by2x(0,1)<<endl;
    cout<<A.findforse1by2x(1,0)<<endl;
    cout<<endl;
    A.makecopyofplanets();
    cout<<A.plmas1[0].speedx<<endl;
    cout<<A.plmas1[1].posx<<endl;

    //cout<<"sss"<<endl;

    return 0;
}

