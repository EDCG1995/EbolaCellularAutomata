/*
FILE NOT READY, NEEDS TO BE WORKED ON:
  ^USE OF THREADS
  ^LOOP?
  ^ERROR HANDLING BORDERS
  ^VALUE-PASSING

*/
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];

void *test(void *rank) {
    long r = (long) rank;
    switch (r) {
        case 0:
            printf("thread 0");
            break;
        case 1:
            printf("thread 1");
            break;
        case 2:
            printf("thread 2");
            break;

        default:
            printf("thread 3");
            break;
    }

}

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

    //Return infectionRate;
}

void checkNeighbourhood(int row, int col) {
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

    setInfectionRate(infNeigh, dead);
}