/*

AUTHOR :SAGNIK CHATTERJEE
DATE : 11 DEC,2020
USAGE : ./q2 file
where file is the input file 

*/
//to print the complete stat structure of the file 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc ,char **argv){

	struct stat file_stats;

	if(argc!=2){
		printf("[ERROR] Usage : %s <filename>",argv[0]);
		exit(1);
	}

	if((stat(argv[1],&file_stats))==-1){
		printf("[ERROR] fstat error \n");
		exit(1);
	}
	printf("[STATUS] File Reports :\n");
	printf(" Filename: %s\n", argv[1]);
	printf(" Device: %lud\n", file_stats.st_dev);
	printf(" Inode: %ld\n", file_stats.st_ino);
	printf(" Time of last access: %ld : %s", file_stats.st_atime, ctime(&file_stats.st_atime));
	printf(" Time of last modification: %ld : %s", file_stats.st_mtime, ctime(&file_stats.st_mtime));
	printf(" Time of last change: %ld : %s", file_stats.st_ctime, ctime(&file_stats.st_ctime));
	printf(" Protection: %o\n", file_stats.st_mode);
	printf(" Number of hard links: %lud\n", file_stats.st_nlink);
	printf(" User ID of owner: %d\n", file_stats.st_uid);
	printf(" Group ID of owner: %d\n", file_stats.st_gid);
	printf(" Device type (if inode device): %lud\n", file_stats.st_rdev);
	printf(" Total size, in bytes: %ld\n", file_stats.st_size);
	printf(" Blocksize for filesystem I/O: %ld\n", file_stats.st_blksize);
	printf(" Number of blocks allocated: %ld\n", file_stats.st_blocks);
	
	return 0;
}
