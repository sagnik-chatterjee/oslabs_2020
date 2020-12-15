/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q1c

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
	int open_mode=O_RDONLY;
	char buffer[4];
	int bytes_read=0;
	
	memset(buffer,'\0',sizeof(buffer));
	printf("[STATUS] Opening FIFO O_RDONLY\n");
	pipe_fd=open(FIFO_NAME,open_mode);
	printf("[STATUS] Pipefd result :- %d \n",pipe_fd);
	
	if (pipe_fd!=-1)
	{
		for(int i=0;i<4;i++)
		{	//printing the 4 integers to the fifo queue
			res=read(pipe_fd,buffer,BUFFER_SIZE);
			if(res==-1){
				printf("[ERROR] Read error on pipe.\n");
				exit(1);
			}
			printf("%d\n",atoi(buffer));
			bytes_read+=res;
			buffer[0]='\n';//clear the buffer
			
		}
		(void)close(pipe_fd);//close the filedescriptor
	}
	else{
		fprintf(stderr,"[ERROR] File could not be opened.\n");
		exit(EXIT_FAILURE);
	}
		

	printf("[STATUS]  Finished and %d bytes read \n",bytes_read);
	exit(EXIT_SUCCESS);
}