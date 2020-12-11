/*
AUTHOR :SAGNIK CHATTERJEE 
DATE : DEC 11 ,2020
USAGE : ./q2
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int status;
	pid_t pid; 
	pid=fork();
	if(pid<0){
		printf("[ERROR] Child could not be created!\n ");
		exit(-1);
	}	

	else if(pid==0){
		printf("[STATUS] Executing the command ...\n");
		execlp("./q1","q1",NULL);
	}
	else{
		wait(NULL);
		printf("[STATUS] Child completed its execution .\n");
		exit(0);
	}
}