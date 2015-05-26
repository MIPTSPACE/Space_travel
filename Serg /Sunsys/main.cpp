#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <time.h>

#include "sunsystem_body.h"
#include "sunsystem_ui.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*
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
    */
    QApplication app(argc, argv);
    Sunsystem_body obj;
    obj.addplanet(23,1);
    obj.addplanet(27,2);
    obj.addplanet(32,3);
    obj.addplanet(38,3);
    obj.addplanet(60,10);
    obj.addplanet(70,8);
    obj.addplanet(80,6);
    obj.addplanet(90,6);
    Sunsystem_UI wnd(&obj);
    wnd.show();
    return app.exec();
    return 0;
}

