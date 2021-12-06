
/*-------------------------------------------------------------------
 * Function:   Print_vector
 * Purpose:    Print the contents of a vector to stdout
 * In args:    title:  title for output
 *             y:      the vector to be printed
 *             m:      the number of elements in the vector
 */
void Print_vector(char title[] /* in */, double y[] /* in */, int m /* in */) {
  int i;

  printf("\nThe vector %s\n", title);
  for (i = 0; i < m; i++)
    printf("%f ", y[i]);
  printf("\n");
} /* Print_vector */
