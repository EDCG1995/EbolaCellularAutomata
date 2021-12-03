/* File:     mat_vect_mult.c
 *
 * Purpose:  Implement serial matrix-vector multiplication using
 *           one-dimensional arrays to store the vectors and the
 *           matrix.
 *
 * Compile:  ./gcc -g -Wall -o mat_vect_mult mat_vect_mult.c
 * Run:      ./mat_vect_mult
 *
 * Input:    Dimensions of the matrix (m = number of rows, n
 *              = number of columns)
 *           n-dimensional vector x
 * Output:   Product vector y = Ax
 *
 * Errors:   if the number of user-input rows or column isn't
 *           positive, the program prints a message and quits.
 * Note:     Define DEBUG for verbose output
 *
 * IPP:      Section 3.4.9 (pp. 113 and ff.), Section 4.3 (pp. 159
 *           and ff.), and Section 5.9 (pp. 252 and ff.)
 */
#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>

/*-------------------------------------------------------------------*/
int main(void) {
  double *A = NULL;
  double *x = NULL;
  double *y = NULL;
  int m, n;

  Get_dims(&m, &n);
  A = malloc(m * n * sizeof(double));
  x = malloc(n * sizeof(double));
  y = malloc(m * sizeof(double));
  if (A == NULL || x == NULL || y == NULL) {
    fprintf(stderr, "Can't allocate storage\n");
    exit(-1);
  }
  Read_matrix("A", A, m, n);
#ifdef DEBUG
  Print_matrix("A", A, m, n);
#endif
  Read_vector("x", x, n);
#ifdef DEBUG
  Print_vector("x", x, n);
#endif

  Mat_vect_mult(A, x, y, m, n);

  Print_vector("y", y, m);

  free(A);
  free(x);
  free(y);
  return 0;
} /* main */

