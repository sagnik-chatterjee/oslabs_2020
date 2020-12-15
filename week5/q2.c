/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q2 

*/
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>


int main(){
    int pfd[2];
    pid_t cpid;
    int buff;

    if(pipe(pfd)==-1){
        perror("[STATUS] Pipe failure\n");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if(cpid==-1){
        perror("[STATUS] Fork error\n");
        exit(EXIT_FAILURE);
    }
    else{
        printf("[STATUS] Pipe created\n");
    }
    if(cpid==0){
        //child process reads from pipe    
        close(pfd[1]);
        int y;
        read(pfd[0],&y,sizeof(int));
        close(pfd[0]);
        printf("[STATUS] Got %d from the parent\n",y);
        }
    else{
      //parent writes to child
            close(pfd[0]);
            printf("[STATUS] Enter a number\n");
            scanf("%d",&buff);
            write(pfd[1],&buff,sizeof(int));
            close(pfd[1]);
            wait(NULL);
            exit(EXIT_SUCCESS);
        }

}