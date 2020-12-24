#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

//zombie process

int main() {
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		printf("Error");
		exit(1);
	}
	else if (pid == 0) {
		printf("The process id of the parent process %d", getppid());
		sleep(10);
	}
	else {
		printf("The process id of this process %d", getpid());
		return 0;
	}
}