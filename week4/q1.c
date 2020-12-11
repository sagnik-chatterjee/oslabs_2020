/*

AUTHOR :SAGNIK CHATTERJEE
DATE : 11 DEC,2020
USAGE : ./q1 q1file
where q1file is the input file 

*/

//to print the inode number of the file 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc ,char **argv){

	if(argc!=2){
		printf("[ERROR] Usage : %s <file> \n",argv[0]);
		exit(1);
	}
	char buffer[100];

	bzero(buffer,sizeof(buffer));
	strcat(buffer,"ls ");
	strcat(buffer,"-i ");
	strcat(buffer,argv[1]);
	system(buffer);

	return 0;

}