threaded_tree.out: stack.o threaded_tree.o main.o
	gcc $^ -o $@

main.o: main.c threaded_tree.h
	gcc -c -g main.c
stack.o: stack.c stack.h
	gcc -c -g stack.c
threaded_tree.o: threaded_tree.c stack.h threaded_tree.h
	gcc -c -g threaded_tree.c

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
