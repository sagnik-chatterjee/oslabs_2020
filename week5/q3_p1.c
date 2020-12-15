/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q3_p1

*/




#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<limits.h>
#define FILE_NAME "/tmp/my_fifo"

int main()
{
	int pipe_fd;
	int res;
	char buffer[1024];

	memset(buffer,'\0',sizeof(buffer));

	//first writing and then reading

	if(access(FILE_NAME,F_OK)==-1)
	{
		res = mkfifo(FILE_NAME,0777);
		if(res!=0)
		{
			fprintf(stderr,"[ERROR] Couldn't create fifo %s\n", FILE_NAME);
			exit(EXIT_FAILURE);
		}
	}

	printf("[STATUS] Opening FIFO_WRONLY");
	pipe_fd = open(FILE_NAME,O_WRONLY);
	printf("[INPUT] Input....\n");

	fgets(buffer,1024,stdin);
	if(write(pipe_fd,buffer,strlen(buffer)+1)==-1){
		fprintf(stderr,"[ERROR] Error in writing \n");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd);

	printf("[STATUS] Opening FIFO_RDONLY\n");
	pipe_fd = open(FILE_NAME,O_RDONLY);

	if(pipe_fd==-1){
		fprintf(stderr,"[ERROR] Error in pie filedescriptor\n");
		exit(EXIT_FAILURE);
	}

	memset(buffer,'\0',sizeof(buffer));
	read(pipe_fd,buffer,1024);
	close(pipe_fd);

	printf("[STATUS] Output: Reads %s\n",buffer);
	return 0;


}