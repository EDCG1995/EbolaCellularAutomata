/*-------------------------------------------------------------------
 * Function:   Mat_vect_mult
 * Purpose:    Multiply a matrix by a vector
 * In args:    A: the matrix
 *             x: the vector being multiplied by A
 *             m: the number of rows in A and components in y
 *             n: the number of columns in A components in x
 * Out args:   y: the product vector Ax
 */
void Mat_vect_mult(double A[] /* in  */, double x[] /* in  */,
                   double y[] /* out */, int m /* in  */, int n /* in  */) {
  int i, j;

  for (i = 0; i < m; i++) {
    y[i] = 0.0;
    for (j = 0; j < n; j++)
      y[i] += A[i * n + j] * x[j];
  }
} /* Mat_vect_mult */
