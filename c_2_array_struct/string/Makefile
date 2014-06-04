string.out: main.o string.o kmp.o
	gcc  $^ -o $@

main.o: string.h kmp.h
string.o: string.h
kmp.o: 

clean:
	-rm string.out *.o

.PHONY: clean
