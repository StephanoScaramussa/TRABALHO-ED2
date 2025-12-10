#include "Algoritmos.h"
#include <stdio.h>
#include <stdlib.h>

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



