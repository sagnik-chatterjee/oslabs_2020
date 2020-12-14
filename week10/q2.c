/*
AUTHOR :SAGNIK CHATTERJEE
DATE: DEC 14,2020
Usage : ./q2
*/
//some problem is happening to open the file for reading .

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SECTOR_SIZE 512


int main(int argc , char **argv) {
	int offset = 0;
	int length = 5 ;
	int rc = -1;

	if (argc < 2) {
		printf("[ERROR] Usage : %s <mount_point_of_pen_drive> ", argv[0]);
		exit(1);
	}

	char *sector = aligned_alloc(SECTOR_SIZE, SECTOR_SIZE);

	memset(sector, 0, SECTOR_SIZE);

	int fd = open(argv[1], O_RDWR | O_DIRECTORY);

	if (fd == -1) {
		printf("[ERROR] Problem opening the file for reading.\n");
		exit(1);
	}
	lseek(fd, offset, SEEK_SET);
	for (int i = 0; i < length; i++) {
		rc = read(fd, sector, SECTOR_SIZE);
		if (rc < 0) {
			printf("[ERROR] Sector read error at offset = %d + %d\n %s",
			       offset, i, strerror(errno));
		}
		printf("[STATUS] Sector : %d\n", i);
		for (int j = 0; j < SECTOR_SIZE; j++) {
			printf("[STATUS] %x", sector[i]);
			if ((j + i) % 16 == 0) {
				printf("\n");
			}
		}
	}
	free(sector);
	close(fd);
	printf("----EXIT----");
	return 0;
}