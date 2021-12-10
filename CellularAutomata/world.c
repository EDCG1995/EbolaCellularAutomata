#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];
extern FILE *fp;

void generateWorld() {
    int row;
    int col;
    float random;
    int susc = 0;
    int inf = 0;
    int empty = 0;
    int rem = 0;
    int dead = 0;

    //gets the percetage of populated cells ex. 0.95 (95%)
    float a = 0.95 * (Xaxis * Yaxis);
    float populated = a / (Xaxis * Yaxis);
    for (row = 0; row < Xaxis; row++) {
        for (col = 0; col < Yaxis; col++) {
            random = (float) rand() / (float) RAND_MAX;
            //cell will be a susceptible person
            if (random <= populated && random >= ZERO) {
                world[row][col] = SUSC;
                susc += 1;
            }
                //cell will be an infected person
            else if (random <= populated && random <= ZERO) {
                world[row][col] = INF;
                inf += 1;
            }
                //cell will be empty
            else {
                world[row][col] = EMPTY;
                empty += 1;
            }
        }
    }
    //fprintf(fp, "%d, %d, %d, %d, %d\n", susc, inf,dead,rem ,empty);
}
