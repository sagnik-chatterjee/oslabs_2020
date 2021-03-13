#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		printf("Error");
		exit(1);
	}
	else if (pid == 0) {
		printf("Process id is : %d", getpid());
		return 0;
	}
	else {
		printf("Process id is %d", getpid());
		sleep(100);
	}
	return 0;
}