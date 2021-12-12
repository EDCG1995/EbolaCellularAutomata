#include <stdlib.h>
#include <stdio.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];

//extern FILE *fp;

void generateWorld() {
    int row;
    int col;
    float random;
    int susc = 0;
    int inf = 0;
    int empty = 0;
    int rem = 0;
    int dead = 0;

    //gets the percentage of populated cells ex. 0.95 (95%)
    for (row = 0; row < Xaxis; row++) {
        for (col = 0; col < Yaxis; col++) {
            random = (float) rand() / (float) RAND_MAX;


            // Debug
            //printf("%d\t", world[row][col]);

            //cell will be a susceptible person
            if (random <= POPULATED && random >= ZERO) {
                world[row][col] = SUSC;
                susc += 1;
            }
                //printf("%d\t", world[row][col]);
                //cell will be an infected person
            else if (random < ZERO && random <= POPULATED) {
                world[row][col] = INF;
                inf += 1;
            }
                //printf("%d\t", world[row][col]);
                //cell will be empty
            else {
                world[row][col] = EMPTY;
                empty += 1;
            }
            // Debug
            //printf("cell [%d][%d] is : %d\n", row, col, world[row][col]);
        }
    }
    for (int i = 0; i < Xaxis; i++) {
        for (int j = 0; j < Yaxis; j++) {
            temp[i][j] = world[i][j];
        }
    }


//    fprintf(fp, "%d, %d, %d, %d, %d\n", susc, inf, dead, rem, empty);

}
