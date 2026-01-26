#include "GeradorNumeros.h"


void geraNumeros(int size){
    int opcao;
    do{
        printf("\n--- MENU ---\n");
        printf("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                for(int i=0; i<size; i++){
                    printf("%d ", rand() % 100);
                }
                printf("\n");
                break;
            case 2: {
                int temp = 0; 
                for(int i = 0; i < size; i++){
                    int num;
                    if(i == 0) {
                        num = rand() % 100;
                    } else {
                        num = temp + (rand() % 100) + 1;
                    }
                    printf("%d ", num);
                    temp = num; 
                }
                printf("\n");
                break;
            }
            case 3: {
                int temp = 0; 
                for(int i = 0; i < size; i++){
                    int num;
                    if(i == 0) {
                        num = 500 + (rand() % 500); 
                    } else {
                        num = temp - (rand() % 100 + 1); 
                    }    
                    if(num < 0) num = 0; 
                    printf("%d ", num);
                    temp = num;
                }
                printf("\n");
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while(opcao != 0);
}

int* geraVetorAleatorio(int size){
    int *vet = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        vet[i] = rand() % 100;
    }
    return vet;
}

int* geraVetorCresc(int size){
    srand(time(NULL));
    int *vet = (int*) malloc(size * sizeof(int));
    vet[0] = rand() % 10; 
    for (int i = 1; i < size; i++) {
        vet[i] = vet[i-1] + (rand() % 10) + 1;
    }  
    return vet;
}

int* geraVetorDecresc(int size) {
    srand(time(NULL));
    int *vet = (int*) malloc(size * sizeof(int));
    vet[0] = 9999999 + (rand() % 10); 
    for (int i = 1; i < size; i++) {
        vet[i] = vet[i-1] - (rand() % 10) - 1;
    }
    return vet;
}