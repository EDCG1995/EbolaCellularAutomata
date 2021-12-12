#ifndef HEADER_H
#define HEADER_H
#define Xaxis 1000
#define Yaxis 1000
#define ZERO 0.001
#define THREADS 4
#define GENS 75
#define DEBUG 0 
#define DEATH 0.30
#define IMMUNITY 0.7
#define POPULATED 0.95

void generateWorld();

void updateWorld();

void *test(void *rank);

float setInfectionRate(int infectedNeighbours, int deceased);

void checkNeighbourhood(int row, int col, long r);

void storeoutput(int susc, int inf, int empty);

extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];
extern int piece;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int sus;
extern int infec;
extern int rem;
extern int de;
extern int emptt;


enum cellStatus {
    EMPTY, /*is 0*/
    INF,  /*is 1*/
    DEAD, /*is 2*/
    REM,  /*is 3*/
    SUSC, /*is 4*/
    REC
};

#endif


