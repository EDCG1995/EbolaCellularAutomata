#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define DEBUG 0
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];

int susc;
int inf;
int empty;

void generateWorld()
{
  int row;
  int col;
  float random;
  susc = 0;
  inf = 0;
  empty = 0;

  //gets the percetage of populated cells ex. 0.95 (95%)
  float a = 0.95 *(Xaxis * Yaxis);
  float populated = a /(Xaxis * Yaxis);
  for (row = 0; row < Xaxis; row++)
  {
    for (col = 0; col < Yaxis; col++)
    {
      random = (float)rand() / (float)RAND_MAX;
      //cell will be a susceptible person
      if (random <= populated && random >= ZERO)
      {
        world[row][col] = SUSC;
        susc += 1;
      }
      //cell will be an infected person
      else if (random <= populated && random <= ZERO)
      {
        world[row][col] = INF;
        inf += 1;
      }
      //cell will be empty
      else
      {
        world[row][col] = EMPTY;
        empty += 1;
      }
      #if (DEBUG > 0)
      printf("cell [%d][%d] is : %d\n", row, col, world[row][col]);
      #endif
    }
  }
  printf("Population: %f \nSusceptible: %d \nInfected: %d \nEmpty:%d\n", populated, susc, inf, empty);
}