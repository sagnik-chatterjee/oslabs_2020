#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	pid_t pid = fork();
	if (pid == -1) {
		printf("[ERROR] Fork error \n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		//child process
		sleep(2);
		printf("In the child process\n");
		printf("The pid of the parent process is %d\n", getppid());
		printf("The pid of this process is %d\n", getpid());
		//sleep(100);//making it sleep so that parent exits faster
	}
	else {
		//parent process
		printf("In the parent process\n");
		printf("The pid of the parent process is %d\n", getppid());
		printf("The pid of this process%d\n", getpid());
		printf("The pid of the child process is %d\n", pid);
	}
	return 0;
}
