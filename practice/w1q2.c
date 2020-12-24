//using lseek to copy differnet parts of the code
//first ,middle and last of the file to others


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc , char **argv) {
	if (argc != 2) {
		printf("[ERROR] Usage : %s <filename>", argv[0]);
		exit(EXIT_FAILURE);
	}

	int n ;
	printf("Enter n :\n");
	scanf("%d", &n);
	int in = open(argv[1], O_RDONLY);
	int out = open("out.file", O_WRONLY);
	char ch;
	int count = 0;
	while (read(out, &ch, 1)) {
		if (count < n) {
			lseek(out, n, SEEK_CUR);
			write(in, &ch, 1);
			count += n;
		}
		else {
			count = 2 * n;
			lseek(out, count, SEEK_CUR);
			write(in, &ch, 1);
		}
	}
	close(in);
	close(out);
	printf("DONE\n");
	return 0;

}