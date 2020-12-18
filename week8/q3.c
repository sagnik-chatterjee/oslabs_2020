#include<stdio.h>
#include<pthread.h>

#define N 10
#define MAX_THREADS 4

int prime_arr[N]={0};

void *printprime(void *ptr)
{
    int  j,flag;
    int i=(int)(long long int)ptr;
    while(i<N)
    {
        printf("Thread id[%ld] checking [%d]\n",pthread_self(),i);
        flag=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==0 && (i>1))
        {
            prime_arr[i]=1;
        }
        i+=MAX_THREADS;
  }
}

int main(int argc ,char **argv)
{
    pthread_t tid[MAX_THREADS]={{0}};
    printf("The numbers added are :-");
    int a =atoi(argv[1]);
    int b =atoi(argv[2]);
    printf("%d\n",a);
    printf("%d\n",b);
    int count=0;
    for(count=0;count<MAX_THREADS;count++)
    {
        printf("\r\n CREATING THREADS %d",count);
        pthread_create(&tid[count],NULL,printprime,(void*)count);
    }
    printf("\n");
    for(count=0;count<MAX_THREADS;count++)
    {
        pthread_join(tid[count],NULL);
    }

    int c=0;
    printf("The prime numbers found are :\n");
    for(count=a;count<=b;count++)
        if(prime_arr[count]==1)
            printf("\n %d \n",count);

    return 0;
 }