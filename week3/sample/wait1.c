#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int status;
    pid_t pid; 
    pid=fork();
    if(pid==-1){
        perror("Error creating child process\n");
        exit(1);
    }
    else if(pid==0){
        //this is for child process
        printf("I'm the child process\n");
        exit(0);
    }
    else {
        //parent process
        wait(&status);//wait for process(status) to change state 
        printf("I'm the parent!\n");
        printf("Child returned : %d\n",status);
    }
}
//wait(&status) will cause the parent to sleep until the child process 
//has finished execution 
//the exit status of the child is retunred to the parent 
