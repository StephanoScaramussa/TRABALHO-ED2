#ifndef ALGORITMOS_H
#define ALGORITMOS_H

void bolha(int vet[], int size);
void bolhaParada(int vet[], int size);
void insercaoDireta(int vet[]);
void insercaoBinaria(int vet[]);
void insercaoTernaria(int vet[]);
void shellSort(int vet[]);
void selectionSort(int vet[]);
void heapSort(int vet[]);
void quickSort(int vet[], int pivo);//pivo = 1 (centro); pivo = 2 (ultimo); pivp = 3 (mediana)  
void margeSort(int vet[]);
void radixSort(int vet[]);
void bucketSort(int vet[]);


#endif