deque.out: main.o deque.o
	gcc $^ -o $@

main.o: deque.h
deque.o: deque.h

clean:
	-rm *.o
.PHONY: clean
