#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
int counter = 0;

void *count(void* param) {
	pthread_mutex_lock(&mutex);
	for (int i = 0; i < 100; i++) {

		//now only 1 thread has acess to this piece of code
		counter++;
		printf("Count =%i\n", counter);

	}
	pthread_mutex_unlock(&mutex);
}

int main() {

	pthread_t thread1 , thread2 ;
	pthread_mutex_init(&mutex, 0);//initialte the mutex
	pthread_create(&thread1, 0, count, 0);
	pthread_create(&thread2, 0, count, 0);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	pthread_mutex_destroy(&mutex);
	return 0;

}
