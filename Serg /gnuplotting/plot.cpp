#include <iostream>
#include "gnuplot.h"
#include<string>
#include <sys/stat.h>
bool fileExists(const std::string& file) {
    struct stat buf;
    return (stat(file.c_str(), &buf) == 0);
}
void plotting(short what,string path,string savename){
   Gnuplot plot;
   plot("reset\n");
   string command="";

   switch (what){
        case 1 : {  if (fileExists(path)){
                        command="set title \"The dependence of fuel from the time\"\n";
                        plot(command);
                        command="set xlabel \"time\"\n";
                        plot(command);
                        command="set ylabel \"fuel\"\n";
                        plot(command);
                        command="plot\""+path+"\"using 1:2 with lines\n";
                        plot(command);
                        plot("set terminal png");
                        command="set output\""+savename+"\"\n";
                        plot(command);
                        command="plot\""+path+"\"using 1:2 with lines\n";
                        plot(command);
                    }
                    break;
                    }
        case 2:  {  if (fileExists(path)){
                        command="set title \"The dependence of speed from the time\"\n";
                        plot(command);
                        command="set xlabel \"time\"\n";
                        plot(command);
                        command="set ylabel \"speed\"\n";
                        plot(command);
                        command="plot\""+path+"\"using 1:2 with lines\n";
                        plot(command);
                        plot("set terminal png");
                        command="set output\""+savename+"\"\n";
                        plot(command);
                        command="plot\""+path+"\"using 1:2 with lines\n";
                        plot(command);
                        }
                    break;
                    }
        case 3:   {if (fileExists(path)){
                        command="set title \"\"\n";
                        plot(command);
                        command="set xlabel \"time\"\n";
                        plot(command);
                        command="set ylabel \"speed\"\n";
                        plot(command);
                        command="plot\""+path+"\"using 1:2 with lines\n";
                        plot(command);
                        plot("set terminal png");
                        command="set output\""+savename+"\"\n";
                        plot(command);
                        command="plot\""+path+"\"using 1:2 with lines\n";
                        plot(command);
                    }
                    break;
                    }
   }
}

int main()
{
int number;
    plotting(1,"data.data","secondtaskk.png");
 std::cin>>number;
return 0;


}
