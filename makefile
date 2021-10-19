all: main.o linkedlist.o library.o
	gcc -o main.o mytunes linkedlist.o library.o

main.o: main.c linkedlist.c library.c linkedlist.h library.h
	gcc -c main.c linkedlist.c library.c

linkedlist.c: linkedlist.c linkedlist.h
	gcc -c linkedlist.c 

library.c: library.c library.h
	gcc -c library.c

run:
	./mytunes