#include <stdlib.h>
#include <stdio.h>
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
#include <pthread.h>
=======
>>>>>>> ab1466c201ae69291d96fdc6b1b7930c43ffd5ed
>>>>>>> Stashed changes
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis];
int temp[Xaxis][Yaxis];

int main()
{
  srand(time(NULL));
  generateWorld();
  pthread_t *thread_handles;
  long thread;
  thread_handles = malloc(THREADS*sizeof(pthread_t));
  for(thread = 0; thread < THREADS; thread++){
    
    pthread_create(&thread_handles[thread], NULL, test, (void *)thread);
    printf("Hello from main");
  }
  for(thread =0; thread<THREADS; thread++){
    pthread_join(thread_handles[thread], NULL);
  }
  free(thread_handles);

  return 0;
}
