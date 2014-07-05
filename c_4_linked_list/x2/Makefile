x2.out: main.o x2.o
	gcc $^ -o $@

main.o: x2.h
x2.o: x2.h

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
