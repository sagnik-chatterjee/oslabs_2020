#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
//ambiguous

int main() {

	int fd1 ;
	char *myfifo = "/tmp/myfifo";

	//creating named file(FIFO)
	mkfifo(myfifo, 0666); //form:- mkfifo(<pathname>,<permission>)

	char str1[80], str2[80];

	while (true) {
		//first open in read only and read
		fd1 = open(myfifo, O_RDONLY);
		read(fd1, str1, 80);

		//print the read string and close
		printf("[STATUS] This fifo prints:- %s\n", str1);
		close(fd1);

		//now opening the fifo in write mode and write string taken from user
		fd1 = open(myfifo, O_WRONLY);
		fgets(str2,)

	}

}