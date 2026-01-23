#include "Algoritmos.h"
#include <stdio.h>

int main(void){
    int vet[9] = {4,1,0,5,7,10,34,6,32};

    //pivo -> começo 
    double tempo = bolha(vet, 9);
    printf("Tempo: %.15f", tempo);

    for(int i = 0; i < 9; i++){
        printf("[%i]", vet[i]);
    }

    return 0;
}