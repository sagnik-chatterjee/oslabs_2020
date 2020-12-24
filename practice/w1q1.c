//program to show user all his C SOURCE CODE AND THEN PROMPT
//interaacvely as to whether others should be given read permisson
//if yes then that permission should be given

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc , char **argv) {
	if (argc != 2) {
		printf("[ERROR] Usage : %s <filename>", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY, S_IRUSR | S_IXUSR);

	if (fd == -1) {
		printf("[ERROR] Failed to open the file.\n ");
		exit(EXIT_FAILURE);
	}


	char ch;
	while (read(fd, &ch, 1) == 1) {
		//print the code on scrren
		printf("%c", ch);
		//can be improved by lssek and fseek to check for newlines and stuff
	}
	char choice;
	printf("Do you want to allow others to give read and execute permissions ?(y|N)\n");
	scanf("%c", &choice);

	if (choice == 'y' || choice == 'Y') {
		//yes give premission
		printf("GIving read permission \n");
		execl("chmod g+r ", argv[1], NULL);
		printf("Giving execute permission \n");
		execl("chmod g+x ", argv[1], NULL);
		exit(EXIT_SUCCESS);
	}
	else {
		//change permission
		printf("Not giving permissions");
		exit(EXIT_SUCCESS);
	}
	return 0;
}