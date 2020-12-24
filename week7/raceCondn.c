#include <pthread.h>
#include <stdio.h>

int counter = 0; //common piece of data that can be used in race condition

void *func(void *params) {
	counter++;
}

int main() {

	pthread_t thread1 , thread2; //creating 2 threads
	pthread_create(&thread1, 0, func, 0);
	pthread_create(&thread2, 0, func , 0);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
}