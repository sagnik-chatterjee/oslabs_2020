#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

int count = 0;

//checking for even and odd nums till this range 
#define COUNT_DONE 500


// print odd numbers
void *oddNums(void* args)
{
	for(;;) {
		// Lock mutex and then wait for signal to relase mutex
		pthread_mutex_lock( &count_mutex );
		if ( count % 2 != 0 ) {
			pthread_cond_wait( &condition_var, &count_mutex );
		}
		count++;
		printf("Counter value oddSums: %d\n",count);
		pthread_cond_signal( &condition_var );
		if ( count >= COUNT_DONE ) {
			pthread_mutex_unlock( &count_mutex );
			return(NULL);
		}
		pthread_mutex_unlock( &count_mutex );
	}
}

// print even numbers
void *evenNums(void* args)
{
	for(;;) {
		// Lock mutex and then wait for signal to release mutex
		pthread_mutex_lock( &count_mutex );
		if ( count % 2 == 0 ) {
			pthread_cond_wait( &condition_var, &count_mutex );
		}

		count++;

		printf("Counter value evenSum: %d\n",count);
		pthread_cond_signal( &condition_var );
		if( count >= COUNT_DONE ) {
			pthread_mutex_unlock( &count_mutex );
			return(NULL);
		}
		pthread_mutex_unlock( &count_mutex );
	}
}

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, oddNums, NULL);
	pthread_create(&thread2, NULL, evenNums, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

