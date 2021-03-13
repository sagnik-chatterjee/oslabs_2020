#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex1, mutex2;
int count = 0;


void *oddNums(void* args) {
	int p = (int*)args;
	for (int i = 0; i < p; i++) {
		pthread_mutex_lock(&mutex1);
		if (count % 2 != 0) {
			pthread_cond_wait(&mutex2);
		}
		count++;
		printf("Counter value oddSUms: %d\n", count);
		pthread_cond_signal(&mutex2);
		if (count >= p) {
			pthread_mutex_unlock(&mutex1);
			return NULL;
		}
		pthread_mutex_unlock(&mutex1);
	}
}


void *evenNums(void *args) {

}

int main() {
	pthread_t thread1, thread2;
	pthread_mutex_init(&mutex1, 0);
	pthread_mutex_init(&mutex2, 0);

	printf("Enter the limit to count \n");
	int counttill;
	scanf("%d", &counttill);

	pthread_create(&thread1, 0, oddNums, (void*)counttill);
	pthread_create(&thread2, 0, evenNums, (void*)counttill);

	pthread_join(&thread1);
	pthread_join(&thread2);
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
}