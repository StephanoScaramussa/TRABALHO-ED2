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

void selectionSort(int vet[], int size){
    int menor, auxiliar;
    for(int i = 0; i < size - 1; i++){
        menor = i;
        for(int j = i + 1; j < size; j ++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
        }
        if (i != menor){
            auxiliar = vet[i];
            vet[i] = vet[menor];
            vet[menor] = auxiliar;
        }
    }
}

void criaHeap(int vet[], int ini, int fim){
    int auxiliar = vet[ini];
    int j = ini*2 + 1;

    while(j <= fim){
        if(j < fim){
            if(vet[j] < vet[j + 1]){
                j += 1;
            }
        }
        if(auxiliar < vet[j]){
            vet[ini] = vet[j];
            ini = j;
            j = 2*ini + 1;   
        }else{
            j = fim + 1;
        }
    }
    vet[ini] = auxiliar;
}

void heapSort(int vet[], int size){
    int aux;

    for(int i = (size - 1)/2; i >= 0; i--){
        criaHeap(vet, i, size - 1);
    }

    for(int i = size - 1; i > 0; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        criaHeap(vet, 0, i - 1);
    }
}

//calculo da mediana [menor][meio][maior]
int calculoMediana(int vet[], int esq, int dir){
    int meio = (esq + dir)/2;
    int aux = 0;

    if(vet[esq] > vet[meio]){
        aux = vet[esq];
        vet[esq] = vet[meio];
        vet[meio] = aux;
    }

    if(vet[meio] > vet[dir]){
        aux = vet[meio];
        vet[meio] = vet[dir];
        vet[dir] = aux;
    }

    if(vet[meio] < vet[esq]){
        aux = vet[esq];
        vet[esq] = vet[meio];
        vet[meio] = aux;
    }

    return vet[meio];
}

void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo){
    int pivo, aux;
    *i = esq;
    *j = dir;

    switch (posiPivo)
    {
    //pivo = 1 (centro)
    case 1:
        pivo = dados[(esq + dir)/2];
        break;
    //pivo = 2 (último) -> POSSÍVEL PIOR CASO O(n^2)
    case 2:
        pivo = dados[esq];
    case 3:
    //pivo = 3 (mediana)
        pivo = calculoMediana(dados, esq, dir);
    default:
        break;
    }

    while(*i <= *j){
        while(dados[*i] < pivo && *i < dir){
            (*i)++;
        }

        while(dados[*j] > pivo && *j > esq){
            (*j)--;
        }
        if(*i <= *j){
            aux = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSort(int vet[], int esq, int dir, int posiPivo){ 
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, posiPivo);

    if(i < dir){
        quickSort(vet, i, dir, posiPivo);
    }
    if(j > esq){
        quickSort(vet, esq, j, posiPivo);
    }
}

void margeSort(int vet[], int ini, int fim){
    int meio;
    
    if (ini < fim){
        meio = (ini + fim)/2;
        margeSort(vet, ini, fim);
        margeSort(vet, ini, fim);
        intercalarMarge(vet, ini, fim, meio);
    }
}