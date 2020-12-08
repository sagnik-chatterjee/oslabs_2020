#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Use : ./q2 filename 

void main (int argc, char **argv) {

	// must have filename
	if (argc != 2) {
		printf("Invalid syntax.\nFormat: ./q2_more filename \n");
		exit(0);
	}

	char filename[100];
	strcpy(filename, argv[1]);

	printf("File: %s\n", filename);

	int fd = open(filename, O_RDONLY);

	// check if file exists
	if (fd == -1) {
		printf("%s doesn't exist.\n", filename);
		exit(0);
	}

	char buffer[1000] = "";
	char c;
	int currentLine = 1;

	while (read(fd, &c, 1) == 1 && currentLine <= 20) {
		if (c != '\n') {
			strncat(buffer, &c, 1);
		} else {
			printf("Line %d: %s\n\n", currentLine, buffer);
			buffer[0] = '\0';
			currentLine++;
		}
	}

	while (read(fd, &c, 1) == 1) {
		if (c != '\n') {
			strncat(buffer, &c, 1);
		} else {
			// wait for key press before printing
			char keyPress;
			read(0, &keyPress, 1);

			printf("Line %d: %s\n", currentLine, buffer);
			buffer[0] = '\0';
			currentLine++;
		}
	}

	
	char keyPress;
	read(0, &keyPress, 1);
	printf("Line %d: %s\n", currentLine, buffer);

	close(fd);

	printf("\n\nEND OF FILE!\n\n");
}
