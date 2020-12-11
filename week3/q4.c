/*
AUTHOR : SAGNIK CHATTERJEE 
DATE : DEC 11,2020
USAGE : ./q4 & in one terminal to start the defunct process in the background 
and in anohter terminal check using  
ps aux | grep 'Z'


*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


//creating a zombie process 

int main(){
	pid_t pid;
	int status;

	pid=fork();
	if(pid<0){
		perror("[STATUS] Child process could not be created .\n");
		exit(-1);
	}
	//creating a child process 
	if(pid==0){
		printf("[STATUS] Child process created.\n");
		exit(0);
	}
	//since for this pid >0 so parent process 	 
	sleep(100);
	//parent sleeps for 70s hence cant call the wait process 
	//child already exited but its process id is still in the process table 
	
	//pid=wait(&status);
	if(WIFEXITED(status)){//to know the exit status of the child 
		fprintf(stderr,"[STATUS] [%d] Process %d exited with status %d.\n",
			getpid(),pid,WEXITSTATUS(status));
		//wexitstatus is fot obtaining the exit  status of the child process.
	}
	return 0;
}