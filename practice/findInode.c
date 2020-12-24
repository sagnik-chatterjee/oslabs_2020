#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

int main(int argc , char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage : %s <directoryname>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int fd = open(argv[1], O_RDONLY);
	struct stat statbuf;

	int ret = fstat(fd, &statbuf);
	if (ret < 0) {
		printf("ERROR");
		exit(1);
	}

	int inode  = statbuf.st_ino;
	printf("The file name is :%s\n", argv[1]);
	printf("Inode Number : %d\n", inode);
	return 0;


}