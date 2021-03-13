//recurisvely print the directory
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void listdir(char *pathname , int depth) {

	struct stat statbuf;
	struct dirent* entry;

	DIR dp;
	if ((dp = opendir(pathname)) == NULL) {
		printf("COuld not open the file for reading.\n");
		exit(1);
	}
	chdir(pathname);

	while ((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) {
			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}
			//else print them
			printf("%*s %s \n", depth, entry->d_name);
			listdir(entry->d_name, depth + 4);
		}
		else {
			//print file name
			printf("[%*s] - [%s]", depth, entry->d_name);
		}
	}
	chdir("..");
	closedir(dp);
}
int main(int argc , char **argv) {

	listdir(argv[1], 0); //depth is 4 that is . for that dir
	return 0;
}
