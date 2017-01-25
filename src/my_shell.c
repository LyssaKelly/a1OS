#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern char **getln();

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
	printf("Here is the argument: %s\n", args[0]);
	if(strcmp(args[0], exit1) == 0){
		exit(0);
	}
	else if(strcmp(args[0], " ") == 0){
		printf("no command entered\n");
	}
	else{

	}
	return;
}

