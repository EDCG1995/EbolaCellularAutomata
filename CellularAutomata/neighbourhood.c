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
extern int t0;
extern int t1;
extern int t2;
extern int t3;

void *test(void *rank)
{
    long r = (long)rank;
    long check = r * piece;
    if (check == 0)
    {
        //thread 0 will check 0 to 249    
        checkNeighbourhood(0, 249, r);
    }
    if (check == 250)
    {
        //thread 1 will check 250 to 499
        checkNeighbourhood(250, 499, r);
    }
    if (check == 500)
    {
        //thread 2 will check 500 to 749    
        checkNeighbourhood(500, 749, r);
    }
    if (check == 750)
    {
        //thread 3 will check 750 999    
        checkNeighbourhood(750, 999, r);
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
    //printf("inf neigh= %d, dec= %d, infRate = %f \n", infectedNeighbours, deceased, infectionRate);
    return infectionRate;
}

void checkNeighbourhood(int lowerBoundary, int upperBoundary, long r)
{

    int row = lowerBoundary;
    int col;
    int infcounter = 0;
            int deadCounter = 0;
    for (row; row <= upperBoundary; row++)
    {
        for (col = 0; col < Yaxis; col++)
        {

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
            float random = (float)rand() / (float)RAND_MAX;
            
            if (random < infRate && world[row][col]==SUSC)
            {
                temp[row][col] = INF;
                infcounter++;
            }
            if(random> 0.5 && world[row][col] == INF){
                temp[row][col] = DEAD;
                deadCounter++;
            }
        }
        
    }
    printf("Thread %ld changed %d to infected and %d to dead \n",r,infcounter, deadCounter);
    printf("thread %ld finished \n",r );
    

    if (r == 0)
    {
        t0 = 1;
        if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
        {
            world[Xaxis][Yaxis] = temp[Xaxis][Yaxis];
            t0 = 0;
            t1 = 0;
            t2 = 0;
            t3 = 0;
            printf("thread %ld updated the table", r);
        }
    }

    if (r == 1)
    {
        t1 = 1;
        if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
        {
            world[Xaxis][Yaxis] = temp[Xaxis][Yaxis];
            t0 = 0;
            t1 = 0;
            t2 = 0;
            t3 = 0;
            printf("thread %ld updated the table", r);
        }
    }

    if (r == 2)
    {
        t2 = 1;
        if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
        {
            world[Xaxis][Yaxis] = temp[Xaxis][Yaxis];
            t0 = 0;
            t1 = 0;
            t2 = 0;
            t3 = 0;
            printf("thread %ld updated the table", r);
        }
    }

    if (r == 3)
    {
        t3 = 1;
        if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
        {
            world[Xaxis][Yaxis] = temp[Xaxis][Yaxis];
            t0 = 0;
            t1 = 0;
            t2 = 0;
            t3 = 0;
            printf("thread %ld updated the table", r);
        }
    }
    
}