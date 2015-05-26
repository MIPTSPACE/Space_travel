#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QMap>
#include <QString>
QString global="";
QStringList splitintowords(QString s,QString s1){
        return s.split(s1);
}

QMap <QString,void*> mapfirstword;
QMap <QString,void*> mapshow;
QMap <QString,void*> mapchange;
QMap   <QString,void*> mapchangeplanets;

//[0]Qmapfirstword

void on_move(QString s){
    global="i'm in on_move="+s;
}
void on_stop(){
    global="stop!!!";
    //calling function stop
}
void on_stepw(){
    global="i'm in on_step>>=";
    //calling step>>function
}
void on_stepl(){
    global="i'm in on_step<<=";
    //calling step<<< function
}
void on_start(){
    global="i'm in on_start=";
    //calling start!!!
}
void on_exxxit(){
    exit(1);
}//+++
void on_pplot(QString s){
    global="i'm in on_plot="+s;
}
void on_ddelete(QString s){
    global="i'm in on_delete="+s;
}
void on_addplanet(QString s){
    global="i'm in on_addplanet="+s;
}
void on_sshow(QString s){
     QString s1=" ";
     while(s.at(0)==s1.at(0)) s.remove(0,1);
     if(s.length()<=1){ global="error";}
     else{
      QStringList mylist=splitintowords(s," ");
     if(mapshow.contains(mylist[0])){
          s.remove(0,mylist[0].length());
          (*(void(*)(QString))mapshow[mylist[0]])(s);
       }
      else global=mylist[0];
     }
}//+++
void on_change(QString s){
    QString s1=" ";
    while(s.at(0)==s1.at(0)) s.remove(0,1);
     QStringList mylist=splitintowords(s," ");
    if(mapchange.contains(mylist[0])){
         s.remove(0,mylist[0].length());
         (*(void(*)(QString))mapchange[mylist[0]])(s);
      }
     else global="there is not such command";
}
void on_ssave(QString s){
    global="i'm in on_ssave="+s;
}
void on_ddownload(QString s){
    global="i'm in on_download="+s;
}
void on_oopen(QString s){
    global="i'm in on_open="+s;
}
void creatQmapfirstword(){

 mapfirstword["move"]=(void*)on_move;
 mapfirstword["stop"]=(void*)on_stop;
 mapfirstword["step>>"]=(void*)on_stepw;
 mapfirstword["step<<"]=(void*)on_stepl;
 mapfirstword["start"]=(void*)on_start;
 mapfirstword["exit"]=(void*)on_exxxit;
 mapfirstword["plot"]=(void*)on_pplot;
 mapfirstword["change"]=(void*)on_change;
 mapfirstword["delete"]=(void*)on_ddelete;
 mapfirstword["addplanet"]=(void*)on_addplanet;
 mapfirstword["show"]=(void*)on_sshow;
 mapfirstword["save"]=(void*)on_ssave;
 mapfirstword["download"]=(void*)on_ddownload;
 mapfirstword["open"]=(void*)on_oopen;
}//+++
//end of Qmapfirstword

