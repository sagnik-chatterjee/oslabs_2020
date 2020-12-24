#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc , char **argv) {
	int fd[2];
	pid_t cpid;
	char buffer[1024];
	if (argc != 2) {
		printf("Error \n");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1) {
		printf("Fork failed\n");
		exit(EXIT_FAILURE);
	}
	//child process
	else if (cpid == 0) {
		close(fd[1]);
		while (read(fd[0], buffer, sizeof(buffer)) != 0)
			write(stdout, buffer, sizeof(buffer));
		write(stdout, "\n", 1);
		close(fd[0]);
		exit(EXIT_SUCCESS);
	}
	else {
		//do something in the parent process

		close(fd[0]);
		write(fd[1], buffer, sizeof(buffer));
		close(fd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
}
