#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>


void listdir(char *pathname , int depth, char* argv) {

	int f = open(argv, O_WRONLY);
	DIR * dp;
	struct stat statbuf;
	struct dirent *entry;
	if ((dp = opendir(pathname)) == NULL) {
		printf("Error opeming the directory\n");
		exit(1);
	}
	chidr(pathname);
	char buffer[1024];
	buffer[0] = '\n';
	while ((entry = readdir(dp)) != 0) {
		lstat(entry->d_name, statbuf);

		if (S_ISDIR(statbuf.st_mode)) {
			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}
			strncat(buffer, entry->d_name);
			write(f, buffer, sizeof(buffer));
			listdir(pathname, depth + 4, argv);
		}

	}
	system("sort .");
	for (int i = 0; < 1024; i++) {

	}

	chdir("..");
	close()
}


int main(int argc , char **argv) {
	listdir(argv[1], 0);
	return 0;
}