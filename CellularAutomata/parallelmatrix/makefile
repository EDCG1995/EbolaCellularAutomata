matrix_vect_mult: matrix_vect_mult.c Get_dims.c Read_matrix.c Read_vector.c Print_matrix.c Print_vector.c Mat_vec_mult.c Get_dims.o Read_matrix.o Read_vector.o Print_matrix.o Print_vector.o Mat_vec_mult.o myfunctions.h
	gcc -g -Wall -o matrix_vect_mult matrix_vect_mult.c Get_dims.o Read_matrix.o Read_vector.o Print_matrix.o Print_vector.o Mat_vec_mult.o  

Get_dims.o: Get_dims.c
	gcc -c Get_dims.c

Read_matrix.o: Read_matrix.c
	gcc -c Read_matrix.c

Read_vector.o: Read_vector.c
	gcc -c Read_vector.c

Print_matrix.o: Print_matrix.c
	gcc -c Print_matrix.c

Print_vector.o: Print_vector.c
	gcc -c Print_vector.c

Mat_vec_mult.o: Mat_vec_mult.c
	gcc -c Mat_vec_mult.c

clean:
	rm -rf *.exe *.o *.h.gch *.c~ makefile~ *.h~

