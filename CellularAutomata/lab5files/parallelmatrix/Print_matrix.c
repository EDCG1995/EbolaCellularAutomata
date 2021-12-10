/*-------------------------------------------------------------------
 * Function:   Print_matrix
 * Purpose:    Print a matrix to stdout
 * In args:    title:  title for output
 *             A:      the matrix
 *             m:      number of rows
 *             n:      number of cols
 */
void Print_matrix(char title[] /* in */, double A[] /* in */, int m /* in */,
                  int n /* in */) {
    int i, j;

    printf("\nThe matrix %s\n", title);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
            printf("%f ", A[i * n + j]);
        printf("\n");
    }
} /* Print_matrix */
