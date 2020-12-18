
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int prevsum;//shred value by the threads 
void *runner(void *param)
{
	prevsum = fibonacci((int)param);
	pthread_exit(0);
}

int fibonacci (int x)
{
    if (x <= 1) {
        return 1;
    }
    return fibonacci(x-1) + fibonacci(x-2);
}
int main(int argc, char *argv[])
{
	int count, i;
	pthread_attr_t attr; 

	if (argc != 2) {
		fprintf(stderr,"usage: pthreads <integer value>\n");
		exit(1);
	}

	count = atoi(argv[1]);

	if (count < 1) {
		fprintf(stderr,"%d must be>= 1\n", count);
		exit(1);
	}

	pthread_attr_init(&attr);

	for(i=1;i<=count;i++){
		pthread_t thread;
		pthread_create(&thread,&attr,runner,(void*)i);
		pthread_join(thread,NULL);	
		printf("Fibonacci value  of %d is %d\n", i, prevsum);
	}	
}

