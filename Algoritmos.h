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
void quickSort(int vet[], int esq, int dir, int posiPivo);//pivo = 1 (centro); pivo = 2 (ultimo); pivp = 3 (mediana) 
void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo); 
void margeSort(int vet[], int size);
void radixSort(int vet[]);
void bucketSort(int vet[]);


#endif