#ifndef ALGORITMOS_H
#define ALGORITMOS_H

void bolha(int vet[], int size);
void bolhaParada(int vet[], int size);
void insercaoDireta(int vet[], int size);
void insercaoBinaria(int vet[], int size);
void insercaoTernaria(int vet[], int size);
void shellSort(int vet[], int size);
void selectionSort(int vet[], int size);
void heapSort(int vet[], int size);
void criaHeap(int vet[], int ini, int fim);
int calculoMediana(int vet[], int esq, int dir);
void quickSortCentro(int vet[], int esq, int dir);
void quickSortFim(int vet[], int esq, int dir);
void quickSortMediana(int vet[], int esq, int dir);
void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo); 
void margeSort(int vet[], int ini, int fim);
void intercalarMarge(int vet[], int ini, int meio, int fim);
void radixSort(int vet[], int size);
int getMax(int vet[], int n);
void countSort(int vet[], int n, int exp);
void bucketSort(int vet[], int size);


#endif