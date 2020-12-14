/*
AUTHOR : SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE :

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdbool.h>

#define max 256

struct msg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

bool checkPalindrome(int data) {
	int number2 = data;

	int temp = 0;
	while (data != 0) {
		int  p = data % 10;
		temp = temp * 10 + data;
		data = data / 10;
	}
	if (temp == number2) {
		return true;
	}
	return false;

}


int main() {
	key_t key;
	int msgid;

	//ftok to generate unique key
	key = ftok("progfile", 65);

	//msgget creates a message queue
	//and returns  indentifer
	msgid = msgget(key, 0666 | IPC_CREAT);

	//msgrev to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);

	//check if the messagedata is pallindrome or not

	printf("[STATUS] Data Received is :%s\n", message.mesg_text);
	if (checkPalindrome(atoi(message.mesg_text))) {
		//yes this is a palindrome
		printf("[STATUS] It is a palindrome number.\n");
	}
	else {
		printf("[STATUS] No this is not a palindrome number.\n");
	}
	//destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
}