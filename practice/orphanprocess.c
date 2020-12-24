#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
	pid_t pid = fork();
	int status;
	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {
		//child process
		printf("In the child\n");
		sleep(5);
		printf("The process id of this process is %d\n", getpid());
		printf("The process id of the parent process is %d\n", getppid());
		execlp("ps", "aux", (char*)0);
	}
	else {
		//aprent process
		printf("In the parent\n");
		printf("The process id of this process is %d\n", getpid());
		wait(&status);
		int es = WEXITSTATUS(status);
		printf("The exit code of the child returned %d\n", es);
	}
}