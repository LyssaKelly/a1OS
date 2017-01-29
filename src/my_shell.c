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
void date(char** args);
void background(char **args);
void foreground(char **args);


int main() {
	char **args; 
	
	while(1) {
		args = getln();
		decipher(args);
	}
	return 0;
}

void decipher(char** args){
	char* exit1 = "exit";
	//int status = 0;
	int counter = 0;
	int biggerThan = 0;
	int lessThan = 0;

	for(int i = 0; args[i] != NULL; i++){
			counter +=1;
	}
	for(int f = 0; f < counter; f++){
		if(strcmp(args[f], ">") == 0){
			biggerThan = 1;
		}
		else if(strcmp(args[f], "<") == 0){
			lessThan = 1;
		}
		else if(lessThan == 1 && biggerThan == 1){
			//they inputed some stupid shit

		}
	}
	if(strcmp(args[0], exit1) == 0){
		exit(0);
	}
	else if(strcmp(args[0], "arg") == 0 || strcmp(args[0], "Arg") == 0 || strcmp(args[0], "ARG") == 0){
		list(args);
	}
	else if(strcmp(args[0], "add") == 0 || strcmp(args[0], "Add") == 0 || strcmp(args[0], "ADD") == 0){
		add(args);
	}
	else if(biggerThan == 1){
		textIn(args);	
    }
	else if(lessThan == 1){
		textOut(args);
	}
	else if(strcmp(args[0], "date") == 0){
		date(args);
	}
	else if(strcmp(args[counter - 1], "&") == 0){
		background(args);
	}
	else{
		foreground(args);
	}
		/*if(counter == 1){
			char *repl1[] = {args[0], NULL };
			child_pid = fork();
			if(child_pid == 0){
				execvp(args[0], repl1);
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0){
        		// Is the parent process 
        		pid = getpid();
        		printf("parent id is now = %d\n", pid);
        		printf("\n");
        		wpid = wait(&status);
        		if(wpid != -1)  {
            		printf("Child exit\n");
            		if(status > 0)  {
                		printf("Accept\n");
            		} 
            		else{
                		printf("Complete parent process\n");
                		printf("\n");
            		}
				}
			}
		}
		if(counter != 1){
			char *repl3[] = {args[0], args[1], NULL };
			child_pid = fork();
			if(child_pid == 0){
    			execvp(args[0], repl3);
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0)  {
        		// Is the parent process 
        		pid = getpid();
        		printf("parent id is now = %d\n", pid);
        		printf("\n");
        		wpid = wait(&status);
        		if(wpid != -1)  {
           			printf("Child exit\n");
           		if(status > 0)  {
               		printf("Accept\n");
           		} 
           		else{
               		printf("Complete parent process\n");
               		printf("\n");
           		}
			}
		}
	}
}*/
    counter = 0;
    lessThan = 0;
    biggerThan = 0;
}


void background(char **args){
	int counter = 0;
	int status = 0;

	for(int d = 0; args[d] != NULL; d++){
		counter += 1;
	}
	if(counter == 2){
			char *repl[] = {args[0], NULL };
			child_pid = fork();
			if(child_pid == 0){
				execvp(args[0], repl);
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0){
        		// Is the parent process 
        		pid = getpid();
        		printf("parent id is now = %d\n", pid);
        		if(wpid != -1){
            		printf("Child exit\n");
            		if(status > 0)  {
               			printf("Accept\n");
            		} 
            		else{
               			printf("Complete parent process\n");
               			printf("\n");
            		}
				}
			}
		}
		if(counter != 1){
			char *repl2[] = {args[0], args[1], NULL };
			child_pid = fork();
			if(child_pid == 0){
    			execvp(args[0], repl2);
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0)  {
        		// Is the parent process 
        		pid = getpid();
        		printf("parent id is now = %d\n", pid);
        		printf("\n");
        		//wpid = wait(NULL);
        		if(wpid != -1)  {
            		printf("Child exit\n");
            		if(status > 0)  {
                		printf("Accept\n");
            		}	 
            		else{
                		printf("Complete parent process\n");
                		printf("\n");
            		}
				}
			}
		}
}


