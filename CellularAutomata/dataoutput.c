#include <stdio.h>
#include <string.h>


// Driver Code
void storeoutput(int susc, int inf, int empty)
{
    // Substitute the file_path string
    // with full path of CSV file
    FILE* fp = fopen("dataoutput.csv", "a+");

    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
    }

    // Saving data in file
    fprintf(fp, "%d, %d, %d\n", susc, inf, empty);

    printf("\nNew Account added to record");

    fclose(fopen("dataoutput.csv", "w"));

    fclose(fp);

}
