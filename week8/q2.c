#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define max_threads 4
#define size 16

int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 }; 
int sum[]={0,0,0,0};
int part=0;

void * sum_array(void *args){
	int thread_part =part++;
	//using 4 threads so diviing into 4 parts 
	for(int i=thread_part * (size/4);i<(thread_part+1)*(size/4);i++){
		sum[thread_part]+=arr[i];
	}
}


int main(){
	printf("Numbers given for summation \n");
	for(int i=0;i<16;i++){
		printf("%d  ",arr[i]);
	}
	printf("\n");

	pthread_t threads[max_threads];

	//create the 4 threads 
	for(int i=0;i<max_threads;i++){
		pthread_create(&threads[i],NULL,sum_array,(void*)arr);
	}

	//wait for all threads to complete before joining 
	for(int i=0;i<max_threads;i++){
		pthread_join(threads[i],NULL);
	}	
	
	//adding sum of all 4 parts 
	int total_sum=0;
	for(int i=0;i<max_threads;i++){
		total_sum+=sum[i];
	}
	printf("\nSum is %d\n",total_sum);
	return 0;

}
