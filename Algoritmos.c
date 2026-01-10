#include "Algoritmos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bolha(int vet[], int size){
    int auxiliar;
    int i, j;

    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                auxiliar = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = auxiliar;
            }
        }
    }
}

void bolhaParada(int vet[], int size){
    int indice = size - 1;
    bool mudou = true;
    while(mudou){
        int j = 1;
        mudou = false;
        while(j < size){
            if(vet[j-1] > vet[j]){
                int auxiliar = vet[j - 1];
                vet[j - 1] = vet[j];
                vet[j] = auxiliar;
                mudou = true;
            }
            indice = j;
            j = j + 1;
        }
        size = indice;
    }
}

void insercaoDireta(int vet[], int size){
    for (int i = 1; i < size; i++) {
        int chave = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j--;
        }

        vet[j + 1] = chave;
    }
}

void insercaoBinaria(int vet[], int size) {
    int auxiliar, esq, dir, meio;

    for (int i = 1; i < size; i++) {
        auxiliar = vet[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            meio = (esq + dir) / 2;
            if (vet[meio] <= auxiliar) {
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }

        for (int j = i; j > esq; j--) {
            vet[j] = vet[j - 1];
        }

        vet[esq] = auxiliar;
    }
}

void insercaoTernaria(int vet[], int size) {
    int auxiliar, esq, dir, m1, m2;

    for (int i = 1; i < size; i++) {
        auxiliar = vet[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            m1 = esq + (dir - esq) / 3;
            m2 = dir - (dir - esq) / 3;

            if (auxiliar < vet[m1]) {
                dir = m1 - 1;
            } 
            else if (auxiliar > vet[m2]) {
                esq = m2 + 1;
            } 
            else {
                esq = m1 + 1;
                dir = m2 - 1;
            }
        }

        for (int j = i; j > esq; j--) {
            vet[j] = vet[j - 1];
        }

        vet[esq] = auxiliar;
    }
}

void shellSort(int vet[], int size){
    int h, auxiliar, j;
    h = 1;  
    while(h < size){
        h = 3*h + 1;
    }
    while(h > 1){
        h = h/3;
        for(int i = h; i <= size; i++){
            auxiliar = vet[i];
            j = i - h;
            while((j >= 0) && (auxiliar < vet[j])){
                vet[j + h] = vet[j];
                j -= h;
            }
            vet[j + h] = auxiliar;
        }
    }
}