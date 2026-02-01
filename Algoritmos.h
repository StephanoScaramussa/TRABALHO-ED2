#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define TAM1 10000
#define TAM2 100000
#define TAM3 500000
#define ORDS 3
#define TAMS 3

void geraMatriz(int *matriz[ORDS][TAMS]);
void copiaMatriz(int *destino[ORDS][TAMS], int *origem[ORDS][TAMS]);
void liberaMatriz(int *matriz[ORDS][TAMS]);
double bolha(int vet[], int size, unsigned long* troc, unsigned long* compare);
double bolhaParada(int vet[], int size, unsigned long* troc, unsigned long* compare);
double insercaoDireta(int vet[], int size, unsigned long* troc, unsigned long* compare);
double insercaoBinaria(int vet[], int size, unsigned long* troc, unsigned long* compare);
double insercaoTernaria(int vet[], int size, unsigned long* troc, unsigned long* compare);
double shellSort(int vet[], int size, unsigned long* troc, unsigned long* compare);
double selectionSort(int vet[], int size, unsigned long* troc, unsigned long* compare);
double heapSort(int vet[], int size, unsigned long* troc, unsigned long* compare);
void criaHeap(int vet[], int ini, int fim, unsigned long* troc, unsigned long* compare);
int calculoMediana(int vet[], int esq, int dir);
double quickSortCentro(int vet[], int esq, int dir, unsigned long* troc, unsigned long* compare);
double quickSortFim(int vet[], int esq, int dir, unsigned long* troc, unsigned long* compare);
double quickSortMediana(int vet[], int esq, int dir, unsigned long* troc, unsigned long* compare);
void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo, unsigned long* troc, unsigned long* compare); 
double margeSort(int vet[], int ini, int fim, unsigned long* troc, unsigned long* compare);
void intercalarMarge(int vet[], int ini, int meio, int fim, unsigned long* troc, unsigned long* compare);
double radixSort(int vet[], int size, unsigned long* troc, unsigned long* compare);
int getMax(int vet[], int n);
void countSort(int vet[], int n, int exp, unsigned long* troc);
double bucketSort(int vet[], int size, unsigned long* troc, unsigned long* compare);
void mostrarMenu();


#endif