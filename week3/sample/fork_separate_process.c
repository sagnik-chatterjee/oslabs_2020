#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid; 
    //fork another process 
    pid=fork();
    if(pid<0){
        //error occured 
        perror("Frok failed\n");
        exit(-1);
    }
    else if(pid==0){
        //child process 
        execlp("/bin/ls","ls",NULL);
    }
    else {
        //parent process 
        //parent will wait for the child to complete 
        wait(NULL);
        printf("Child Complete!\n");
        exit(0);
    }
}