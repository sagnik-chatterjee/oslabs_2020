/*
AUTHOR: SAGNIK CHATTERJEE
DATE : DEC9,2020
Usage : ./q1 

*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void ChildProcess(char *message){
	printf("Child process prints :- %s",message);
}

int main(){
	//to block a parent process until the child completes using a 
	//wait system call 
	
	pid_t cpid ;
	if(fork()==0){
		printf("Fork couldn't be done\n");
		exit(0);
	}
	else {
		cpid= wait(NULL); //parent 
	}

	printf("Parent pid = %d\n",getpid()); 
	printf("Child  pid = %d\n",cpid);
	


	return 0;
}