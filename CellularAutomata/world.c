#include <stdlib.h>
#include <stdio.h>
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
    int rec = 0;

    //gets the percetage of populated cells ex. 0.95 (95%)
    for (row = 0; row < Xaxis; row++) {
        for (col = 0; col < Yaxis; col++) {
            random = (float) rand() / (float) RAND_MAX;

            //cell will be a susceptible person
            if (random <= POPULATED && random >= ZERO) {
                world[row][col] = SUSC;
                susc += 1;
            }
                //cell will be an infected person
            else if (random < ZERO ) {
                world[row][col] = INF;
                inf += 1;
            }
                //cell will be empty
            else {
                world[row][col] = EMPTY;
                empty += 1;
            }
            //debug
            //printf("%d\t", world[row][col]);
        }
    }
    for (int i = 0; i < Xaxis; i++) {
        for (int j = 0; j < Yaxis; j++) {
            temp[i][j] = world[i][j];
        }
    }
    fprintf(fp, "%d, %d, %d, %d, %d, %d\n", susc, rec, inf, dead, rem, empty);
}
