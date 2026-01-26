#ifndef GERADORNUMEROS_H
#define GERADORNUMEROS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM1 10000
#define TAM2 100000
#define TAM3 500000
#define ORDS 3
#define TAMS 3

void geraNumeros(int size);
int* geraVetorAleatorio(int size);
int* geraVetorCresc(int size);
int* geraVetorDecresc(int size);

#endif