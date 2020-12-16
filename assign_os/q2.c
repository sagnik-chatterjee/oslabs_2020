#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void printdir(char *dir,int depth){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp= opendir(dir)) == NULL){
		fprintf(stderr,"cannot open directory: %s\n",dir);
	return ;
	}
	chdir(dir);
	while((entry=readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			//found directory but ignore and ...
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0){
				continue;
			}
			printf("%*s%s/\n",depth,"",entry->d_name);
			//recurse at new indent level
			printdir(entry->d_name,depth+4);
		}
		else {
			printf("%*s%s ,Inode Number :- %ld\n",depth,"",entry->d_name,statbuf.st_ino);
	/*		
	printf(" Filename: %s\n", argv[1]);
	printf(" Device: %lld\n", statbuf.st_dev);
	printf(" Inode: %ld\n", statbuf.st_ino);
	printf(" Protection: %o\n", statbuf.st_mode);
	printf(" Number of hard links: %d\n", statbuf.st_nlink);
	printf(" User ID of owner: %d\n", statbuf.st_uid);
	printf(" Group ID of owner: %d\n", statbuf.st_gid);
	printf(" Device type (if inode device): %lld\n", statbuf.st_rdev);
		printf(" Total size, in bytes: %ld\n", statbuf.st_size);
		printf(" Blocksize for filesystem I/O: %ld\n", statbuf.st_blksize);
		printf(" Number of blocks allocated: %ld\n", statbuf.st_blocks);
	*/

		}
	}
	chdir("..");
	closedir(dp);
}

int main(int argc ,char **argv){


	printdir(argv[1],0);
	
	return 0;
	
}	