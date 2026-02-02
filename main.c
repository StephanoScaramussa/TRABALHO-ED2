#include "Algoritmos.h"
#include "GeradorNumeros.h"
#include "InputDados.h"

int main() {
    int* dados[ORDS][TAMS];
    int* copia[ORDS][TAMS];
    geraMatriz(dados);
    int opcao;
    do {
        copiaMatriz(copia, dados);
        unsigned long troca = 0, comparacao = 0;
        opcao = ValidaInput("\n=== MENU DE ALGORITMOS DE ORDENACAO ===\n1.  Bolha\n2.  Bolha crit. de parada\n3.  Insercao direta\n4.  Insercao binaria\n5.  Insercao ternaria\n6.  Shell Sort\n7.  Selection Sort\n8.  Heap Sort\n9.  Quicksort centro\n10. Quicksort fim\n11. Quicksort mediana\n12. Merge Sort\n13. Radix Sort\n14. Bucket Sort\n0.  Sair\n=======================================\nEscolha uma opcao: ", 0, 14);
        switch (opcao) {
            case 1:{ // Algoritmo Bolha
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/bubble_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = bolha(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = bolha(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = bolha(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = bolha(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 2:{ // Algoritmo Bolha crit. de Parada
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/bubble_crit_parada.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = bolhaParada(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = bolhaParada(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha crit. de parada - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = bolhaParada(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha crit. de parada - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = bolhaParada(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha crit. de parada - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 3:{ // Algoritmo Insercao direta
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/insercao_direta.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = insercaoDireta(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = insercaoDireta(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao direta - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = insercaoDireta(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao direta - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = insercaoDireta(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao direta - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 4:{ // Algoritmo Insercao binaria
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/insercao_binaria.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = insercaoBinaria(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = insercaoBinaria(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao binaria - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = insercaoBinaria(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao binaria - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = insercaoBinaria(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao binaria - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 5:{ // Algoritmo Insercao ternaria
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/insercao_ternaria.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = insercaoTernaria(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = insercaoTernaria(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao ternaria - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = insercaoTernaria(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao ternaria - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = insercaoTernaria(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Insercao ternaria - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 6:{ // Algoritmo Shellsort
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/shell_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = shellSort(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = shellSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Shell Sort - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = shellSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Shell Sort - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = shellSort(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Shell Sort - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 7:{ // Algoritmo Selection Sort
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/selection_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = selectionSort(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = selectionSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Selection Sort - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = selectionSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Selection Sort - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = selectionSort(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Selection Sort - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 8:{ // Algoritmo Heap sort
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/heap_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = heapSort(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = heapSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Heap Sort - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = heapSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Heap Sort - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = heapSort(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Heap Sort - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 9:{ // Algoritmo Quicksort Centro
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/quicksort_centro.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;

                                    tempo = quickSortCentro(copia[i][j], 0, tams[j]-1, &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = quickSortCentro(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "QuickSort Centro - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = quickSortCentro(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "QuickSort Centro - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = quickSortCentro(vet, 0, size_-1, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "QuickSort Centro - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 10:{ // Algoritmo Quicksort Fim
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/quicksort_fim.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = quickSortFim(copia[i][j], 0, tams[j]-1, &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = quickSortFim(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Quicksort Fim - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = quickSortFim(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Quicksort Fim - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = quickSortFim(vet, 0, size_-1, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Quicksort Fim - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 11:{ // Algoritmo Quicksort Mediana
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/quicksort_mediana.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = quickSortMediana(copia[i][j], 0, tams[j]-1, &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = quickSortMediana(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Quicksort Mediana - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = quickSortMediana(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Quicksort Mediana - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = quickSortMediana(vet, 0, size_-1, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Quicksort Mediana - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 12:{ // Algoritmo Merge Sort
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/merge_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = margeSort(copia[i][j], 0, tams[j]-1, &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = margeSort(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "MergeSort - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = margeSort(vet, 0, size_-1, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "MergeSort - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = margeSort(vet, 0, size_-1, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "MergeSort - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 13:{ // Algoritmo RadixSort
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/radix_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = radixSort(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = radixSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "RadixSort - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = radixSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "RadixSort - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = radixSort(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "RadixSort - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 14:{ // Algoritmo BucketSort
                int opcao2;
                do {
                    opcao2 = ValidaInput("\n=== ALGORITMOS RELACIONADOS ===\n1. Gerar tabela de todos os testes (demorado!)\n2. Gerar um vetor de tamanho predefinido\n0. Voltar ao Menu Principal\nEscolha: ", 0, 2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("arquivos_saida/bucket_sort.csv", "w");
                            if (arquivo == NULL) {
                                printf("Erro ao criar arquivo CSV!\n");
                                break;
                            }
                            fprintf(arquivo, "Tamanho"); 
                            for (int k = 0; k < 3; k++) {
                                fprintf(arquivo, ";%s_Tempo(s);%s_Trocas;%s_Comp", tipos[k], tipos[k], tipos[k]);
                            }
                            fprintf(arquivo, "\n");
                            for (int j = 0; j < 3; j++) {
                                fprintf(arquivo, "%d", tams[j]);
                                for (int i = 0; i < 3; i++) {
                                    unsigned long troca = 0, comparacao = 0;
                                    tempo = bucketSort(copia[i][j], tams[j], &troca, &comparacao);
                                    printf("\n[%s] - Tamanho %d:\n", tipos[i], tams[j]);
                                    printf("Tempo: %.4f s | Trocas: %lu | Comp: %lu\n", tempo, troca, comparacao);
                                    fprintf(arquivo, ";%.3f;%lu;%lu", tempo, troca, comparacao);
                                }
                                fprintf(arquivo, "\n");
                            }
                            fclose(arquivo);
                            opcao2 = 0;
                            break;
                        }
                        case 2: {
                            int opcao3, size_;
                            size_ = ValidaInput("\nTamanho do vetor a ser gerado: ", 1, 1000000);
                            opcao3 = ValidaInput("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\nEscolha: ", 1, 3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = bucketSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "BucketSort - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = bucketSort(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "BucketSort - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = bucketSort(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("arquivos_saida/saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "BucketSort - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                        system("sleep 2");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 0:
                                    printf("Cancelando...\n");
                                    break;
                                default:
                                    printf("Opcao invalida!\n");
                            }
                            break;
                        }
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while(opcao2 != 0);
                break;
            }
            case 0:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
        if (opcao != 0) liberaMatriz(copia);
    } while (opcao != 0);
    liberaMatriz(dados);
    return 0;
}
