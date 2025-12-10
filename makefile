all: main
	./main

main: main.o Algoritmos.o
	gcc main.o Algoritmos.o -lm -o main

main.o: main.c Algoritmos.h
	gcc -Wall -Werror -c main.c

Algoritmos.o: Algoritmos.c Algoritmos.h
	gcc -Wall -Werror -c Algoritmos.c

clean: 
	rm -f *.o main