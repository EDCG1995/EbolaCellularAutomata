#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis];
int temp[Xaxis][Yaxis];
int piece = Yaxis / THREADS;

int main() {
    srand(time(NULL));
    generateWorld();
    pthread_t *thread_handles;
    long thread;
    thread_handles = malloc(THREADS * sizeof(pthread_t));
    for (thread = 0; thread < THREADS; thread++) {
        pthread_create(&thread_handles[thread], NULL, test, (void *) thread);
    }
    for (thread = 0; thread < THREADS; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);

    return 0;
}
