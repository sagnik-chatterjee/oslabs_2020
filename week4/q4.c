#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

 

int main(int argv, char *argc[]) {

    char command[50] = "ls -il";
    printf("old path -> %s\n", argc[1]);
    symlink(argc[1], "link");
    system(command);
   printf("\n");
    unlink(argc[1]);
    system(command);


}