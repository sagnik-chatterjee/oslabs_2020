#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BIG 1000000000UL
uint32_t counter = 0;

void count_to_num() {
	for (uint32_t i = 0; i < BIG; i++) {
		counter++;
	}
}


int main() {
	count_to_num();
	count_to_num();
	printf("Done ,counter = %u\n", counter);
	return 0;
}