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

ifdef OS
   RM = del /Q
   EXT = .exe
   PATH_SAIDA = arquivos_saida\saida.txt
else
   RM = rm -f
   EXT =
   PATH_SAIDA = arquivos_saida/saida.txt
endif

clean:
	$(RM) main$(EXT) main.o Algoritmos.o GeradorNumeros.o InputDados.o
	$(RM) $(PATH_SAIDA)