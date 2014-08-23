binary_tree.out: queue.o stack.o binary_tree.o main.o
	gcc $^ -o $@

main.o: binary_tree.h
queue.o: queue.h
stack.o: stack.h
binary_tree.o: binary_tree.h

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
