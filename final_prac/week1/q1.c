#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc , char **argv) {
	int f = open(argv[1], RD_ONLY);
	if (f < 0) {
		printf("Error");
		exit(1);
	}

	char *word = argv[2];
	char temp, line[100];
	char j;
	while ((r = read(fd, &temp, sizeof(char))) != 0) {
		if (temp != '\n') {
			line[j] = temp;
			j++;
		}
		else {
			line[j] = '\0';
			if (strstr(line, argv[1]) != NULL)
				printf("Pattern is : %s\n", line);
			line[0] = '\n';
			j = 0;
		}
	}
	close(f);
	return 0;
}