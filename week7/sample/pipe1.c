#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int n ;
	int fd[2];
	char buf[1024];
	char *data = "Sample data .... hello !!!\n";
	pipe(fd);
	write(fd[1], data, strlen(data));

	if ((n = read(fd[0], buf, 1024)) >= 0) {
		buf[n] = 0; //terminate the string
		printf("Read %d bytes from the pipe: \"%s\"\n", n, buf);
	}
	else {
		perror("Read");
		exit(0);
	}
	return 0;
}