//[1]Qmapshow
void on_show_date(QString s){
    global=QString::number(1997)+"."+QString::number(12)+"."+QString::number(25);
}
void on_show_forse(QString s){
    double posx,posy;
    s=s.simplified();
    QStringList mylist=splitintowords(s," ");
    if (mylist.size()!=2)  global="Format of command must be:show forse  <posx> <posy>";
    else{
        bool ok;
        double d;
        d=mylist.at(0).toDouble(&ok);
        if (ok) posx=d;
        else goto endofforse;
        d=mylist.at(1).toDouble(&ok);
        if (ok) posy=d;
        else goto endofforse;
        global="all is ok!";
 //here should be a part of calling function forse posx, posy
        return;
    }
    endofforse: global="<posx> <pos y>  are incorrect";

}
void on_show_planet(QString s){
     if(s.indexOf("position")>0){
         s.remove(s.indexOf("position"),s.length());
         s=s.simplified();
         QRegExp name_ex("^[a-zA-Z0-9]+$");
         QRegExp number_ex("^\\d\\d?$");

         if(s.contains(number_ex)>0){
             global="Here is a number="+s;
             //find planet by number and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         }
         else if(s.contains(name_ex)>0){
              global=s+"PosX=0  PosY=0";
                  //find planet by name and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         }
         else global="Format of command should be show planet <Name>||<Number> position";


     }
     else if (s.indexOf("speed")>0){
         s.remove(s.indexOf("speed"),s.length());
         s=s.simplified();
         QRegExp name_ex("^[a-zA-Z0-9]+$");
         QRegExp number_ex("^\\d\\d?$");

         if(s.contains(number_ex)>0){
             global="Here is a number="+s;
             //find planet by number and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         }
         else if(s.contains(name_ex)>0){
              global="here is a name"+s;
                  //find planet by name and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         }
         else global="Format of command should be show planet <Name>||<Number> speed";
         }
          else global="error";
}
//on show planet just add calls of functions from sunsystem
void creatQmapshow(){
   mapshow["planet"]=(void*)on_show_planet;
   mapshow["date"]=(void*)on_show_date;
   mapshow["forse"]=(void*)on_show_forse;
}
//end of mapshow
//last cheker: working well

//[2]Qmapchange
void on_change_pto(QString s){
    s=s.simplified();
    QStringList mylist=splitintowords(s," ");
    //proverka na planety
    QString s1=mylist[0];
    QRegExp name_ex("^[a-zA-Z0-9]+$");
    QRegExp number_ex("^\\d\\d?$");

    if(s1.contains(number_ex)>0){
        global="Here is a number="+s1;
        //find planet by number and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else if(s1.contains(name_ex)>0){
         global="here is a name"+s1;
             //find planet by name and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else global="Format of command should be change planet <Name>|| to <Name>";
      //here should be a cod with changing name!
}
void on_change_pposx(QString s){
    s=s.simplified();
    QStringList mylist=splitintowords(s," ");
    //proverka na planety
    QString s1=mylist[0];
    QRegExp name_ex("^[a-zA-Z0-9]+$");
    QRegExp number_ex("^\\d\\d?$");

    if(s1.contains(number_ex)>0){
        global="Here is a number="+s1;
        //find planet by number and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else if(s1.contains(name_ex)>0){
         global="here is a name"+s1;
             //find planet by name and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else global="Format of command should be change planet <Name>||<Number>  posx <posx>";
      //here should be a cod with changing posx!

}
void on_change_pposy(QString s){
    s=s.simplified();
    QStringList mylist=splitintowords(s," ");
    //proverka na planety
    QString s1=mylist[0];
    QRegExp name_ex("^[a-zA-Z0-9]+$");
    QRegExp number_ex("^\\d\\d?$");

    if(s1.contains(number_ex)>0){
        global="Here is a number="+s1;
        //find planet by number and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else if(s1.contains(name_ex)>0){
         global="here is a name"+s1;
             //find planet by name and call DATAPLANETFORM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    else global="Format of command should be change planet <Name>||<Number>  posy <posy>";
      //here should be a cod with changing posy!

}

void on_change_planet(QString s){
    s=s.simplified();
    QStringList mylist=splitintowords(s," ");
    if(mylist.size()!=3){
        global="error in change command";
        return;
    }
    else{
        if(mapchangeplanets.contains(mylist[1])){
             (*(void(*)(QString))mapchangeplanets[mylist[1]])(s);
          }
         else global="error in change planet command";

    }
}
void creatQmapchange(){
    mapchange["planet"]=(void*)on_change_planet;
}
void creatQmapchangeplanets(){
    mapchangeplanets["to"]=(void*)on_change_pto;
    mapchangeplanets["posx"]=(void*)on_change_pposx;
    mapchangeplanets["posy"]=(void*)on_change_pposy;
    mapchangeplanets["posy"]=(void*)on_change_pposy;
}




//part for working with data
#define FIRSTYEAR  1900
#define LASTYEAR   2200

//data
struct mydate{
    int day;
    int S;
    int year;
    bool error;
    QString problem;
};


/*Here is a data format
 * 01/01/1991
 * 01.01.1991
 *
 */


bool isALeapYear( int year )
{   if (year==2000) return true;
    if ( (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
        return true;
    else
        return false;
}

bool Checkermonth(int i){
    if(i<0||i>12) return false;
    return true;
}

bool Checkeryear(int i){
    if(i<FIRSTYEAR||i>LASTYEAR) return false;
    return true;
}

bool Checkerday(int d,int m,int y){
    switch (m)
    {
        case 4 :{
            if(d<0|| d>30) return false;
            else return true;
        }
        case 6 :{
            if(d<0|| d>30) return false;
            else return true;
       }
       case 9 :{
            if(d<0|| d>30) return false;
            else return true;
       }
       case 11 :{
           if(d<0|| d>30) return false;
           else return true;
       }
       case 1 :{
            if(d<0|| d>31) return false;
            else return true;
       }
       case 3 :{
            if(d<0|| d>31) return false;
            else return true;
       }
       case 5 :{
            if(d<0|| d>31) return false;
            else return true;
       }
       case 7 :{
            if(d<0|| d>31) return false;
            else return true;
       }
       case 8 :{
            if(d<0|| d>31) return false;
            else return true;
       }
       case 10 :{
            if(d<0|| d>31) return false;
            else return true;
       }
       case 12: {
            if(d<0||d>31) return false;
            else return true;
                             }
       case 2 :            {
                                if(isALeapYear(y)){
                                    if(d<0 || d>29) return false;
                                    else return true;
                                }
                                else{
                                    if(d<0||d>28) return false;
                                    else return true;
                                }
                            }

    }
   return false;
}

struct mydate  dateformat(QString s){
        QRegExp exp1("[0-9]{1,2}\\/[0-9]{1,2}\\/[0-9]{1,10}");
        QRegExp exp2("[0-9]{1,2}\\.[0-9]{1,2}\\.[0-9]{1,10}");
        mydate ans;ans.error=false;
        QStringList copy;
        QStringList::const_iterator constIterator;
    if (s.contains(exp1)){
        copy=splitintowords(s,"/");
        constIterator=copy.begin();
        ans.day=(*constIterator).toInt();
        ++constIterator;
        ans.S=(*constIterator).toInt();
        ++constIterator;
        if (Checkermonth(ans.S)==false) goto falsemonth;
        ans.year=(*constIterator).toInt();
        if (Checkeryear(ans.year)==false) goto falseyear;
        if (Checkerday(ans.day,ans.S,ans.year)==false) goto falseday;
        return ans;
    }
    else if (s.contains(exp2)){
        copy=splitintowords(s,".");
        constIterator=copy.begin();
        ans.day=(*constIterator).toInt();
        ++constIterator;
        ans.S=(*constIterator).toInt();
        ++constIterator;
         if (Checkermonth(ans.S)==false) goto falsemonth;
        ans.year=(*constIterator).toInt();
        if (Checkeryear(ans.year)==false) goto falseyear;
        if (Checkerday(ans.day,ans.S,ans.year)==false) goto falseday;
        return ans;
        }
        else {
                ans.problem="Wrong data format(use  01/01/1991 or 01.01.1991 )!";
                ans.error=true;
                return ans;
            falsemonth:{
                ans.problem="Wrong month!";
                ans.error=true;
                return ans;
            }
            falseyear:{
                ans.problem="Wrong year!";
                ans.error=true;
                return ans;
            }
            falseday:{
                ans.problem="Wrong day!";
                ans.error=true;
                return ans;
            }

        }
}

QString Parsecommand(QString str){
    if ( str=="") return "Error";
    else{
        str=str.simplified();
        QStringList mylist=splitintowords(str," ");
        creatQmapfirstword();
        creatQmapshow();
        creatQmapchange();
        creatQmapchangeplanets();
        if(mapfirstword.contains(mylist[0])){
            str.remove(0,mylist[0].length());
            (*(void(*)(QString))mapfirstword[mylist[0]])(str);
            return global;
        }
        else return "erorr";

    }
}


QString myanswer(QString s){
    mydate m=dateformat(s);
    if (m.error==false) return QString::number(m.S);
    return m.problem;
}




