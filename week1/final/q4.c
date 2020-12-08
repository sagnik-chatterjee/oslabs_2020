#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//running:-  ./q4 input1q4.txt 
//output written in :- output1q4.txt 
int main(){
	
	//reading into file 
	FILE *fp  =fopen("input1q4.txt","r");
	if(fp==NULL){
		printf("Could not use file for reading.\n");
		return 0;
	}
	char buffer[1024];
	buffer[0]='\0';
	do {
		char c =fgetc(fp);
		//eof check
		strncat(buffer,&c,1);
		if(feof(fp))
			break;

	}while(1);
	buffer[1023]='\0';
	//close file pointer 
	fclose(fp);

	//open file pointer for writing 
	FILE * fp1 =fopen("output1q4.txt","w");
	if(fp1==NULL){
		printf("Could not use file for writing.\n");
		return 0;
	}

	for(int i=0;buffer[i]!='\0';i++){
		fputc(buffer[i],fp1);
	}
	buffer[1024]='\0';
	if(fclose(fp1)!=-1){
	printf("Wrote to the output file");
	}
	return 0;

}
