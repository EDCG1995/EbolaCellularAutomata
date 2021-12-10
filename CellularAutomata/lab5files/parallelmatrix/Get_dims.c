/*-------------------------------------------------------------------
 * Function:   Get_dims
 * Purpose:    Read the dimensions of the matrix from stdin
 * Out args:   m_p:  number of rows
 *             n_p:  number of cols
 *
 * Errors:     If one of the dimensions isn't positive, the program
 *             prints an error and quits
 */

#include <stdio.h>
#include <stdlib.h>

void Get_dims(int *m_p /* out */, int *n_p /* out */) {
    printf("Enter the number of rows\n");
    scanf("%d", m_p);
    printf("Enter the number of columns\n");
    scanf("%d", n_p);

    if (*m_p <= 0 || *n_p <= 0) {
        fprintf(stderr, "m and n must be positive\n");
        exit(-1);
    }
} /* Get_dims */
