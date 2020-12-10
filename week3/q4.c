//creating a zombie process 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status;

	if((pid=fork())<0){
		perror("Fork error\n");
		exit(0);
	}
	//creating a child process 
	if(pid==0){
		exit(0);
	}
	//parent --> gives tie to observe the zombie using ps(1)

	sleep(100);

	//after that ,parent wait(2)s its child's exit status 
	//and prints a relevant message 

	pid=wait(&status);
	if(WIFEXITED(status)){
		fprintf(stderr,"\n\t[%d]\tProcess %d exited with status %d.\n",
			(int)getpid(),pid,WEXITSTATUS(status));
	return 0;
}}