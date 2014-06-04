stack.out: stack.o main.o
	gcc $^ -o $@

stack.o: stack.h
main.o: stack.h

clean: 
	-rm *.o
.PHONY: clean
