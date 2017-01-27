#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

extern char **getln();
pid_t child_pid;
pid_t wpid;
pid_t pid;
void decipher(char** args);
void list(char** args);
void add(char** args);
int checker(char* args);
void textOut(char** args);
void textIn(char** args);


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
	else if(strcmp(args[0], "arg") == 0 || strcmp(args[0], "Arg") == 0 || strcmp(args[0], "ARG") == 0){
		//add up the guys
		list(args);
	}
	else if(strcmp(args[0], "add") == 0 || strcmp(args[0], "Add") == 0 || strcmp(args[0], "ADD") == 0){
		add(args);
	}
	else if(strcmp(args[1], "<") == 0){
		textOut(args);
	}
	else if(strcmp(args[2], ">") == 0){
		textIn(args);
	}
	else{ 
		counter = 0;
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

void list(char** args){
	int counter = 0;
	long total = 0;
	int test = 0;
	for(int i = 0; args[i] != NULL; i++){
		counter +=1;
	}
	counter -= 1;
	printf("The number of numbers you entered is: %d\n", counter);
	printf("The numbers you entered are: ");
	for(int g = 1; g < counter; g++){
		printf("%s, ", args[g]);
	}
	printf("%s\n", args[counter]);
	printf("\n");
}

void add(char** args){
	int total = 0;
	int sixteens = 1;
	int fromString = 0;
	int counter = 0;
	int argNum = 1;
	int bool = 0;

	for(int y = 1; args[y] != NULL; y++) {
		fromString = (int)strtol(args[y], (char **)NULL, 0);
		total += fromString;
		counter += 1;
	}
	for(int t = 1; t < counter; t++){
		printf("%s + ", args[t]);
	}
	printf("%s ", args[counter]);
	printf(" = %d\n", total);
	printf("The total added up is: %d\n", total);
	total = 0;
}

void textOut(char** args){
	int c;
	FILE *file;
	int counter = 0;
	int status = 0;
	printf("textOut is running\n");
	for(int y = 0; args[y] != NULL; y++) {
		counter += 1;
	}
	printf("The file name is: %s\n", args[counter -1]);
	file = fopen(args[counter-1], "r");
	if(file){
		printf("The text is: \n");
    	while ((c = getc(file)) != EOF){
        	printf("%c", c);
    		fclose(file);
		}
		printf("\n");
	}
	else{
		printf("Couldn't open file\n");
	}
}


void textIn(char** args){
	FILE *goingOut;
	int counter = 0;
	int status = 0;
	char* replArgs = args[0], args[1];
	printf("textIn is running\n");
	for(int y = 1; args[y] != NULL; y++) {
		counter += 1;
	}
	printf("The file name is %s\n", args[counter]);
	child_pid = fork();
   // goingOut = freopen(args[counter], "w+", stdout);
    //printf("running 3rd block of code");
	//child_pid = fork();
    if(child_pid == 0) {
    	goingOut = freopen(args[counter], "w+", stdout);
    	execvp(args[0], args[1]);
    	fclose(goingOut);
    	//printf("Exiting child program now");
    	_exit(0);
    }
    else if(child_pid > 0)  {
    /* Is the parent process */
    pid = getpid();
    //printf("parent id is now = %d\n", pid);
    wpid = wait(&status);
	}
	//fclose(goingOut);
}

	/*for(int i = counter -1; i > -1; i--){
		sixteens = 1;
		for(int g = i; g > 0; --g){
			sixteens *= 16;
		}
		fromString = (int)strtol(args[argNum], (char **)NULL, 10);
		printf("From string is: %d, sixteens is: %d\n", fromString, sixteens);
		total += fromString * sixteens;
		printf("The new total is: %d\n", total);
		argNum +=1;		
	}
	printf("The decimal number is: %d\n", total);
}*/


/*int checker(char* args){
	int argnum = 0;
	int total = 0;
	int argNumRepl = 0;
	int sixteens = 1;
	for(int r = 0; r < strlen(args); ++r){
		if(args[r] == 'a' || args[r] == 'A'){
			argNumRepl = 10;
		}
		sixteens = 1;
		for(int g = strlen(args); g > 0; --g){
			sixteens *= 16;
		}
		//fromString = (int)strtol(args[r], (char **)NULL, 10);
		printf("2nd block+From string is: %d, sixteens is: %d\n", argNumRepl, sixteens);
		total += argNumRepl * sixteens;
		printf("2nd block+The new total is: %d\n", total);
		//argNum +=1;
	}
	return total;
}*/



