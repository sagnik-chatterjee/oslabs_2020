#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;

void *threadFunc(void *thread) {
	while (1) {
		sleep(1);
		count += 1;
		printf("My turn !\n");
		printf("Count:- %d\n", count);
	}
	return NULL;
}


void yourturn() {
	while (1) {
		sleep(2);
		count += 1;
		printf("Your turn!!\n");
		printf("COunt :- %d\n", count);
	}
}


int main() {
	pthread_t newthread;
	pthread_create(&newthread, NULL, threadFunc, NULL);
	yourturn();
	pthread_join(&threadFunc, NULL);
	return 0;
}
