/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q1p

*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main()
{
	int pipe_fd;
	int res;
	int open_mode=O_WRONLY;
	int bytes_sent=0;
	char buffer[100];
	
	if (access(FIFO_NAME,F_OK)==-1){
		res=mkfifo(FIFO_NAME,0777);
	
		if (res!=0)
		{
			fprintf(stderr,"[ERROR] Couldn't create fifo %s\n",FIFO_NAME );
			exit(EXIT_FAILURE);
		}
	}
	printf("[STATUS] Opening FIFO O_WRONLY\n");
	pipe_fd=open(FIFO_NAME,open_mode);
	printf("[STATUS] Pipe_fd result %d \n",pipe_fd);
	if (pipe_fd!=-1)
	{
		for (int i=0;i<4;i++)
		{	//writing the 4 integers in the fifo queue
			printf(" Enter the integer \n");
			scanf("%s",buffer);
			res=write(pipe_fd,buffer,100);
			//buffer[0]='\n';//clear the pipe
			if (res==-1)
			{
				fprintf(stderr,"[ERROR] Write error on pipe\n");
				exit(EXIT_FAILURE);
			}
			bytes_sent+=res;
		}
		(void)close(pipe_fd);//close the file descriptor
	}
	else
	{
		printf("[ERROR] Couldn't read from the pipe file descriptor.\n");
		exit(EXIT_FAILURE);
	}
	printf("[STATUS] DONE \n");
	exit(EXIT_SUCCESS);
}