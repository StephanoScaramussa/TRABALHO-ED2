#ifndef INPUTDADOS_H
#define INPUTDADOS_H

#define TAM1 10000
#define TAM2 100000
#define TAM3 500000
#define ORDS 3
#define TAMS 3


int ENumerico(const char* str);
int ValidaInput(const char* str, int ini, int fim);
void geraMatriz(int *matriz[ORDS][TAMS]);
void copiaMatriz(int *destino[ORDS][TAMS], int *origem[ORDS][TAMS]);
void liberaMatriz(int *matriz[ORDS][TAMS]);

#endif