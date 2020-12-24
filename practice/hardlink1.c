
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	struct stat sb;
	int ret, ret1, ret2, ret3, ret4, ret5;
	//char date[256];
	if (argc < 2) {
		fprintf(stderr, "\nusage: %s\n", argv[0]);
		return 1;
	}
	ret = stat(argv[1], &sb);
	if (ret) {
		perror("stat");
		return 1;
	}
	printf("\nInitial Number of Hard Links: %ld\n", sb.st_nlink);
	ret1 = link(argv[1], "sam.txt");
	if (ret1) {
		perror("link");
		return 1;
	}
	printf("\nHard Link created\n");
	ret3 = stat(argv[1], &sb);
	if (ret3) {
		perror("stat");
		return 1;
	}
	printf("\nNumber of Hard Links after creation of new link: %ld\n", sb.st_nlink);
	printf("\nUnlinking..\n");
	printf("\nPress enter to unlink\n");
	getchar();
	getchar();
	ret4 = unlink("sam.txt");
	if (ret4) {
		perror("unlink");
		return 1;
	}
	printf("\nUnlinking successful\n");
	ret5 = stat("s.txt", &sb);
	printf("No. of links after unlinking of hard link : %ld\n", sb.st_nlink );
	return 0;
}