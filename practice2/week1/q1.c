#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char **argv) {

	if (argc != 2) {
		printf("Usage :%s <inputfilename>", argv[0]);
		exit(1);
	}

	int fd = fopen(argv[1], O_RDONLY);

}