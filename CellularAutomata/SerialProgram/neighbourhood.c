#include <stdlib.h>
#include <stdio.h>
#include "header.h"

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];
extern FILE *fp;
int sus = 0;
int infec = 0;
int rem = 0;
int de = 0;
int emptt = 0;
int rec = 0;

void checkNeighbourhood()
{

    for (int row = 0; row < Xaxis; row++)
    {
        for (int col = 0; col < Yaxis; col++)
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
                // Debug
                //printf("%d\t", world[row][col]);
                if (random < infRate)
                { //if susc becomes infected
                    temp[row][col] = INF;
                    infec++;
                }
                else
                {
                    temp[row][col] = SUSC;
                    sus++;
                }
                break;

            case INF:
                // Debug
                //printf("%d\t", world[row][col]);
                if (random < DEATH)
                { //30% chance of dying
                    temp[row][col] = DEAD;
                    de++;
                }
                else if (random > POPULATED - 0.05)
                { //10% chance of recovering and being susc
                    temp[row][col] = SUSC;
                    sus++;
                }
                else if (random >= DEATH && random < IMMUNITY)
                { //Death minus immunity is immunity rate... 40% of becoming immune.
                    temp[row][col] = REC;
                    rec++;
                }
                else
                { //20% chance of remaining infected
                    temp[row][col] = INF;
                    infec++;
                }
                break;

            case DEAD:
                // Debug
                //printf("%d\t", world[row][col]);
                if (random <= 0.5)
                {
                    temp[row][col] = REM;
                    rem++;
                }
                else
                {
                    temp[row][col] = DEAD;
                    de++;
                }
                break;

            case EMPTY: // empty
                // Debug
                //printf("%d\t", world[row][col]);
                temp[row][col] = EMPTY;
                emptt++;
                break;
            
            case REC:
                temp[row][col] = REC;
                emptt++;
                break;
            }
        }
    }
    updateWorld();
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
    sus = 0;
    infec = 0;
    rem = 0;
    emptt = 0;
    de = 0;
    rec = 0;
}
