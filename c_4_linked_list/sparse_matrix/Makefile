sparse_matrix.out: sparse_matrix.o main.o
	gcc $^ -o $@

sparse_matrix.o: sparse_matrix.h
main.o: sparse_matrix.h

clean:
	-rm *.o *.out

.PHONY: clean
