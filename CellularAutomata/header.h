#ifndef HEADER_H
#define HEADER_H
#define Xaxis 100000
#define Yaxis 100000

void generateWorld();
void papulateWorld();

typedef enum
{
    EMPTY,
    INFECTED,
    IMMUNE,
    DEAD,
    SUCEPTIBLE
}cell_type;

#endif