void foreground(char **args){
	int counter = 0;
	int status = 0;
	for(int d = 0; args[d] != NULL; d++){
		counter += 1;
	}
	if(counter == 1){
			char *repl1[] = {args[0], NULL };
			child_pid = fork();
			if(child_pid == 0){
				execvp(args[0], repl1);
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0){
        		// Is the parent process 
        		pid = getpid();
        		printf("parent id is now = %d\n", pid);
        		printf("\n");
        		wpid = wait(&status);
        		if(wpid != -1)  {
            		printf("Child exit\n");
            		if(status > 0)  {
                		printf("Accept\n");
            		} 
            		else{
                		printf("Complete parent process\n");
                		printf("\n");
            		}
				}
			}
		}
		if(counter != 1){
			char *repl3[] = {args[0], args[1], NULL };
			child_pid = fork();
			if(child_pid == 0){
    			execvp(args[0], repl3);
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0)  {
        		// Is the parent process 
        		pid = getpid();
        		printf("parent id is now = %d\n", pid);
        		printf("\n");
        		wpid = wait(&status);
        		if(wpid != -1)  {
           			printf("Child exit\n");
           		if(status > 0)  {
               		printf("Accept\n");
           		} 
           		else{
               		printf("Complete parent process\n");
               		printf("\n");
           		}
			}
		}
	}
}


void list(char** args){
	int counter = 0;
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
	int fromString = 0;
	int counter = 0;

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
	printf("\n");
	total = 0;
}

void textOut(char** args){
	int c;
	FILE *file;
	int counter = 0;
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
		printf("\n");
	}
}


void textIn(char** args){
	FILE *goingOut;
	int counter2 = 0;
	int status = 0;
	int y = 0;
	while(strcmp(args[y], ">") != 0){
		counter2 += 1;
		y++;
	}
	if(counter2 == 1){
		char *replText[] = {args[0], args[2], NULL};
		printf("The file name is %s\n", args[2]);
		child_pid = fork();
	//strcpy(args[2], NULL);
   // goingOut = freopen(args[counter], "w+", stdout);
    //printf("running 3rd block of code");
	//child_pid = fork();
    	if(child_pid == 0){
    		//printf("trying");
    		goingOut = freopen(args[2], "w+", stdout);
    		printf("trying");
    	//if(counter > 2){//if there is an argument
    		execvp(args[0], replText);
    		printf("trying");
    		_exit(0);
    		fclose(goingOut);
    		//_exit(0);
    	}
    	else if(child_pid > 0){
    		pid = getpid();
	    	wpid = wait(&status);
		}
	}
	if(counter2 == 2){
		char *replText2[] = {args[0], args[1], args[3], NULL};
		printf("The file name is %s\n", args[3]);
		child_pid = fork();
   // goingOut = freopen(args[counter], "w+", stdout);
    //printf("running 3rd block of code");
	//child_pid = fork();
    	if(child_pid == 0){
    		goingOut = freopen(args[3], "w+", stdout);
    	//if(counter > 2){//if there is an argument
    		execvp(args[0], replText2);
    		_exit(0);
    		fclose(goingOut);
    		//_exit(0);
    	}	
    	else if(child_pid > 0){
    		pid = getpid();
	    	wpid = wait(&status);
		}
	}
	if(counter2 == 3){
		char *replText2[] = {args[0], args[1], args[2], args[4], NULL};
		//printf("The file name is %s\n", args[3]);
		child_pid = fork();
   // goingOut = freopen(args[counter], "w+", stdout);
    //printf("running 3rd block of code");
	//child_pid = fork();
    	if(child_pid == 0){
    		goingOut = freopen(args[4], "w+", stdout);
    	//if(counter > 2){//if there is an argument
    		execvp(args[0], replText2);
    		_exit(0);
    		fclose(goingOut);
    		//_exit(0);
    	}	
    	else if(child_pid > 0){
    		pid = getpid();
	    	wpid = wait(&status);
		}
	}
	counter2 = 0;
	y = 0;
}	


void date(char** args){
	double totalMin = 0;
	double totalHr = 0.00;
	double totalDay = 0;
	double sixty = 60.00;
	double twFr = 24.00; 
	totalMin += strtol(args[1], (char **)NULL, 0);
	totalMin += strtol(args[2], (char **)NULL, 0)*60;
	totalMin += 1440*strtol(args[3], (char **)NULL, 0);

	totalHr = (float)totalMin/sixty;

	totalDay = (float)totalHr/twFr;

	printf("You have spent %.2lf minutes so far this month\n", totalMin);
	printf("You have spent %.2lf hours so far this month\n", totalHr);
	printf("You have spent %.2lf days so far this month\n", totalDay);
	printf("\n");
}












