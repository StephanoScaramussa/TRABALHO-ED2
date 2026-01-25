#ifndef ALGORITMOS_H
#define ALGORITMOS_H

double bolha(int vet[], int size, int* troc, int* compare);
double bolhaParada(int vet[], int size, int* troc, int* compare);
double insercaoDireta(int vet[], int size, int* troc, int* compare);
double insercaoBinaria(int vet[], int size, int* troc, int* compare);
double insercaoTernaria(int vet[], int size, int* troc, int* compare);
double shellSort(int vet[], int size, int* troc, int* compare);
double selectionSort(int vet[], int size);
double heapSort(int vet[], int size);
void criaHeap(int vet[], int ini, int fim);
int calculoMediana(int vet[], int esq, int dir);
double quickSortCentro(int vet[], int esq, int dir);
double quickSortFim(int vet[], int esq, int dir);
double quickSortMediana(int vet[], int esq, int dir);
void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo); 
double margeSort(int vet[], int ini, int fim);
void intercalarMarge(int vet[], int ini, int meio, int fim);
double radixSort(int vet[], int size);
int getMax(int vet[], int n);
void countSort(int vet[], int n, int exp);
double bucketSort(int vet[], int size);


#endif