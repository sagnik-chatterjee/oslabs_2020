/*
AUTHOR : SAGNIK CHATTERJEE
DATE : DEC 15,2020
USAGE : ./q1r
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define max 256

struct msg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;

int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
} 
  
int isPalindrome(int n) 
{ 
	int rev_num = reverseDigits(n); 
  
    if (rev_num == n) 
        return 1; 
    else
        return 0; 
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

	int number = atoi(message.mesg_text);
	printf("[STATUS] Data Received is :%d\n", number);
	if (isPalindrome(number)==1) {
		//yes this is a palindrome
		printf("[STATUS] %d is a palindrome number.\n",number);
	}
	else {
		printf("[STATUS] No this is not a palindrome number.\n");
	}
	//destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}