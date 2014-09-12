graph.out: main.o dlinked_queue.o graph.o
	gcc $^ -o $@

main.o: main.c dlinked_queue.h graph.h
	gcc -g -c main.c

dlinked_queue.o: dlinked_queue.c dlinked_queue.h
	gcc -g -c dlinked_queue.c

graph.o: graph.c graph.h dlinked_queue.h
	gcc -g -c graph.c

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
