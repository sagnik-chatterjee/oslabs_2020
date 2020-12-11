/*
AUTHOR : SAGNIK CHATTERJEE 
DATE   : DEC 11,2020
USAGE  : ./q3

*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid;

	pid=fork();
	if(pid==-1){
		printf("[ERROR] Child could not be created!\n");
		exit(-1);
	}
	else if(pid==0){
		//process ids of both parent and child when pid==0 i.e child process
		printf("[STATUS] Inside the child process ...\n");
		printf("Process id of the child process :- %d\n",getpid());
		printf("Process id of the parent process :- %d\n",getppid());

	}
	else {
		wait(NULL);//wait for child process to finish 
		//process ids of both parent and child when pid >0 i.e parent process 
		printf("[STATUS] Inside the parent process ...\n");
		printf("Process id of the child process :- %d\n",getpid());
		printf("Process id of the parent process :- %d\n",getppid());
	
	}	
	return 0;
}