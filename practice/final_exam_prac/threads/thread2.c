#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void *threadFunc1(void *arg) {
	int *ptr = (int*)malloc(sizeof(int));
	*ptr = 5;
	for (int i = 0; i < 6; i++) {
		sleep(1);
		printf("Turn of thread1\n");
		printf("COunter value %d\n", *ptr);
		*(ptr) += 1;
	}
	return ptr;
}

void *threadFunc2(void *args) {
	for (int i = 0; i < 5; i++) {
		sleep(2);
		printf("Turn of thread 2 \n");
	}
}

int main() {
	pthread_t thread1 , thread2 ;

	//int v = 5;
	int *result ;

	pthread_create(&thread1, NULL, threadFunc1, NULL);
	pthread_create(&thread2, NULL, threadFunc2, NULL);

	pthread_join(thread1, (void*)&result );
	pthread_join(thread2, NULL);

	printf("THread1 and 2 are done and thread 1 returns : %d\n", *result);
	return 0;
}
