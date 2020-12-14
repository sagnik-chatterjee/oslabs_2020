//working of pipe in  a single process after the fork system call

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main(int argc , char **argv) {
	int pfd[2];
	pid_t cpid;
	char buffer[1204];
	if (argc < 2) {
		printf("[ERROR] Usage : %s | <filename> ", argv[0]);
		exit(1);
	}
	cpid = fork();
	if (cpid == -1) {
		printf("[ERROR] Fork Error\n");
		exit(1);
	}
	if (cpid == 0) {
		//child readsd from pipe
		close(pfd[1]); //close unused write end
		while (read(pfd[0], &buffer, 1) > 0) {
			write(argv[2], &buffer, 1); //where argv[1] is the outpur file name
		}
		write(argv[2], "\n", 1);
		close(pfd[0]);
		exit(0);//successful exit
	}
	else {
		//parent writes argv[1] to pipe
		close(pfd[0]);//close unused read end
		write(pfd[1], argv[2], strlen(argv[1])); //writeing to the output file
		close(pfd[1]);
		wait(NULL);
		exit(0);//successful exit
	}
}