#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {

	printf("This is the parent process with pid :%d\n ", getpid());
	pid_t pid = fork();

	printf("This is the  process with pid : %d\n", getpid());
	printf('This ')

	if (pid == 0) {
		printf("some work done by child process with id :", getpid());
	}
	wait(NULL);
	else {

	}
}