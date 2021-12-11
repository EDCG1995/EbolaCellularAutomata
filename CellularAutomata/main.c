#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis] = {-1};
int temp[Xaxis][Yaxis];
int genCount = 0;
FILE *fp;
FILE *fa;

int main() {
    printf("Program is running %d generations...\n", GENS);
    fp = fopen("dataoutput.csv", "a+");
    fa = fopen("dataoutputanimation.csv", "a+");
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
    }
    if (!fa) {
        // Error in file opening
        printf("Can't open file\n");
    }

    fprintf(fp, "Sus,inf,dead,rem,empty\n");
    fclose(fopen("dataoutput.csv", "w"));
    fclose(fopen("dataoutputanimation.csv", "w"));

    srand(time(NULL));

    generateWorld();

    for (int t = 0; t < GENS; t++) {

        int s = 0;
        int in = 0;
        int e = 0;
        int d = 0;
        int rem = 0;
        for (int i = 0; i < Xaxis; i++) {
            for (int j = 0; j < Yaxis; j++) {
                // Prints out the cells for the cellular automata table
                // fprintf(fa, "%d,", world[i][j]);
                switch (world[i][j]) {

                    case SUSC:
                        s++;
                        break;
                    case INF:
                        in++;
                        break;
                    case EMPTY:
                        e++;
                        break;
                    case DEAD:
                        d++;
                        break;
                    case REM:
                        rem++;
                        break;
                }
            }
            fprintf(fa, "\n");
        }
        fprintf(fa, "\n");
        fprintf(fp, "%d, %d, %d, %d, %d\n", s, in, d, rem, e);
        float progress_bar = t * 100.0 / GENS;
        printf("\rProgress = %.2f %%", progress_bar);
    }
    fclose(fp);
    fclose(fa);
    printf("\rProgress =   100 %%");
    printf("\nProgram finished! Check .cvs output.\n");
    return 0;
}