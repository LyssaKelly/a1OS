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
	int counter = 0;
	int biggerThan = 0;
	int lessThan = 0;

	for(int i = 0; args[i] != NULL; i++){//finding the number of arguments
			counter +=1;
	}
	for(int f = 0; f < counter; f++){//finding a < or > in command
		if(strcmp(args[f], ">") == 0){
			biggerThan = 1;
		}
		else if(strcmp(args[f], "<") == 0){
			lessThan = 1;
		}
	}
	if(strcmp(args[0], exit1) == 0){//if exit command
		exit(0);
	}
	else if(strcmp(args[0], "arg") == 0 || strcmp(args[0], "Arg") == 0 || strcmp(args[0], "ARG") == 0){//if arg is command call arg function
		list(args);
	}
	else if(strcmp(args[0], "add") == 0 || strcmp(args[0], "Add") == 0 || strcmp(args[0], "ADD") == 0){//if add is comand call add function
		add(args);
	}
	else if(biggerThan == 1){//if using <
		textIn(args);	
    }
	else if(lessThan == 1){//if using >
		textOut(args);
	}
	else if(strcmp(args[0], "date") == 0){//if date function is called
		date(args);
	}
	else if(strcmp(args[counter - 1], "&") == 0){//if running background process
		background(args);
	}
	else{//if random command is entered
		foreground(args);
	}
    counter = 0;
    lessThan = 0;
    biggerThan = 0;
}


void background(char **args){
	int counter = 0;
	int status = 0;
	for(int d = 0; args[d] != NULL; d++){//finding the number of arguments
		counter += 1;
	}
	if(counter == 2){//if 1 arguments
		char *repl[] = {args[0], NULL };
		child_pid = fork();
		if(child_pid == 0){//child is not created properly
			if(execvp(args[0], repl) == -1){
				printf("command not found\n");
				_exit(0);
				return;
			}
			printf("Exiting program now");
    		_exit(0);
    	}
    	else if(child_pid > 0){//can continue
    		wpid = wait(NULL);
        	if(wpid != -1){//if child is exited
           		printf("Child exit\n");
           		if(status > 0)  {
           		} 
           		else{
              		printf("Complete parent process\n");
           			printf("\n");
            	}
			}
		}
	}
	if(counter > 2){//if more than 1 argument
		char *repl2[] = {args[0], args[1], NULL };
		child_pid = fork();
		if(child_pid == 0){
			if(execvp(args[0], repl2) == -1){
				printf("command not found\n");
				_exit(0);
				return;
			}
			printf("Exiting program now");
    		_exit(0);
    	}
    	else if(child_pid > 0)  { 
       		wpid = wait(NULL);
       		if(wpid != -1)  {
           		printf("Child exit\n");
           		if(status > 0)  {
           		}	 
           		else{
               		printf("Complete parent process\n");
               		printf("\n");
           		}
			}
		}
	}
}


void foreground(char **args){//same as background but contains the wait()
	int counter = 0;
	int status = 0;
	for(int d = 0; args[d] != NULL; d++){
		counter += 1;
	}
	if(counter == 1){
			char *repl1[] = {args[0], NULL };
			child_pid = fork();
			if(child_pid == 0){
				if(execvp(args[0], repl1) == -1){
					printf("command not found\n");
					_exit(0);
					return;
				}
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0){
        		pid = getpid();
        		printf("\n");
        		wpid = wait(&status);
        		if(wpid != -1)  {
				}
			}
		}
		if(counter != 1){
			char *repl3[] = {args[0], args[1], NULL };
			child_pid = fork();
			if(child_pid == 0){
				if(execvp(args[0], repl3) == -1){
					printf("command not found\n");
					_exit(0);
					return;
				}
				printf("Exiting program now");
    			_exit(0);
    		}
    		else if(child_pid > 0)  {
        		pid = getpid();
        		printf("\n");
        		wpid = wait(&status);
        		if(wpid != -1)  {
           		/*if(status > 0)  {
           		} 
           		else{
           		}*/
			}
		}
	}
}


void list(char** args){//the arg function
	int counter = 0;
	int start = 0;
	int end = 0;
	for(int i = 0; args[i] != NULL; i++){//counting number of arguments
		counter +=1;
		for(int e = 0; e < strlen(args[i]); e++){
			if(args[i][e] == '"' && start == 0){
				start = i;
			}
			else if(args[i][e] == '"' && start != 0){
				end = i;
			}
		}
	}
	if(start != 0 && end != 0){
		counter = counter - (end - start);
	}
	counter -= 1;
	printf("The number of arguments you entered is: %d\n", counter);
	printf("The arguments you entered are: ");
	for(int g = 1; g < counter + (end - start); g++){//prints out list
		printf("%s ", args[g]);
	}
	printf("%s\n", args[counter + (end - start)]);
	printf("\n");
}

