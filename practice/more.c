#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc , char **argv) {

	char buffer[1024];
	//list the files gives as arguments and read one line at  a time
	//until key is hit


	int currentline = 1;
	while (currentline <= 20) {
		printf("Line %d is : %s", currentline, buffer);
		buffer[0] = '\n';
		currentline++;
	}
	char ch;
	while (read(0, &c, 1) == 1) {
		char keypress;
		read(0, &keypress, 1);

		printf("Line %d : %s\n", currentline, buffer);
		buffer[0] = '\0';
		currentline++;
	}



	return 0;
}