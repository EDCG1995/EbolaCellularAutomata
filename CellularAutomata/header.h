#ifndef HEADER_H
#define HEADER_H
#define Xaxis 100
#define Yaxis 100
#define POPULATION 9500
#define ZERO 0.05

void generateWorld();
extern int world[Xaxis][Yaxis];

enum cellStatus
{
    SUSC, /*is 0*/
    INF,  /*is 1*/
    DEAD, /*is 2*/
    REC,  /*is 3*/
    EMPTY /*is 4*/
};

#endif
