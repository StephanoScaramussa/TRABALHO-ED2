#include "Algoritmos.h"
#include <stdio.h>

int main(void){
    int vet[5] = {4,1,0,5,7};

    selectionSort(vet, 5);
    

    for(int i = 0; i < 5; i++){
        printf("%i", vet[i]);
    }

    return 0;
}