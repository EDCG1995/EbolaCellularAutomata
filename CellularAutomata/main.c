#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include <time.h>

int world[Xaxis][Yaxis];
int main()
{
  srand(time(NULL));
  generateWorld();
  return 0;
}
