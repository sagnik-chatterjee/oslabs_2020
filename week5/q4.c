/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q4 <inputfile> <outfile>
*/




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int fd[2];
	pid_t pid;
	char buf[1024];
	if(argc!=3 ){
		printf("[ERROR] Usage : %s <inputfile> <outputfile> \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if(pipe(fd)==-1){
		perror("[ERROR] Pipe Error\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if(pid==-1){
		perror("[ERROR] Fork Error\n");
		exit(EXIT_FAILURE);
	}
	else if(pid==0){
        //for child process write into binary file
		char ch;
		FILE *fw;
		fw = fopen(argv[2], "wb");
		if (fw == NULL){
			printf("[ERROR] Output binary file can't be opened\n");
            exit(EXIT_FAILURE);
        }
        printf("[STATUS] Reading in child. \n");
		close(fd[1]); //close unused write end
		while(read(fd[0], &buf, strlen(buf))>0){
			fputs(buf, fw);
		}
		close(fd[0]);
		printf("[STATUS] Child ended,closing .\n");
		fclose(fw);
		exit(EXIT_SUCCESS);
	}
	else{
        //parent process read from the bianry file 
		char ch;
		FILE *fw = fopen(argv[1], "rb");
		if (fw == NULL){
			printf("[ERROR] Input binary file can't be opened\n");
            exit(EXIT_FAILURE);
        }
        printf("[STATUS] Writing in parent...\n");
		close(fd[0]); //close unused read end
		while(fgets(buf, 1024, fw) !=NULL){
			write(fd[1], buf, strlen(buf));
		}
		close(fd[1]); //reader will see EOF
		wait(NULL); //wait for child to terminate
		printf("[STATUS] Parent ended,closing.\n");
		fclose(fw);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
