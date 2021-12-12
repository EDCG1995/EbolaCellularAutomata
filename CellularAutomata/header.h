#ifndef HEADER_H
#define HEADER_H
#define Xaxis 1000
#define Yaxis 1000
#define ZERO 0.001
#define GENS 5
#define DEBUG 0
#define POPULATED 0.95

void generateWorld();

void updateWorld();

float setInfectionRate(int infectedNeighbours, int deceased);

void checkNeighbourhood(int row, int col);

void storeoutput(int susc, int inf, int empty);

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];


enum cellStatus {
    EMPTY, /*is 0*/
    INF,  /*is 1*/
    DEAD, /*is 2*/
    REM,  /*is 3*/
    SUSC, /*is 4*/
};

#endif


