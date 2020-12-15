/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q3_p2

*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

#define FILE_NAME "/tmp/my_fifo"


int main(){
	
	int pipe_fd;
	int res;
	char buffer[1024];


	//first reading and then writing

	if(access(FILE_NAME,F_OK)==-1)
	{
		res = mkfifo(FILE_NAME,0777);
		if(res!=0)
		{
			fprintf(stderr,"[ERROR] Couldn't create fifo %s\n", FILE_NAME);
			exit(EXIT_FAILURE);
		}
	}


	printf("[STATUS] Opening FIFO_RDONLY\n");
	pipe_fd = open(FILE_NAME,O_RDONLY);

	memset(buffer,'\0',sizeof(buffer));
	if(read(pipe_fd,buffer,1024)==-1){
		fprintf(stderr,"[ERROR] READ error \n");
		exit(EXIT_FAILURE);
	}
	close(pipe_fd);

	printf("[STATUS] Output: Reads %s\n",buffer);

	printf("[STATUS] Opens FIFO_WRONLY");
	pipe_fd = open(FILE_NAME,O_WRONLY);
	printf("[INFO]Input....\n");
	memset(buffer,'\0',sizeof(buffer));
	fgets(buffer,1024,stdin);
	if(write(pipe_fd,buffer,strlen(buffer)+1)==-1){
		fprintf(stderr,"[ERROR] Error writing\n");
		exit(EXIT_FAILURE);	
	}
	close(pipe_fd);

	return 0;
}