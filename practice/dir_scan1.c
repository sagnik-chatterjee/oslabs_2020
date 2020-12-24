#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

void printDepth(char *dir, int depth) {
	DIR *dp;
	struct dirent* entry;
	struct stat statbuf;

	if ((dp = oepn(dir)) == NULL) {
		fprintf(stderr, "Cannot open directory %s\n", dir);
		return ;
	}
	chdir(dir);//changing directory to dir

	while ((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name, &statbuf); //get file status for files in direcotry
		if (S_ISDIR(statbuf.st_mode)) {
			//found directory but ignoreing . and ..
			if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
				continue;
			}
			printf("%d :- %s | %s | %s | %s\n", depth, entry->d_name, statbuf->st_uid, statbuf->st_gid);
			//st_uid and st_gid gives userid and groupid info
			//recusre at new depth
			printDepth(entry->d_name, depth + 4);
		}
		else {
			printf("%d :- %s | %s | %s | %s\n", depth, entry->d_name, statbuf->st_uid, statbuf->st_gid);


		}

	}
	chdir("..");
	closedir(dp);

	/*
		for permission individually can alos be checked as
		struct stat sbuf;

		if((dir=open(fd))!=NULL){
		if(sbuf.st_size==0){
			printf("d");//foir empty dir
		}
		if(sbuf.st_mode  & S_IREAD){
	printf("r");
		}
		if(sbuf.st_mode & S_IEXEC){
	printf("x");
		}
		if(sbuf.st_mode &S_IWRITE){
	printf("w");
		}
		}

	*/

}
int main(int argc , char **argv) {
	//pass the dirname and the depth level as param to check them
}