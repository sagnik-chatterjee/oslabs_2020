/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 14,2020
USAGE : ./q1

To identofy the number of hard disks connected to the system

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char **argv) {
	printf("The number of hard disks connected to the system and their partitions \n");
	printf("---------");
	/*system("sudo fdisk -l");
	//Not a safe to show the hard drives connected ,for non sudo access use this
	//to list all block devices use
	system("lsblk");
	*/
	system("df -H");
	printf("----------");
	printf("end\n");
	return 0;
}