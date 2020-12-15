/*
AUTHOR :SAGNIK CHATTERJEE
DATE : DEC 15 ,2020
USAGE :

*/

//the writer part -->the parent process


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
	//ftok to make a unique key
	key_t key = ftok("shmfile", 65);

	//shmgte returns an identifier in shmid
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

	if (shmpid == -1) {
		printf("[ERROR] shmget failed.\n");
		exit(1);
	}
	//shmat to attach to the shared memory
	char *str = (char*) shmat(shmoid, (void*)0, 0);

	printf("[STATUS] Enter the character to send : ");
	fgets(message.mesg_text, max, stdin);


}