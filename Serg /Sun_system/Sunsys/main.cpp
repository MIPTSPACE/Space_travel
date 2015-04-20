#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Sunsystem_body{
private:
double stod(const string &strInput){
    double dbl_one = 0;
   double dbl_two = 0;
   double dbl_final = 0;
   int strlen;
   bool dec_pt = false;
   int nums_before_dec = 0;
   int nums_after_dec = 0;
   strlen = strInput.length();
  /* Check whether the string can be transformed into a number */
  if(strInput[0] == '0' && strInput[1] == '0')
  {
  // invalid number !
  return 0;
  }
  for(int i = 0; i < strlen; i++)
  { if(strInput[i] == '0' || strInput[i] == '1' || strInput[i] == '2' || strInput[i] == '3' || strInput[i] == '4' || strInput[i] == '5' || strInput[i] == '6' || strInput[i] == '7' || strInput[i] == '8' || strInput[i] == '9')
      {
     // valid number
     } else if(strInput[i] == '.'){
     if(dec_pt)
     {
     // there was already a decimal point counted
     // invalid number !
     return 0;
     } else {
     dec_pt = true; // increment by one
     }
     } else {
     // invalid number !
     return 0;
     }
     }
  /* Convert the number */
 // STEP 1: Calculate the amount of numbers before/after the decimal point (if there's one)
  if(dec_pt) // if there's a decimal point in the number
 {
 for(int i = 0; i < strlen; i++)
 {
 if(strInput[i+1] != '.')
 {
 nums_before_dec++;
 } else {
 nums_before_dec++;
 break;
 }
 }
 nums_after_dec = strlen-nums_before_dec;
 nums_after_dec -= 1;
 } else {
 // This piece of code was added later as a BUGFIX !
 // Now the STOD-function is working 100% perfect !!!
 nums_after_dec = 0;
 nums_before_dec = strlen;
 }
 // STEP 2: Convert the string to a real number
 for(int i = 0; i < nums_before_dec; i++)
 {
 switch(strInput[i])
 {
 case '0':
 dbl_one += 0 * apow(10, (nums_before_dec - i));
 break;
 case '1':
 dbl_one += 1 * apow(10, (nums_before_dec - i));
 break;
 case '2':
 dbl_one += 2 * apow(10, (nums_before_dec - i));
 break;
 case '3':
 dbl_one += 3 * apow(10, (nums_before_dec - i));
 break;
 case '4':
 dbl_one += 4 * apow(10, (nums_before_dec - i));
 break;
 case '5':
 dbl_one += 5 * apow(10, (nums_before_dec - i));
 break;
 case '6':
 dbl_one += 6 * apow(10, (nums_before_dec - i));
 break;
 case '7':
 dbl_one += 7 * apow(10, (nums_before_dec - i));
 break;
 case '8':
 dbl_one += 8 * apow(10, (nums_before_dec - i));
 break;
 case '9':
 dbl_one += 9 * apow(10, (nums_before_dec - i));
 break;
 default:
 // invalid number !
 return 0;
 }
 }
 dbl_one = dbl_one / 10; // little fix
for(int i = 0; i < nums_after_dec; i++)
{
switch(strInput[i + nums_before_dec + 1])
{
case '0':
dbl_two += (0 / apow(10, i+1));
break;
case '1':
dbl_two += (1 / apow(10, i+1));
break;
case '2':
dbl_two += (2 / apow(10, i+1));
break;
case '3':
dbl_two += (3 / apow(10, i+1));
break;
case '4':
dbl_two += (4 / apow(10, i+1));
break;
case '5':
dbl_two += (5 / apow(10, i+1));
break;
case '6':
dbl_two += (6 / apow(10, i+1));
break;
case '7':
dbl_two += (7 / apow(10, i+1));
break;
case '8':
dbl_two += (8 / apow(10, i+1));
break;
case '9':
dbl_two += (9 / apow(10, i+1));
break;
default:
// invalid number !
return 0;
}
}
// STEP 3: Return the converted string as a double:
dbl_final = dbl_one + dbl_two;
return dbl_final;
}
/* This function 'apow' raises x to the power of y, it's a dependency of 'stod' */
double apow(const float &x, int y)
{
double result = 1;
if(y == 0)
return result;
if(y < 0)
{
y = -y;
for(int i = 0; i < y; i++)
result = result * x;
return 1/result;
}
for(int i = 0; i < y; i++)
result = result * x;
return result;
}
    void changenumberofplanet(){
        for(int i=0;i<plmas.size();i++)
            plmas[i].number=i;
    }
public:
    int countofplanets=0;
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

void addplanet(string myname,double myposx,double myposy,double mymass,double myspeedx,double myspeedy){
    //data to our struct
    planet n;
    n.name=myname;
    n.mass=mymass;
    n.posx=myposx;
    n.posy=myposy;
    n.speedx=myspeedx;
    n.speedy=myspeedy;
    bool isexist=false;
    for (int i=0;i<plmas.size();i++){
        if (plmas[i].name==myname) isexist=true;
    }
    if (!isexist) {
        n.number=countofplanets;
        ++countofplanets;
        plmas.insert(plmas.end(),n);
        }
}//заполнить информацию о планете
int findplanetbyname(string myname){//-1 not exist
    for(int i=0;i<plmas.size();i++)
        if (plmas[i].name==myname) return i;
    return -1;
}//возвращает номер планеты -1 если она не существует
short deleteplanet(int number){ //-1 не получилось удалить 0 --ok
    if (number<0 ||number>=plmas.size())  return -1;
    else{
        plmas.erase(plmas.begin()+number);
        changenumberofplanet();
        return 0;
    }

}//удаляет планету с номером

short deleteplanet(string name){//-1 не получилось удалить 0---ok
     int i=findplanetbyname(name);

     if (i=-1) return -1;
     else{
         plmas.erase(plmas.begin()+i);
         changenumberofplanet();
         return 0;
     }
}//удаляеьт планету по названию

short changeplanetdata(int numplanet,string myname){//-1 не получилось удалить 0---ok
    if (numplanet<0||numplanet>=plmas.size()) return -1;
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

short changeplanetdata(int numplanet,int what,double val){//-1 не получилось изменить 0---ok
    if (numplanet<0||numplanet>=plmas.size()) return -1;
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
        }
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
            myplanet.posx=stod(s);
            if (f.eof()) break;
            getline(f,s);
            myplanet.posy=stod(s);
            if (f.eof()) break;
            getline(f,s);
            myplanet.mass=stod(s);
            if (f.eof()) break;
            getline(f,s);
            myplanet.speedx=stod(s);
            if (f.eof()) break;
            getline(f,s);
            myplanet.speedy=stod(s);
            addplanet(myplanet.name,myplanet.posx,myplanet.posy,myplanet.mass,myplanet.speedx,myplanet.speedy);

        }
    }
    f.close();
    return 0;

}

};

int main()
{
    Sunsystem_body A;
    A.addplanet("Merqury",123,123,2,3,4);
    A.addplanet("Venues",123,123,2,3,4);
    A.addplanet("Earth",123,123,2,3,4);
    A.addplanet("Mars",123,123,2,3,4);
    A.addplanet("Mars",123,123,2,3,4);
    A.changeplanetdata("Mars",1,1.255);
    cout<<"!!!!"<<A.plmas.size()<<"!!!!!!!!!!!!!!";

    return 0;
}

