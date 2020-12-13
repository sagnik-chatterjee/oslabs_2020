#include <sys/types.h>
#include <sys/stat.h>

int mkfifo(char *filename, mode_t mode);

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv) {
	int res = mkfifo("/tmp/my_fifo", 0777);
	if (res == 0) {
		printf("FIFO created \n");
		exit(0);
	}
	exit(EXIT_SUCCESS);
	return 0;
}