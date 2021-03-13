#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc , char **argv) {
	int f = open(argv[1], O_RDONLY, S_IRUSR);

	if (f == -1) {
		printf("Error in opening");
		exit(1);
	}

	char buffer[100];
	char c;
	//print the c file in console
	while ((r = read(f, &c, sizeof(char))) != 0) {
		write(stdout, &c, 1);
	}
	printf("Should other's be able to see ?(y/N)\n");
	char response;
	if (response == 'y' || response == 'Y') {
		int perm = S_IROTH | S_IRUSR;
		chmod(argv[1], perm);//changed the file perm
	}
	else {
		printf("Exiting\n");
	}
	return 0;

}
