#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void printDir(char *dir ) {
	DIR *p;
	struct dirent dirstat;
	struct stat statbuf;

	if ((p = opendir(dir)) == NULL) {
		fprintf(stderr, "Error in opening");
		exit(1);
	}
	chdir(dir);
	if ((dirstat = readdir(p)) != NULL) {
		lstat(dirstat.d_name, &statbuf);
		if (S_ISDIR(statbuf.st_mode)) {
			printf("%d -> %i ", statbuf.st_uid, statbuf.st_mode);
		}
	}
	chdir("..");
	closedir(p);

}


int main(int argc , char **argv) {
	//directory name if argv[1]
	if (argc != 3) {
		fprintf(stderr, "Usage : %s <directory> <filename>", argv[1]);
		exit(1);
	}

	printDir(argv[1]);

	//file in argv[2]
	int fd = open(argv[2], O_RDONLY);

	if (fd == -1) {
		fprintf(stderr, "File READ error");
		exit(1);
	}
	printf("Change the permission the file ?(y|N)");
	char ch;
	scanf("%c", &ch);
	if (ch == 'y' ) {
		int p = fchmod(fd, S_IROTH | S_IWOTH);

		if (p == -1) {
			fpritnf(stderr, "chmod fail");
			exit(1);
		}
		printf("Succesfully changes the permisison of the file \n");
	}
	else {
		printf("Not changesd permission");
	}
	close(fd);
	return 0;
}

