#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sunsystem_body{
private:
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
    ifstream  f;
    string s;
    planet myplanet;
    if (f.open(path,ios::nocreate)==false) return -1;
    else{
        while (!f.eof){
            getline(f,s);
            meplanet.name=s;

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

