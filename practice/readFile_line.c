#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc , char **argv) {
	if (argc != 3) {
		printf("[ERROR] Usage : %s <fileinput> <fileoutput>", argv[0]);
		exit(1);
	}

	int in = open(argv[1], O_RDONLY, S_IWUSR | S_IRUSR);
	int out = open(argv[2], O_CREAT | O_RDONLY, S_IRUSR | S_IXUSR);

	if (in == -1) {
		printf("[ERROR] Error opening inputfile %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (out == -1) {
		printf("[ERROR] Error opening outputfile %s", argv[2]);
		exit(EXIT_FAILURE);
	}

	char buffer[512];
	buffer[0] = '\n'; //flush the buffer
	//buffer is of size of  a line
	while (read(in, &ch, 1) == 1) {

	}



}