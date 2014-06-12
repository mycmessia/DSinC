expr.out: main.o expression.o stack.o
	gcc $^ -o $@

main.o: expression.h
expression.o: expression.h stack.h
stack.o: stack.h

clean:
	-rm *.o
.PHONY: clean
