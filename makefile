all: compila
compila: main.o Algoritmos.o
	gcc main.o Algoritmos.o -o result.exe
	./result.exe

main.o: main.c
	gcc -c main.c

Algoritmos.o: Algoritmos.c
	gcc -c Algoritmos.c

clean: 
	rm main.o Algoritmos.o result.exe