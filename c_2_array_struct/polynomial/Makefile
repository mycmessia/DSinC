polynomial.out: peval.o pmult.o pread_print.o polynomial.o
	gcc peval.o pmult.o pread_print.o polynomial.o -o polynomial.out

polynomial.o: polynomial.c polynomial.h
	gcc -c polynomial.c

peval.o: peval.c polynomial.h
	gcc -c peval.c

pmult.o: pmult.c polynomial.h
	gcc -c pmult.c

pread_print.o: pread_print.c polynomial.h ../../c_1_basic_concept/compare.h
	gcc -c pread_print.c
