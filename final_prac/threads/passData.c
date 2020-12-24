#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_1_func(void *param) {
	int id = (int)param;
	printf("Starting thread %i\n", id);
	return (void*)id;
}

int main(int argc, char const **argv) {

	pthread_t thread[10];
	int return_value[10];

	for (int i = 0; i < 10; i++) {
		pthread_create(&thread[i], 0, &thread_1_func, (void*)i);
	}
	for (int i = 0; i < 10; i++) {
		pthread_join(thread[i], (void**)&return_value[i]);
		printf("End Thread %i\n", return_value[i]);
	}
	return 0;
}