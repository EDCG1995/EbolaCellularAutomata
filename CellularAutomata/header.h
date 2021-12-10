#ifndef HEADER_H
#define HEADER_H
#define Xaxis 1000
#define Yaxis 1000
#define ZERO 0.05
#define THREADS 4
#define GENS 2

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

enum cellStatus {
    SUSC, /*is 0*/
    INF,  /*is 1*/
    DEAD, /*is 2*/
    REC,  /*is 3*/
    EMPTY /*is 4*/
};

#endif


