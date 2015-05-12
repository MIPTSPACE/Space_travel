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
//[0]Qmapfirstword

void on_move(QString s){
    global="i'm in on_move="+s;
}
void on_stop(QString s){
    global="i'm in on_stop="+s;
}
void on_stepw(QString s){
    global="i'm in on_step>>="+s;
}
void on_stepl(QString s){
    global="i'm in on_step<<="+s;
}
void on_start(QString s){
    global="i'm in on_start="+s;
}
void on_exxxit(QString s){
    exit(1);
}//+++
void on_pplot(QString s){
    global="i'm in on_plot="+s;
}
void on_change(QString s){
    global="i'm in on_change="+s;
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
      QStringList mylist=splitintowords(s," ");
     if(mapshow.contains(mylist[0])){
          s.remove(0,mylist[0].length());
          (*(void(*)(QString))mapshow[mylist[0]])(s);
       }
      else global=mylist[0];
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
}
//end of Qmapfirstword

//[1]Qmapshow
void on_show_date(QString s){
    global="here is your date  ";
}
void on_show_planet(QString s){
     if(s.indexOf("position")>0){
         s.remove(s.indexOf("position"),s.length());
         s=s.simplified();
         QStringList mylist=splitintowords(s," ");
         //if s.contains()

     }
     else if (s.indexOf("speed")>0) global="here is a speed";
            else global="error";
}

void creatQmapshow(){
   mapshow["planet"]=(void*)on_show_planet;
   mapshow["date"]=(void*)on_show_date;
   //mapshow["forse"]=(void*)on_show_forse;
}
//end of mapshow

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


