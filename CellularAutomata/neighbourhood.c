/*
FILE NOT READY, NEEDS TO BE WORKED ON:
  ^USE OF THREADS
  ^LOOP?
  ^ERROR HANDLING BORDERS
  ^VALUE-PASSING

*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];
extern int piece;
extern FILE *fp;
extern int (*p)[Xaxis][Yaxis];
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int genCount;
extern pthread_mutex_t test_mutex;
int sus = 0;
int infec = 0;
int empt = 0;
int de = 0;

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

        checkNeighbourhood(0, 249, r);
    }
    if (check == 250)
    {

        checkNeighbourhood(250, 499, r);
    }
    if (check == 500)
    {

        checkNeighbourhood(500, 749, r);
    }
    if (check == 750)
    {

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

            switch (world[row][col])
            {
            case SUSC:

                if (random > infRate && random < ZERO)
                { //if susc becomes infected
                    temp[row][col] = INF;
                    pthread_mutex_lock(&test_mutex);
                    infec++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else if (random > infRate && random > ZERO)
                {
                    temp[row][col] = SUSC;
                    pthread_mutex_lock(&test_mutex);
                    sus++;
                    pthread_mutex_unlock(&test_mutex);
                }
                break;

            case INF:

                if (random < 0.3)
                { //30% chance of dying
                    temp[row][col] = DEAD;
                    pthread_mutex_lock(&test_mutex);
                    de++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else if (random > 0.8)
                { //20% chance of recovering and being susc
                    temp[row][col] = SUSC;
                    pthread_mutex_lock(&test_mutex);
                    sus++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else
                { //50% chance of remaining infected
                    temp[row][col] = INF;
                    pthread_mutex_lock(&test_mutex);
                    infec++;
                    pthread_mutex_unlock(&test_mutex);
                }

                break;
            case DEAD:
                if (random <= 0.5)
                {
                    temp[row][col] = EMPTY;
                    pthread_mutex_lock(&test_mutex);
                    empt++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else
                {
                    temp[row][col] = DEAD;
                    pthread_mutex_lock(&test_mutex);
                    de++;
                    pthread_mutex_unlock(&test_mutex);
                }
                break;
            case EMPTY: // empty
                temp[row][col] = EMPTY;
                pthread_mutex_lock(&test_mutex);
                empt++;
                pthread_mutex_unlock(&test_mutex);
                break;
            }
        }
        printf("thread %ld finished \n", r);

        if (r == 0)
        {
            t0 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
                printf("thread %ld updated the table\n", r);
            }
        }

        if (r == 1)
        {
            t1 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
                printf("thread %ld updated the table\n", r);
            }
        }

        if (r == 2)
        {
            t2 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
                printf("thread %ld updated the table\n", r);
            }
        }

        if (r == 3)
        {
            t3 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
                printf("thread %ld updated the table\n", r);
            }
        }
    }
}
void updateWorld()
{
    for (int i = 0; i < Xaxis; i++)
    {
        for (int j = 0; j < Yaxis; j++)
        {
            world[i][j] = temp[i][j];
        }
    }
    //fprintf(fp, "%d, %d, %d, %d\n", sus, infec, de, empt);
    t0 = 0;
    t1 = 0;
    t2 = 0;
    t3 = 0;
    sus = 0;
    infec = 0;
    empt = 0;
}
