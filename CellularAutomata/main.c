#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis] = {-1};
int temp[Xaxis][Yaxis];
int piece = Yaxis / THREADS;
int t0 = 0;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int genCount = 0;
FILE *fp;
pthread_mutex_t test_mutex;

int main() {
    printf("Program is running %d generations...\n", GENS);
    fp = fopen("dataoutput.csv", "a+");
    fa = fopen("dataoutputanimation.csv", "a+");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
    }
    if (!fa) {
        // Error in file opening
        printf("Can't open file\n");
    }

    fprintf(fp, "Sus,inf,dead,rem,empty\n");
    fclose(fopen("dataoutput.csv", "w"));
    fclose(fopen("dataoutputanimation.csv", "w"));

    srand(time(NULL));
    generateWorld();
    pthread_t *thread_handles;
    long thread;
    pthread_mutex_init(&test_mutex, NULL);

    for (int t = 0; t < GENS; t++) {
        thread_handles = malloc(THREADS * sizeof(pthread_t));
        for (thread = 0; thread < THREADS; thread++) {
            pthread_create(&thread_handles[thread], NULL, test, (void *) thread);
        }
        for (thread = 0; thread < THREADS; thread++) {
            pthread_join(thread_handles[thread], NULL);
        }
        free(thread_handles);

        pthread_mutex_destroy(&test_mutex);

        int s = 0;
        int in = 0;
        int e = 0;
        int d = 0;
        int rem = 0;
        for (int i = 0; i < Xaxis; i++) {
            for (int j = 0; j < Yaxis; j++) {
                // Debug statement
                // fprintf(fa, "%d,", world[i][j]);
                switch (world[i][j]) {

                    case SUSC:
                        s++;
                        break;
                    case INF:
                        in++;
                        break;
                    case EMPTY:
                        e++;
                        break;
                    case DEAD:
                        d++;
                        break;
                    case REM:
                        rem++;
                        break;
                }
            }
            fprintf(fa, "\b\n");
        }

        fprintf(fa, "\n");
        // Prints susceptible, infected, dead, removed and empty to CSV file for data storage and SIR visualization
        fprintf(fp, "%d, %d, %d, %d, %d\n", s, in, d, rem, e);

        // Progress bar to show completion %
        float progress_bar = t * 100.0 / GENS;
        printf("\rProgress = %.2f %%", progress_bar);
    }
    fclose(fp);
    fclose(fa);
    printf("\rProgress =   100 %%");
    printf("\nProgram finished! Check .cvs output.\n");
    return 0;
}