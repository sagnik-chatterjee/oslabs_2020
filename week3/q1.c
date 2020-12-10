/*
AUTHOR: SAGNIK CHATTERJEE
DATE : DEC9,2020
Usage : ./q1 

*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	//to block a parent process until the child completes using a 
	//wait system call 

	pid_t cpid ;
	if(fork()==0){
		exit(0);//terminating the child process
	}
	else {
		cpid= wait(NULL); //parent 
	}

	printf("Parent pid = %d\n",getpid()); 
	printf("Child  pid = %d\n",cpid);
	return 0;
}