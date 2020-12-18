#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


int buf[10], f = 0,r = 0, item, val;
sem_t mutex, full, empty;

void *producer(void *arg){
    int i;
    for(i = 0;i < 10; i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Produced item is %d\n", i);
        buf[(++r) % 10] = i;
        sleep(1);
        sem_post(&mutex);
        sem_post(&full);
        sem_getvalue(&full, &val);
        printf("Full : %d \n", val);
    }
}

void *consumer(void *arg){
    int i;
    for(i = 0; i < 10; i++){
        sem_getvalue(&full, &val);
        printf("Full:%d \n", val);
        sem_wait(&full);
        sem_wait(&mutex);
        item = buf[(++f) % 10];
        printf("Consuming the item %d\n", item);
        sleep(1);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char const *argv[]){
    pthread_t tid1, tid2;
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 1);
    sem_init(&empty, 0, 10);
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    return 0;
}