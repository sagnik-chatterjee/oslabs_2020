#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

void printIndodeDir(char *path, int depth) {
	DIR* p;
	struct dirent *entry;
	struct stat statbuf;

	if ((p = open(path)) == NULL) {
		fprint(stderr, "Cannot open dir %s", path);
		exit(EXIT_FAILURE);
	}
	chdir(path);
	while ((entry = readdir(path)) != NULL) {
		lstat(entry.d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) {
			//foudn directory ignore . and ..
			if (strcmp(entry.d_name.'.') == 0 || strcmp(entry.d_name, '..') == 0) {
				continue;
			}
			else {
				int inode = statbuf.st_ino;
				printf("%s -> %d ", entry.d_name, inode);
			}
			printIndodeDir(entry.d_name, depth + 4);
		}
	}
	else {
		int inode = statbuf.st_ino;
		printf("%s -> %d", entry.d_name, inode);
	}
	chdur('..');
	closedir(p);
}


int main(int argc , char **argv) {

}