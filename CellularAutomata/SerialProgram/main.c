#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "header.h"

int world[Xaxis][Yaxis] = {-1};
int temp[Xaxis][Yaxis] = {-1};
FILE *fp;
FILE *fa;

int main()
{
    printf("Program is running %d generations...\n", GENS);
    fp = fopen("dataoutput.csv", "a+");
    fa = fopen("dataoutputanimation.csv", "a+");
    if (!fp)
    {
        // Error in file opening
        printf("Can't open file\n");
    }
    if (!fa)
    {
        // Error in file opening
        printf("Can't open file\n");
    }

    fprintf(fp, "Sus, Rec, inf, dead, rem, empty\n");
    fclose(fopen("dataoutput.csv", "w"));
    fclose(fopen("dataoutputanimation.csv", "w"));

    srand(time(NULL));
    generateWorld();
    for (int t = 0; t < GENS; t++)
    {
        checkNeighbourhood();

        int s = 0;
        int in = 0;
        int e = 0;
        int d = 0;
        int rem = 0;
        int rec = 0;

        for (int i = 0; i < Xaxis; i++)
        {

            for (int j = 0; j < Yaxis; j++)
            {
                fprintf(fa, "%d,", world[i][j]);
                if (j < Yaxis - 1){
                    fprintf(fa, ",");
                }
                switch (world[i][j])
                {

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
                case REC:
                    rec++;
                }
            }
            fprintf(fa, "\b\n");
        }

        fprintf(fa, "\n");
        // Prints susceptible, infected, dead, removed and empty to CSV file for data storage and SIR visualization
        fprintf(fp, "%d, %d, %d, %d, %d, %d\n", s, rec, in, d, rem, e);

        // Progress bar to show completion %
        float progress_bar = t * 100.0 / GENS;
        printf("\rProgress = %.2f %%", progress_bar);
    }
    fclose(fp);
    fclose(fa);
    printf("\rProgress =   100 %%");
    printf("\nProgram finished! Check .cvs output.\n");
    return 0;
}