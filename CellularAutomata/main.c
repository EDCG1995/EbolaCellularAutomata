#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis];
int temp[Xaxis][Yaxis];
int main()
{
  srand(time(NULL));
  generateWorld();

  return 0;
}
