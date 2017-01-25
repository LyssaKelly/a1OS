#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern char **getln();
pid_t child_pid;
pid_t wpid;
pid_t pid;
void decipher(char** args);

main() {
	int i;
	char **args; 
	
	while(1) {
		args = getln();
		for(i = 0; args[i] != NULL; i++) {
			printf("Argument %d: %s\n", i, args[i]);
			//printf("Args is now %s\n", args[i]);

		}
		decipher(args);
		printf("Args is now %s\n", args[0]);
		printf("Args is now %s\n", args[1]);
		//decipher(args);
	}
}

void decipher(char** args){
	char* exit1 = "exit";
	char* ls1 = "ls";
	int status = 0;
	int counter = 0;
	printf("Here is the argument: %s\n", args[0]);
	if(strcmp(args[0], exit1) == 0){
		exit(0);
	}
	else if(strcmp(args[0], "") == 0){
		printf("no command entered\n");
	}//need to fix, seg faults out like a bitch
	else{ 
		for(int i = 0; args[i] != NULL; i++){
			counter +=1 ;
		}
		if(strcmp(args[counter - 1], "&") == 0){
			//run background instd
			printf("FIrst block of code is running\n");
			child_pid = fork();
    		if(child_pid == 0) {
    			execvp(args[0], args);
    			printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0)  {
        	// Is the parent process 
        	pid = getpid();
        	printf("parent id is now = %d\n", pid);
        	//wpid = wait(NULL);
        	//if(wpid != -1)  {
            	printf("Child exit status %d\n", status);
            	if(status > 0)  {
                	printf("Accept\n");
            	} 
            	else{
                	printf("Complete parent process\n");
            	}
        	}

		}
		else{
			printf("running 2nd block of code");
			child_pid = fork();
    		if(child_pid == 0) {
    			execvp(args[0], args);
    			printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0)  {
        	/* Is the parent process */
        	pid = getpid();
        	printf("parent id is now = %d\n", pid);
        	wpid = wait(&status);
        	if(wpid != -1)  {
            	printf("Child exit status %d\n", status);
            	if(status > 0)  {
                	printf("Accept\n");
            	} 
            	else  {
                	printf("Complete parent process\n");
            	}
        	}
    	}
    	else{
    		printf("Didnt make the child\n");
    	}
    }
}
	
	}


