#ifndef HEADER_H
#define HEADER_H
#define Xaxis 1000
#define Yaxis 1000
#define ZERO 0.05

void generateWorld();
void checkNeighbourhood();
float setInfectionRate(int infectedNeighbours, int deceased);
void checkNeighbourhood(int row, int col);
extern int world[Xaxis][Yaxis];
extern int temp[Xaxis][Yaxis];

enum cellStatus
{
    SUSC, /*is 0*/
    INF,  /*is 1*/
    DEAD, /*is 2*/
    REC,  /*is 3*/
    EMPTY /*is 4*/
};

#endif
