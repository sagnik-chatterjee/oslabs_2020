/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 14,2020
USAGE : ./q2

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define msgsize 50

int main() {
	int fd[2]; //the arg for the pipe

	pid_t pid;
	char *mess1 = "hello ,this is message1";
	char *mess2 = "hello this is message2";
	char *mess3 = "hello this is message3";
	int nbytes;
	char inbuf[msgsize];

	if (pipe(fd) < 0) {
		printf("[ERROR] Pipe could not be created.\n");
		exit(1);
	}
	pid = fork();
	//creating from a pipe
	if (pid > 0) {
		//parent process
		//write from a pipe
		write(fd[1], mess1, msgsize);
		write(fd[2], mess2, msgsize);
		write(fd[3], mess3, msgsize);

	}
	else {
		//for child process
		//close(fd[1]);
		while ((nbytes = read(fd[0], inbuf, msgsize)) > 0)
			printf("% s\n", inbuf);
		if (nbytes != 0)
			exit(2);
		printf("[STATUS] Finished reading\n");
	}
}

