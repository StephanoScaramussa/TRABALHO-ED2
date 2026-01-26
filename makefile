all: main
	./main

main: main.o Algoritmos.o GeradorNumeros.o InputDados.o
	gcc main.o Algoritmos.o GeradorNumeros.o InputDados.o -o main

main.o: main.c
	gcc -c main.c

Algoritmos.o: Algoritmos.c
	gcc -c Algoritmos.c

GeradorNumeros.o: GeradorNumeros.c
	gcc -c GeradorNumeros.c

InputDados.o: InputDados.c
	gcc -c InputDados.c

clean:
	rm -f main main.o Algoritmos.o GeradorNumeros.o InputDados.o saida.txt 