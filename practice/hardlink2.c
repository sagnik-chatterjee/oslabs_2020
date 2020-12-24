#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>

int main(int argc , char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage : %s <filename>", argv[0]);
		exit(1);
	}


	//if using fd by open use linkat see man2 link
	struct stat statbuffer;
	int fd = open(argv[1], O_RDONLY);

	int ret = stat(fd, &statbuffer);

	if (ret) {
		perror("SOme error with stat");
		exit(1);
	}
	printf("Initila number of hard links : %d", statbuffer.st_nlink);

	int ret1 = link(fd, "file1.txt");
	if (ret1) {
		perror("SOme error");
		exit(1);
	}
	printf("Hard link created ");
	int ret3 = stat(fd, &statbuf);
	printf("Press enter to unlink");
	getchar();
	getchar();
	int ret4 = unlink("file1.txt");
	printf("\nUnlinking successful\n");
	int ret5 = stat(fb, &sb);
	printf("No. of links after unlinking of hard link : %ld\n", sb.st_nlink );
	return 0;


}