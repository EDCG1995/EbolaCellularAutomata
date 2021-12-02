#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "header.h"

int world[Xaxis][Yaxis];


void generateWorld(){
  srand(time(NULL));
  int row;
  int col;
  for(row = 0; row < Xaxis; row++){
    for(col = 0; col < Yaxis; col++){
      float random = (float)rand()/(float)RAND_MAX; 
    }
  }
  printf("generate world accessed!");
}
void populateWorld(){}
