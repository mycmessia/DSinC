maze.out: main.o maze.o stack.o
	gcc $^ -o $@

main.o: maze.h
maze.o: maze.h stack.h
stack.o: stack.h

clean:
	-rm *.o
.PHONY: clean
