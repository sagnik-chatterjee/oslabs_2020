#include <stdio.h>
#include <dirent.h>

int main(){
	struct dirent *dir ;//pointer for directory entry 

	DIR *d = opendir("."); //returns a pointer of DIR type 

 if (d) {
    	while ((dir = readdir(d)) != NULL) {
      	printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
	return 0;
}