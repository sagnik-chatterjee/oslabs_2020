#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc , char **argv) {
	if (argc != 4) {
		printf("[ERROR] Usage : %s <filename> <keyword>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int in = open(argv[1], O_RDONLY);
	int out = open(argv[3], O_WRONLY);
	if (in == -1) {
		printf("[ERROR] Opening error \n");
		exit(EXIT_FAILURE);
	}
	char ch;
	char buffer[512];

	buffer[0] = '\n'; ///clear the buffer

	int j = 0;
	char line[100];
	while (read(in, &ch, 1) != -1) {
		if (ch == '\n') {
			line[j] = ch;
			j++;
		}
		else {
			line[j] = '\0';
			if (strstr(line, argv[2]) != NULL) {
				printf("Pattern found is :%s", line);
			}
			memset(line, 0, siezof(line));
			j = 0;
		}
	}
	close(in);
	printf("Done");

	return 0;
}
