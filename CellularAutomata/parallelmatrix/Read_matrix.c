/*-------------------------------------------------------------------
 * Function:   Read_matrix
 * Purpose:    Read the contents of the matrix from stdin
 * In args:    prompt:  description of matrix
 *             m:       number of rows
 *             n:       number of cols
 * Out arg:    A:       the matrix
 */


#include <stdio.h>

void Read_matrix(char prompt[] /* in  */, double A[] /* out */, int m /* in  */,
                 int n /* in  */) {
  int i, j;

  printf("Enter the matrix %s\n", prompt);
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%lf", &A[i * n + j]);
} /* Read_matrix */
