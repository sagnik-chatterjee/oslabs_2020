/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q4 inputfilename outputfilename

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>


int main(int argc , char **argv) {
	char  buffer[1024];
	FILE* ptr;
	if (argc < 3) {
		printf("[ERROR] Usage : %s <filename_to_read> <filename_to_write>", argv[0]);
		exit(1);
	}
	ptr = fopen(argv[1], "rb");

	if (ptr < 0) {
		printf("[ERROR] Could not open files for reading.\n");
		exit(1);
	}
	//read the data to the buffer

	if (fread(buffer, sizeof(buffer), 1, ptr) < 0) {
		printf("[ERROR] Some reading error.\n");
		exit(1);
	}
	printf("Succesfully read from the file.\n");
	//print a series of bytes to screen
	/*for (int i = 0; i < 1024; i++) {
		printf("%x", buffer[i]);
	}
	*/

	FILE* write_ptr ;

	write_ptr = fopen(argv[2], "wb");
	if (write_ptr < 0) {
		printf("[ERROR] Could not open file for writing.\n");
		exit(1);
	}

	if (fwrite(buffer, sizeof(buffer), 1, write_ptr) < 0) {
		printf("[ERROR] Some writing error \n");
		exit(1);
	}
	printf("Succesfully wrote the result to file %s\n", argv[2]);
	printf("\n----DONE------\n");

	fclose(write_ptr);
	fclose(ptr);
	return 0;
}