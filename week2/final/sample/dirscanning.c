#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

//Usage :- ./dir 

void printdir(char *dir,int depth){
	//depth can be increased or decreased depending on how to increase it 
	//*dir is the refenrece to the directory we need to see 
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
			printf("%*s%s\n",depth,"",entry->d_name);
		}
	}
	chdir("..");
	closedir(dp);
}
int main(){
  //directory is . (curent directory) and depth is 0
	printdir(".",0);
	return 0;
}
