#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis];
int temp[Xaxis][Yaxis];
int *p = &world[0][0];
int piece = Yaxis / THREADS;
int t0 = 0;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int genCount = 0;

int main() {
    srand(time(NULL));
    generateWorld();
    pthread_t *thread_handles;
    long thread;
    for (int i = 0; i < GENS; i++) {
        thread_handles = malloc(THREADS * sizeof(pthread_t));
        for (thread = 0; thread < THREADS; thread++) {
            pthread_create(&thread_handles[thread], NULL, test, (void *) thread);
        }
        for (thread = 0; thread < THREADS; thread++) {
            pthread_join(thread_handles[thread], NULL);
        }
        free(thread_handles);
    }
    storeoutput(susc, inf, empty);
    return 0;
}
