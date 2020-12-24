#include <stdio.h>
#include <unistd.h>


int main(int argc , char **argv) {
	execv("/bin/echo", argv);
	printf("DONE\n");
	return 0;
}