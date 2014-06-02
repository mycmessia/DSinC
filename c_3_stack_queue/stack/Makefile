stack.out: stack.o main.o
	gcc stack.o main.o -o stack.out
stack.o: stack.c stack.h
	gcc -c stack.c
main.o: main.c stack.h
	gcc -c main.c
