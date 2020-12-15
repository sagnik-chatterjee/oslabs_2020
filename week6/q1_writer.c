/*
AUTHOR : SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE :

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define max 256

struct msg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

int main() {
	key_t key;
	int msgid;

	// ftok to generate unique key
	key = ftok("progfile", 65);

	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;

	printf("[STATUS] Enter the number to send to check for pallindrome : ");
	fgets(message.mesg_text, max, stdin);

	// msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0);

	// display the message
	printf("[STATUS] Data being sentis : %s \n", message.mesg_text);

	return 0;
}