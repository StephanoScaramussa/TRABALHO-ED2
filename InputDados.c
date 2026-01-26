#include "InputDados.h"
#include "GeradorNumeros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ENumerico(const char* str){
    for (int i = 0; i < strlen(str); i ++){
        if(!isdigit((unsigned char) str[i])){
            return 0;
        }
    }
    return 1;
}

int ValidaInput(const char* str, int ini, int fim){
    char op[100];
    int numop = 0;
    
    while(1){
        printf("%s", str);
        fgets(op, sizeof(op), stdin);
        system("cls");

        op[strcspn(op, "\n")] = 0;
        
        if (ENumerico(op)) {
            numop = atoi(op);
            if (numop >= ini && numop <= fim) {
                return numop;
            }
        }
    }
}

void geraMatriz(int *matriz[ORDS][TAMS]) {
    int tamanhos[3] = {TAM1, TAM2, TAM3};
    for (int j = 0; j < 3; j++) {
        matriz[0][j] = geraVetorAleatorio(tamanhos[j]);
        matriz[1][j] = geraVetorCresc(tamanhos[j]);
        matriz[2][j] = geraVetorDecresc(tamanhos[j]);
    }
}

void copiaMatriz(int *destino[ORDS][TAMS], int *origem[ORDS][TAMS]) {
    int tams[3] = {TAM1, TAM2, TAM3};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int N = tams[j];
            destino[i][j] = (int*) malloc(N * sizeof(int));
            if (destino[i][j] != NULL && origem[i][j] != NULL) {
                memcpy(destino[i][j], origem[i][j], N * sizeof(int));
            }
        }
    }
}

void liberaMatriz(int *matriz[ORDS][TAMS]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] != NULL) {
                free(matriz[i][j]);
                matriz[i][j] = NULL;
            }
        }
    }
}