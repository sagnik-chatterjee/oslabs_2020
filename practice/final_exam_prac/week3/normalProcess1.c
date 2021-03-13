#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("Error forking!\n");
		exit(1);
	}
	else if (pid == 0) {
		printf("This is the child process ,wiht the parent id :- %d", getppid());
		printf("And the process id this process is %d", getpid());
	}

	else {
		printf("The process id of this process %d", getpid());
		printf("The process id of the child is %d", pid);
		wait(NULL);
	}
	return 0;
}