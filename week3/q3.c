//program to create a child process 
//display the process id's of the porcess,parent and child 
//in botht the parent and child process 

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t pid;

	fork();
	//printing the process id of the processes 
	printf("Parent pid = %d\n",getpid());
	printf("Child pid = %d\n",pid);
	return 0;
}