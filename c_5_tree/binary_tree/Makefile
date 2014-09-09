binary_tree.out: queue.o stack.o binary_tree.o main.o
	gcc $^ -g -o $@

main.o: main.c binary_tree.h
	gcc -c -g main.c
queue.o: queue.c queue.h
	gcc -c -g queue.c
stack.o: stack.c stack.h
	gcc -c -g stack.c
binary_tree.o: binary_tree.c binary_tree.h
	gcc -c -g binary_tree.c

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
