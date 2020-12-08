//systemcalls for open anc close 

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void OpenFile(){
	//open a file called sample1.txt in the current directory 
	//if the file is not present it is created 
	
	int fd = open("sample1.txt",O_RDONLY| O_CREAT);

	if(fd==-1){
		printf("Some error in creating the file descriptor.\n");
		exit(1);		
	} 
	printf("sample1.txt is successfully opened or created.\n");

}

void CloseFile(){
	int fd= open("sample1.txt",O_RDONLY);
	if(fd1==-1){
		printf("Some error with the file descriptor\n");
		exit(1);
	}
	printf("Opened the file sampl1.txt with the file descriptor.");

	//close the file 
	if(close(fd)==-1){
		printf("Some error occured with the close systemcall\n");
		exit(1);
	}
	printf("Closed the file sample1.txt\n");
}


int main(){
	OpenFile();
	CloseFile();
	return 0;
}
