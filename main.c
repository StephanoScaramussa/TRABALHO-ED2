#include "Algoritmos.h"
#include <stdio.h>

int main(void){
    int vet[5] = {4,1,1,5,7};

    bolha(vet);
    

    for(int i = 0; i < 3; i++){
        printf("%i", vet[i]);
    }

    return 0;
}