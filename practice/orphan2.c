#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		exit(1);
	}
	else if (pid == 0) {
		//child process ,make an orphan process
		printf("Old parent process id : %d", getppid());
		sleep(2);
		printf("New parent process id : %d", getppid());
		execlp("ps", "-aux", "|", "grep", getpid(), (char*)0);
	}
	else {
		sleep(1);
	}
}

