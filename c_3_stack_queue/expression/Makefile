expr.out: main.o expression.o stack.o
	gcc $^ -o $@

main.o: expression.h
	gcc -c -g main.c
expression.o: expression.h stack.h
	gcc -c -g expression.c
stack.o: stack.h
	gcc -c -g stack.c

clean:
	-rm *.o
.PHONY: clean
