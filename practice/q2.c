#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main() {
	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stderr, "fork error");
		exit(1);
	}
	else if (pid == 0) {
		//child process
		printf("The process id of this process %d", getpid());
		printf("The process id of the parent process %d", getppid());
	}
	else {
		printf("The process id of this process %d", getpid());
		printf("The process id of the child process %d", pid);
		wait(NULL);
	}
}
