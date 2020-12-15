/*

AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE :

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

#define size 2 //because only allphabet sent

void nextalphabet(char *alphabet){
	char *next= (char*)calloc(2,sizeof(char));
	next[1]='\0';
	//handle corner cases of Z and z
	if(*alphabet=='Z'){
		next[0]='a';
	}
	else if(*alphabet=='z'){
		next[0]='A';
	}
	//for other characters handle 
	else {
		next[0]=*alphabet+1;
	}
	*alphabet=*next;
}

int main(){
	int segment_id = shmget(IPC_PRIVATE, size, S_IRUSR | S_IWUSR);
	if(segment_id<0){
		printf("[ERROR] shmget error. \n");
		exit(1);
	}

	char *shared_memory = (char *)shmat(segment_id, NULL, 0);
	*shared_memory = '\0';

	pid_t pid;
	int i;
	*shared_memory = 'A';//from the first english alphabet 

	for (i = 0; i < 52; ++i) {
		pid = fork();
			
		if(pid<0){
			printf("[ERROR] fork error \n");
			exit(1);
		}

		if (pid == 0) {//for child process get the next alphabet 
			while (*shared_memory == '\0');
			nextalphabet(shared_memory);
			exit(0);
		} else {
			//for parent process prints the next alphabet 
			//after the chracter has been incremented in the child process 
			printf("[STATUS] The next alphabet of %s is  :-  ", shared_memory);
			wait(NULL);
			printf("%s\n", shared_memory);
		}
	}
	//close the 
	shmdt(shared_memory);
}