void add(char** args){//adding function
	int total = 0;
	int fromString = 0;
	int counter = 0;
	for(int y = 1; args[y] != NULL; y++) {
		fromString = (int)strtol(args[y], (char **)NULL, 0);
		total += fromString;
		counter += 1;
		if(strtol(args[y], (char **)NULL, 0) == 0){
			printf("You entered in non-numericals; only numerical values will be added to total.\n");
			args[y] = "0";
		}
	}
	for(int t = 1; t < counter; t++){//prints out equation to screen
		printf("%s + ", args[t]);
	}
	printf("%s ", args[counter]);
	printf(" = %d\n", total);//prints out total
	printf("\n");
	total = 0;
	return;
}

void textOut(char** args){//prints out stuff from whatever command is entered
	int c;
	FILE *file;
	int counter = 0;
	for(int y = 0; args[y] != NULL; y++) {//counts number of arguments
		counter += 1;
	}
	file = fopen(args[counter-1], "r");//opens file
	if(file){
    	while ((c = getc(file)) != EOF){//prints out file
        	printf("%c", c);
    		fclose(file);
		}
		printf("\n");
	}
	else{//if file can't be opened
		printf("Couldn't open file\n");
		printf("\n");
	}
}


void textIn(char** args){//writes in command to specified file
	int counter2 = 0;
	int status = 0;
	int y = 0;
	while(strcmp(args[y], ">") != 0){//counts how many arguments are put in
		counter2 += 1;
		y++;
	}
	if(counter2 == 1){//if one argument
		char *replText[] = {args[0], args[2], NULL};
		child_pid = fork();
    	if(child_pid == 0){
    		FILE *goingOut = freopen(args[2], "w+", stdout);
    		if(execvp(args[0], replText) == -1){
					printf("command not found\n");
					fclose(goingOut);
					_exit(0);
					return;
				}
    		//fclose(goingOut);
    		_exit(0);
    		fclose(goingOut);

    	}
    	else if(child_pid > 0){
    		pid = getpid();
	    	wpid = wait(&status);
	    	if(wpid != -1)  {
           		if(status > 0)  {
               		printf("Accept\n");
           		} 
           		else{
           		}
           	}
		}
	}
	if(counter2 == 2){//if two arguments
		char *replText2[] = {args[0], args[1], args[3], NULL};
		child_pid = fork();
    	if(child_pid == 0){
    		FILE *goingOut = freopen(args[3], "w+", stdout);
    		if(execvp(args[0], replText2) == -1){
					printf("command not found\n");
					fclose(goingOut);
					_exit(0);
					return;
				}
    		fclose(goingOut);
    		_exit(0);
    	}	
    	else if(child_pid > 0){
    		pid = getpid();
	    	wpid = wait(&status);
		}
	}
	if(counter2 == 3){//if three arguments
		char *replText3[] = {args[0], args[1], args[2], args[4], NULL};
		child_pid = fork();
    	if(child_pid == 0){
    		FILE *goingOut = freopen(args[4], "w+", stdout);
    		if(execvp(args[0], replText3) == -1){
					printf("command not found\n");
					fclose(goingOut);
					_exit(0);
					return;
				}
       		fclose(goingOut);
    		_exit(0);
    	}	
    	else if(child_pid > 0){
    		pid = getpid();
	    	wpid = wait(&status);
		}
	}
	counter2 = 0;
	y = 0;
}	

/*This is the function I made, enter in the date command followed
  by a numerical value for number of minutes, then hours, then days
  and will output the total time in minutes, hours and days
  SAMPLE = "date 3 4 12"*/
void date(char** args){//
	double totalMin = 0;
	double totalHr = 0.00;
	double totalDay = 0;
	double sixty = 60.00;
	double twFr = 24.00;
	int counter = 0;
	for(int y = 0; args[y] != NULL; y++) {//counts number of arguments
		counter += 1;
	}
	if(counter < 4){//if not enough arguments are entered
		printf("Not enough arguments, exiting command\n");
		return;
	}
	else if(counter > 3){
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
}












