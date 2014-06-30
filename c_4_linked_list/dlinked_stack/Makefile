dlinked_stack.out: main.o dlinked_stack.o palindrome.o exp_paren.o
	gcc $^ -o $@

main.o: main.c dlinked_stack.h
	gcc -g -c main.c

dlinked_stack.o: dlinked_stack.c dlinked_stack.h
	gcc -g -c dlinked_stack.c	

palindrome.o: palindrome.c dlinked_stack.h
	gcc -g -c palindrome.c

exp_paren.o: exp_paren.c dlinked_stack.h
	gcc -g -c exp_paren.c

clean:
	-rm *.o
	-rm *.out
.PHONY: clean
