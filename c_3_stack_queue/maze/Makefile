maze.out: main.o maze.o stack.o
	gcc $^ -o $@

main.o: maze.h
	gcc -g -c main.c
maze.o: maze.h stack.h
	gcc -g -c maze.c
stack.o: stack.h
	gcc -g -c stack.c

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
