sparse_matrix.out: mmult.o mread_print_search.o transpose.o sparse_matrix.o
	gcc mmult.o mread_print_search.o transpose.o sparse_matrix.o -o sparse_matrix.out

mmult.o: mmult.c sparse_matrix.h ../../c_1_basic_concept/compare.h
	gcc -c mmult.c

mread_print_search.o: mread_print_search.c sparse_matrix.h
	gcc -c mread_print_search.c

transpose.o: transpose.c sparse_matrix.h
	gcc -c transpose.c

sparse_matrix.o: sparse_matrix.c sparse_matrix.h
	gcc -c sparse_matrix.c
