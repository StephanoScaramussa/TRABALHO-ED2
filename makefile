all: main
	./main

main: main.o Algoritmos.o GeradorNumeros.o
	gcc main.o Algoritmos.o GeradorNumeros.o -o main

main.o: main.c
	gcc -c main.c

Algoritmos.o: Algoritmos.c
	gcc -c Algoritmos.c

GeradorNumeros.o: GeradorNumeros.c
	gcc -c GeradorNumeros.c

clean:
	rm -f main main.o Algoritmos.o GeradorNumeros.o