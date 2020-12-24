#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc , char **argv) {
	int f = open(argv[1], O_RDONLY);
	char buffer[100];
	int q = open(argv[2], O_WRONLY);

	if (f == -1) {
		printf("Error in opening file for reading\n");
		exit(1);
	}
	if (q == -1) {
		printf("Error in opening file for writing \n");
		exit(1);
	}
	char temp;
	while ((r = read(f, &temp, 1)) != 0) {
		write(q, temp, sizeof(char));
	}
	close(f);
	close(q);
	return 0;
}