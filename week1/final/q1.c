#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>

void check_Pattern(char *argv[])
{
    int fd,r,j=0;
    char temp,line[100];
    if((fd=open(argv[2],O_RDONLY)) != -1)
    {
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp!='\n')
            {
                line[j]=temp;
                j++;

            }
            else
            {
            	line[j]='\0';
                if(strstr(line,argv[1])!=NULL)
                printf("Pattern is :%s\n",line);
                memset(line,0,sizeof(line));
                j=0;
            }

        }
    }
    else{
    	printf("Could not read the file with the file descriptor.\n");
    	exit(1);
    }   
}




int main(int argc,char **argv){
	
	struct stat stt;

	if(argc==3){
		if(stat(argv[2],&stt)==0){
			printf("Checking for matching patterns ... \n");
			check_Pattern(argv);
		}
		else{
			printf("Some problem occured , some error with parameter list.\n");
			exit(1);
		}
	}
			
}