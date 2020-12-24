#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc , char **argv) {
	int n;
	int fd[2];
	char buff[1024];
	char *data = "hello....this is sample data!\n";
	pipe(fd);
	write(fd[1], data, strlen(data));

	n = read(fd[0], buff, 1024);
	if (n >= 0) {
		buff[n] = 0;
		printf("Read %d bytes from the pipe : %d\t%s", n, buff);
	}
	else {
		printf("Error");
	}
	exit(0);
}