#include <stdlib.h>
#include <stdio.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];
extern FILE *fp;
//extern int genCount;
//extern int *neighborptr;
int sus = 0;
int infec = 0;
int rem = 0;
int de = 0;
int emptt = 0;

float setInfectionRate(int infectedNeighbours, int deceased) { //infection rate starts at 51.5% and increments to 90%
    float infectionRate = 0.;
    switch (infectedNeighbours) {
        case 1:
            infectionRate = 0.515;
            break;
        case 2:
            infectionRate = 0.57;
            break;
        case 3:
            infectionRate = 0.625;
            break;
        case 4:
            infectionRate = 0.68;
            break;
        case 5:
            infectionRate = 0.735;
            break;
        case 6:
            infectionRate = 0.79;
            break;
        case 7:
            infectionRate = 0.845;
            break;
        case 8:
            infectionRate = 0.9;
            break;
        default:
            infectionRate = 0.0;
    }
    infectionRate += (deceased * 0.05); //the infection rate increases 5% for every infected neighbour
    // Debug
    //printf("inf neigh= %d, dec= %d, infRate = %f \n", infectedNeighbours, deceased, infectionRate);
    return infectionRate;
}

void checkNeighbourhood(int lowerBoundary, int upperBoundary) {

    for (int row = lowerBoundary; row < upperBoundary; row++) {
        for (int col = 0; col < Yaxis; col++) {

            int infNeigh = 0;
            int dead = 0;

            int up = world[row][col + 1];
            int down = world[row][col - 1];
            int left = world[row - 1][col];
            int right = world[row + 1][col];
            int upLeft = world[row - 1][col + 1];
            int upRight = world[row + 1][col + 1];
            int downLeft = world[row - 1][col - 1];
            int downRight = world[row - 1][col + 1];
            //check for infected neighbours
            if (right == INF)
                infNeigh += 1;
            if (left == INF)
                infNeigh += 1;
            if (up == INF)
                infNeigh += 1;
            if (down == INF)
                infNeigh += 1;
            if (upLeft == INF)
                infNeigh += 1;
            if (upRight == INF)
                infNeigh += 1;
            if (downLeft == INF)
                infNeigh += 1;
            if (downRight == INF)
                infNeigh += 1;
            //check for dead neighbours
            if (right == DEAD)
                dead += 1;
            if (left == DEAD)
                dead += 1;
            if (up == DEAD)
                dead += 1;
            if (down == DEAD)
                dead += 1;
            if (upRight == DEAD)
                dead += 1;
            if (upLeft == DEAD)
                dead += 1;
            if (downRight == DEAD)
                dead += 1;
            if (downLeft == DEAD)
                dead += 1;

            float infRate = setInfectionRate(infNeigh, dead);
            float random = (float) rand() / (float) RAND_MAX;

            switch (world[row][col]) {
                case SUSC:
//                    debug
//                    printf("%d, %d\t", row, col);
                    if (random < infRate) { //if susc becomes infected
                        temp[row][col] = INF;
                        infec++;
                    }
                    else {
                        temp[row][col] = SUSC;
                        sus++;
                    }
                    break;
//
//                case INF:
//                    //debug
//                    //printf("%d\t", world[row][col]);
//                    if (random < 0.3) { //30% chance of dying
//                        temp[row][col] = DEAD;
//                        de++;
//                    } else if (random > 0.8) { //20% chance of recovering and being susc
//                        temp[row][col] = SUSC;
//                        sus++;
//                    } else { //50% chance of remaining infected
//                        temp[row][col] = INF;
//                        infec++;
//                    }
//                    break;
//
//                case DEAD:
//                    //debug
//                    //printf("%d\t", world[row][col]);
//                    if (random <= 0.5) {
//                        temp[row][col] = REM;
//                        rem++;
//                    } else {
//                        temp[row][col] = DEAD;
//                        de++;
//                    }
//                    break;
//
//                case EMPTY: // empty
//                    //debug
//                    //printf("%d\t", world[row][col]);
//                    temp[row][col] = EMPTY;
//                    emptt++;
//                    break;
            }
        }
    }
    updateWorld();
}

void updateWorld() {
    for (int i = 0; i < Xaxis; i++) {
        for (int j = 0; j < Yaxis; j++) {
            world[i][j] = temp[i][j];
        }
    }
//    Debug print
//    fprintf(fp, "%d, %d, %d, %d, %d\n", sus, infec, de, rem, emptt);
    sus = 0;
    infec = 0;
    rem = 0;
    emptt = 0;
    de = 0;
}
