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

void quickSortCentro(int vet[], int esq, int dir){ 
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, 1);

    if(i < dir){
        quickSortCentro(vet, i, dir);
    }
    if(j > esq){
        quickSortCentro(vet, esq, j);
    }
}

void quickSortFim(int vet[], int esq, int dir){ 
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, 2);

    if(i < dir){
        quickSortFim(vet, i, dir);
    }
    if(j > esq){
        quickSortFim(vet, esq, j);
    }
}

void quickSortMediana(int vet[], int esq, int dir){ 
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, 3);

    if(i < dir){
        quickSortMediana(vet, i, dir);
    }
    if(j > esq){
        quickSortMediana(vet, esq, j);
    }
}

void intercalarMarge(int vet[], int ini, int meio, int fim){
    int i = ini;
    int j = meio + 1;
    int k = 0;

    int *tmp = (int*) malloc((fim - ini + 1) * sizeof(int));

    while (i <= meio || j <= fim) {
        if (i == meio + 1)
            tmp[k++] = vet[j++];
        else if (j == fim + 1)
            tmp[k++] = vet[i++];
        else if (vet[j] < vet[i])
            tmp[k++] = vet[j++];
        else
            tmp[k++] = vet[i++];
    }

    for (i = ini, k = 0; i <= fim; i++, k++) {
        vet[i] = tmp[k];
    }

    free(tmp);
}

void margeSort(int vet[], int ini, int fim){
    int meio;
    
    if (ini < fim){  
        meio = (ini + fim)/2;
        margeSort(vet, ini, meio);
        margeSort(vet, meio + 1, fim);
        intercalarMarge(vet, ini, meio, fim);
    }
}

int getMax(int vet[], int n){
    int max = vet[0];
    for (int i = 1; i < n; i++){
        if (vet[i] > max){
            max = vet[i];
        }
    }
    return max;
}

void countSort(int vet[], int n, int exp){
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(vet[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(vet[i] / exp) % 10] - 1] = vet[i];
        count[(vet[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        vet[i] = output[i];
}


void radixSort(int vet[], int size){
    int maximo = getMax(vet, size);

    for(int exp = 1; maximo/exp > 0; exp *= 10){
        countSort(vet, size, exp);
    }
}

void bucketSort(int vet[], int size) {
    int max = vet[0];

    for (int i = 1; i < size; i++) {
        if (vet[i] > max)
            max = vet[i];
    }

    int **buckets = (int **)malloc(size * sizeof(int *));
    int *count = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int indice = (size * vet[i]) / (max + 1);
        buckets[indice][count[indice]++] = vet[i];
    }

    for (int i = 0; i < size; i++) {
        if (count[i] > 0) {
            insercaoDireta(buckets[i], count[i]);
        }
    }

    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < count[i]; j++) {
            vet[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(count);
}