#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int exchangedata(){
	pid_t pid;
	pid=fork();
	int a=0;
	if  (pid<0) {return -1;}
	else if (pid==0) {
        //here is a client part!

	}
	else {
		(void)execlp("java","java","Server",NULL);
	}



}
int main(int argc,char *argv[], char *env[]){
    exchangedata();
    return 0;

}
