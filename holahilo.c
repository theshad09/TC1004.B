#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 100
int saldo;
pthread_mutex_t saldoLock;
void*suma100(void*arg)
{
    int localsaldo=PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&saldoLock)
    localsaldo=localsaldo+100;
    saldo=localsaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    saldo=0;
    for(int i=0;i<NUM_THREADS;i++)
    {
        pthread_create(&threads[i],NULL,suma100,NULL);
    }

    for(int i=0;i<NUM_THREADS;i++)
    {
        pthread_join(threads[i],NULL);
    }

    printf("Saldo final %d\n",saldo);
    pthread_exit(NULL);
}