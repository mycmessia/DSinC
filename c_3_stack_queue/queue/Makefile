deque.out: main.o deque.o
	gcc main.o deque.o -o deque.out
main.o: main.c deque.h
	gcc -c main.c
deque.o: deque.c deque.h
	gcc -c deque.c
