//Usage : ./q2 dir 
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void listdir(const char *name ,int indent){
	DIR *dir;
	struct dirent *entry;
	if(!(dir=opendir(name)))
		return ;
	while((entry= readdir(dir))!=NULL){
		if(entry->d_type ==DT_DIR){
			char path[1024];
			if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
			continue;
			snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s[%s]\n", indent, "", entry->d_name);
            listdir(path, indent + 2);
		}
		else {
			printf("%*s- %s\n", indent, "", entry->d_name);
		}
	}
	closedir(dir);

}

int main(int argc ,char **argv){
  //here depth level taken to be 0 and the directory is . (current directory)
 	listdir(argv[1],0);
	return 0;
}