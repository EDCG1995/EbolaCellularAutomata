#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];
extern int piece;
extern FILE *fp;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int genCount;
extern pthread_mutex_t test_mutex;
int sus = 0;
int infec = 0;
int rem = 0;
int de = 0;
int emptt = 0;
int rec = 0;

//Threads enter this method and are divided by their rank
void *test(void *rank)
{
    long r = (long)rank;
    long check = r * piece;
    // thread 0 will check 0 to 249
    if (check == 0)
        checkNeighbourhood(0, 249, r);
    //thread 1 will check 250 to 499
    if (check == 250)
        checkNeighbourhood(250, 499, r);
    //thread 2 will check 500 to 749
    if (check == 500)
        checkNeighbourhood(500, 749, r);
    //thread 3 will check 750 999//thread 3 will check 750 999
    if (check == 750)
        checkNeighbourhood(750, 999, r);
}

//This method goes through each cell a thread is assigned with
void checkNeighbourhood(int lowerBoundary, int upperBoundary, long r)
{
    int col;
    for (int row = lowerBoundary; row <= upperBoundary; row++)
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
            if (right == INF) infNeigh += 1;
            if (left == INF) infNeigh += 1;
            if (up == INF) infNeigh += 1;
            if (down == INF) infNeigh += 1;
            if (upLeft == INF) infNeigh += 1;
            if (upRight == INF) infNeigh += 1;
            if (downLeft == INF) infNeigh += 1;
            if (downRight == INF) infNeigh += 1;
            //check for dead neighbours
            if (right == DEAD) dead += 1;
            if (left == DEAD) dead += 1;
            if (up == DEAD) dead += 1;
            if (down == DEAD) dead += 1;
            if (upRight == DEAD) dead += 1;
            if (upLeft == DEAD) dead += 1;
            if (downRight == DEAD) dead += 1;
            if (downLeft == DEAD) dead += 1;

            float infRate = setInfectionRate(infNeigh, dead);
            float random = (float)rand() / (float)RAND_MAX;

            switch (world[row][col])
            {
            case SUSC:
                // Debug
                //printf("%d\t", world[row][col]);
                if (random < infRate)
                { //if susc becomes infected
                    temp[row][col] = INF;
                    pthread_mutex_lock(&test_mutex);
                    infec++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else
                {
                    temp[row][col] = SUSC;
                    pthread_mutex_lock(&test_mutex);
                    sus++;
                    pthread_mutex_unlock(&test_mutex);
                }
                break;

            case INF:
                // Debug
                //printf("%d\t", world[row][col]);
                if (random < DEATH)
                { //30% chance of dying
                    temp[row][col] = DEAD;
                    pthread_mutex_lock(&test_mutex);
                    de++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else if (random > POPULATED - 0.05)
                { //10% chance of recovering and being susc
                    temp[row][col] = SUSC;
                    pthread_mutex_lock(&test_mutex);
                    sus++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else if (random >= DEATH && random < IMMUNITY)
                { //Death minus immunity is immunity rate... 40% of becoming immune.
                    temp[row][col] = REC;
                    pthread_mutex_lock(&test_mutex);
                    rec++;
                    pthread_mutex_unlock(&test_mutex);
                }
                else
                { //20% chance of remaining infected
                    temp[row][col] = INF;
                    pthread_mutex_lock(&test_mutex);
                    infec++;
                    pthread_mutex_unlock(&test_mutex);
                }
                break;

            case DEAD:
                // Debug
                //printf("%d\t", world[row][col]);
                if (random <= 0.5)
                {
                    temp[row][col] = REM;
                    pthread_mutex_lock(&test_mutex);
                    rem++;
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
                // Debug
                //printf("%d\t", world[row][col]);
                temp[row][col] = EMPTY;
                pthread_mutex_lock(&test_mutex);
                emptt++;
                pthread_mutex_unlock(&test_mutex);
                break;
            
            case REC:
                temp[row][col] = REC;
                pthread_mutex_lock(&test_mutex);
                rec++;
                pthread_mutex_unlock(&test_mutex);
                break;
            }
        }

        if (r == 0)
        {
            t0 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
            }
        }

        if (r == 1)
        {
            t1 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
            }
        }
        if (r == 2)
        {
            t2 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
            }
        }
        if (r == 3)
        {
            t3 = 1;
            if (t0 == 1 && t1 == 1 && t2 == 1 && t3 == 1)
            {
                updateWorld();
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
    //    fprintf(fp, "%d, %d, %d, %d, %d\n", sus, infec, de, rem, emptt);
    t0 = 0;
    t1 = 0;
    t2 = 0;
    t3 = 0;
    sus = 0;
    infec = 0;
    rem = 0;
    emptt = 0;
    de = 0;
    rec = 0;
}
