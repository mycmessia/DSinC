string.out: main.o string.o kmp.o
	gcc  main.o string.o kmp.o -o string.out
main.o: main.c string.h kmp.h
	gcc -c -g main.c
string.o: string.c string.h
	gcc -c -g string.c
kmp.o: kmp.c
	gcc -c -g kmp.c 
