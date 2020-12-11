/*
AUTHOR: SAGNIK CHATTERJEE
DATE : DEC 11,2020
Usage : ./q1 

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int status;
	pid_t pid; 
	pid=fork();

	//printf("The process id of the parent process is %d",getpid());
	//printf("The process id of the child process is %d",pid);

	if(pid==-1){
		printf("[ERROR] Couldn't create child process !!\n");
	}
	else if(pid==0){
		printf("[STATUS] This is the child process,with process id :- %d\n,and the process id of its parent process is :- %d\n",getpid(),getppid());
		exit(0);
	}	
	else {
		wait(&status);
		printf("[STATUS] This is the parent process ,with process id :- %d\n",getpid());
		printf("[STATUS] Child process returns status :- %d\n",status);
	}
return 0;
}