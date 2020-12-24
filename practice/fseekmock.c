#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc , char **argv) {
	char buffer[100];
	int n ;
	printf("Enter offset\n");
	scanf("%d", &n);

	int fd_open = open(argv[1], O_RDONLY);
	int fd_close = open(argv[2], O_WRONLY);
	char ch;
	int count  = 0;
	//reading the alteranate nth byte andwrite it
	while (read(fd_open, buffer, 1) == 1) {
		if (count < n) {
			//SEEK_CUR specifies that the offset provided is relative to the
			//current file position
			lseek(fd_close, n, SEEK_CUR);
			write(fd_open, buffer, 1);
			count = n;
		}
		else {
			count = (2 * n );
			lseek(fd_close, count, SEEK_CUR);
			write(fd_open, buffer, 1);
		}
	}
	close(fd_open);
	close(fd_close);
	printf("DONE\n");
	return 0;

}