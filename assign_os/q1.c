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

	}
	chdir("..");
	closedir(dp);
}




int main(int argc ,char **argv){
	if(argc!=2){
		fprintf(stderr,"Usage : %s <directoryname>",argv[0]);
	}
	//argv[1] is taken as the directory name to search 
	printdir(argv[1],0);
	//for sorting names by directory extension using -X flag for it 



}