#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

#define MAXNTHREADS 100

struct {
    int *buff;  // Change to dynamic array
    int nput;
    int nputval;
    sem_t mutex, nstored;  // Removed nempty semaphore
} shared;

int nitems, nproducers, nconsumers;

void *produce(void *);
void *consume(void *);

int main(int argc, char **argv) {
    int i, ccount[MAXNTHREADS], pcount[MAXNTHREADS];
    pthread_t tid_consume[MAXNTHREADS], tid_produce[MAXNTHREADS];

    if (argc != 4) {
        printf("Invalid number of arguments. Need nitems, nproducers, and nconsumers.\n");
        exit(3);
    }

    nitems = atoi(argv[1]);
    nproducers = min(atoi(argv[2]), MAXNTHREADS);
    nconsumers = min(atoi(argv[3]), MAXNTHREADS);

    sem_init(&shared.mutex, 0, 1);
    sem_init(&shared.nstored, 0, 0);

    shared.buff = (int *)malloc(nitems * sizeof(int));  // Dynamically allocate buffer

    for (i = 0; i < nproducers; i++) {
        pcount[i] = 0;
        pthread_create(&tid_produce[i], NULL, produce, &pcount[i]);
    }

    for (i = 0; i < nconsumers; i++) {
        ccount[i] = 0;
        pthread_create(&tid_consume[i], NULL, consume, &ccount[i]);
    }

    for (i = 0; i < nproducers; i++)
        pthread_join(tid_produce[i], NULL);
    for (i = 0; i < nconsumers; i++)
        pthread_join(tid_consume[i], NULL);

    printf("\nNumber of items contributed by each producer thread:\n");
    for (i = 0; i < nproducers; i++)
        printf("pcount[%d] = %d\n", i, pcount[i]);

    printf("\nNumber of items consumed by each consumer thread:\n");
    for (i = 0; i < nconsumers; i++)
        printf("ccount[%d] = %d\n", i, ccount[i]);

    sem_destroy(&shared.mutex);
    sem_destroy(&shared.nstored);
    free(shared.buff);  // Free dynamically allocated buffer
    exit(0);
}

void *produce(void *arg) {
    for (;;) {
        sem_wait(&shared.mutex);
        shared.buff[shared.nput % nitems] = shared.nputval;
        printf("p:%d ", shared.nputval);
        shared.nput++;
        shared.nputval++;
        sem_post(&shared.mutex);
        sem_post(&shared.nstored);
        (*((int *)arg))++;
    }
}

void *consume(void *arg) {
    int i;

    for (i = 0; i < nitems; i++) {
        sem_wait(&shared.nstored);
        sem_wait(&shared.mutex);
        printf("c:%d ", shared.buff[i % nitems]);
        sem_post(&shared.mutex);
    }
    (*((int *)arg)) = nitems;
    return (NULL);
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
