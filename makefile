all: main
	./main

main: main.o Algoritmo.o GeradorValores.o
	gcc main.o Algoritmo.o GeradorValores.o

main.o: main.c
	gcc -c main.c

Algoritmo.o: Algoritmo.c
	gcc - c Algoritmo.c

GeradorValores.o:
	gcc -c 