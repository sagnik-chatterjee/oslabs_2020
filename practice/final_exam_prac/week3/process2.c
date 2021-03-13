#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

//zombie process
int main() {
	printf("SOme work is beign done \n");
	pid_t pid;

	pid = fork();

	if (pid < 0) {
		printf("Fork error \n");
		exit(1);
	}
	else if (pid == 0) {
		//chidld procees
		printf("CHild process  ");
		printf("Parent pid :- %d ", getppid());
		return 0;
	}
	else {
		//aprent process
		printf("CHild process ");
		printf("THis pid  : - %d", getpid());
		//printf("Parent pid :- %d ", getppid());
		sleep(4);
		//wait(NULL);
	}
}