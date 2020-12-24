#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char **argv) {
	if (argc != 3) {
		printf("[ERROR] Usage : %s <input_file> <output_file>", argv[0]);
		exit(1);
	}

	int in = open(argv[1], O_RDONLY);
	int out = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	if (in == -1) {
		printf("[ERROR] Could not open file for reading\n");
		exit(EXIT_FAILURE);
	}
	if (out == -1) {
		printf("[ERROR] Could not create /open file for writing.\n");
		exit(EXIT_FAILURE);
	}
	char ch;
	while (read(in, &ch, sizeof(ch)) == 1) {
		//reading successfully until end of file
		write(out, &ch, sizeof(ch)); //write to the outfile
	}
	printf("[STATUS] Done.\n");
	return 0;

}