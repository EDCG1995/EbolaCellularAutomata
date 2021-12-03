/*-------------------------------------------------------------------
 * Function:   Read_vector
 * Purpose:    Read a vector from stdin
 * In args:    prompt:  description of matrix
 *             n:       order of matrix
 * Out arg:    x:       the vector being read in
 */

#include <stdio.h>

void Read_vector(char prompt[] /* in  */, double x[] /* out */,
                 int n /* in  */) {
  int i;

  printf("Enter the vector %s\n", prompt);
  for (i = 0; i < n; i++)
    scanf("%lf", &x[i]);
} /* Read_vector */
