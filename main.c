#include "Algoritmos.h"
#include <stdio.h>

int main(void){
    int vet[9] = {-89,1,52,5,631,10,34,6,32};

    //pivo -> começo 
    int troca, comparacao;
    double tempo = insercaoBinaria(vet, 9, &troca, &comparacao);
    printf("Tempo: %.15f", tempo);

    for(int i = 0; i < 9; i++){
        printf("[%i]", vet[i]);
    }

    printf("\nq. troca: %d, q. comparacao: %d", troca, comparacao);
    return 0;
}