#include <stdio.h>
//#include "storeval.h"
#include <string.h>

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

int main(){
	//needs to call the different fucntions

	return 0;
}


int reader(){
j
}

int interpreter(int choice){
	if(choice == 1){
		exit();
	}
	else if(choice == 2){

	}
}

int exit(){
	exit();
}

int noArgs(){
	pid_t  pid;
	pid = fork();
    if (pid == 0) 
        ChildProcess();
    else 
        ParentProcess();
    	printf("Didn't fork properly");
}