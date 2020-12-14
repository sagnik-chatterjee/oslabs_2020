#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int fd[2]; int n;
	//filedescriptor reads into an array and writes to that
	char buffer[1024];
	char *data = "hello...this is sample data";
	pipe(fd);//piping it
	write(fd[1], data, strlen(data)); //write the cahnges to the first file descriptor

	if ((n = read(fd[0], buffer, 1024)) >= 0) {
		//successfully read from the file
		buffer[n] = 0; //end the buffer
		printf("[STATUS] Read %d bytes from the pipe : \"%s\"\n", n, buffer);
	}
	else {
		perror("[ERROR] Error reading the file");
		exit(0);
	}
	return 0;
}