#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
void generateWorld()
{
  int row;
  int col;
  float random;
  int susc = 0;
  int inf = 0;
  int empty = 0;
  //gets the percetage of populated cells ex. 0.95 (95%)
  float populated = (float)POPULATION / (Xaxis * Yaxis);
  printf("%f", populated);
  for (row = 0; row <= Xaxis; row++)
  {
    for (col = 0; col <= Yaxis; col++)
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
      printf("cell [%d][%d] is : %d \n", row, col, world[row][col]);
    }
  }
  printf("Population rate: %f \nSusceptible: %d \nInfected: %d \nEmpty:%d\n", populated, susc, inf, empty);
}