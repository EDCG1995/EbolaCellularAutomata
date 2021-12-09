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
extern int piece;
void *test(void *rank)
{

    /*
    thread 0 will check 0 to 249
    thread 1 will check 250 to 499
    thread 2 will check 500 to 749
    thread 3 will check 750 999
    
    */
    long r = (long)rank;
    long check = r * piece;
    if (check == 0)
    {
        checkNeighbourhood(0, 249);
    }
    if (check == 250)
    {
        checkNeighbourhood(250, 499);
    }
    if (check == 500)
    {
        checkNeighbourhood(500, 749);
    }
    if (check == 750)
    {
        checkNeighbourhood(750, 999);
    }
}

float setInfectionRate(int infectedNeighbours, int deceased)
{ //infection rate starts at 51.5% and increments to 90%

    float infectionRate = 0.;

    switch (infectedNeighbours)
    {
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
    printf("inf neigh= %d, dec= %d, infRate = %f \n", infectedNeighbours, deceased, infectionRate);
    //Return infectionRate;
}

void checkNeighbourhood(int lowerBoundary, int upperBoundary)
{
    int summ = 0;
    for (lowerBoundary; lowerBoundary <= upperBoundary; lowerBoundary++)
    {
        summ++;
    }
    printf("total amount %d", summ);
    int row = 0; //change this bitch
    int col = 0; //change this bitch
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