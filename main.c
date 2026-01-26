#include "Algoritmos.h"
#include "GeradorNumeros.h"

int main() {
    int* dados[ORDS][TAMS];
    int* copia[ORDS][TAMS];
    unsigned long troca = 0, comparacao = 0;
    geraMatriz(dados);
    int opcao;
    do {
        copiaMatriz(copia, dados);
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:{ // Algoritmo Bolha
                int opcao2;
                do {
                    printf("\n=== ALGORITMOS RELACIONADOS ===\n");
                    printf("1. Gerar tabela de todos os testes (demorado!)\n");
                    printf("2. Gerar um vetor de tamanho predefinido\n");
                    printf("0. Voltar ao Menu Principal\n");
                    printf("Escolha: ");
                    scanf("%d", &opcao2);
                    switch(opcao2){
                        case 1:{
                            int tams[3] = {TAM1, TAM2, TAM3};
                            char *tipos[3] = {"Aleatorio", "Crescente", "Decrescente"};
                            double tempo;
                            FILE *arquivo = fopen("bubble_sort.csv", "w");
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
                            printf("\nTamanho do vetor a ser gerado: ");
                            scanf("%d", &size_);
                            printf("1 - Aleatorio\n2 - Crescente\n3 - Decrescente\n0 - Cancelar\n");
                            printf("Escolha: ");
                            scanf("%d", &opcao3);
                            switch(opcao3){
                                case 1: {
                                    int *vet = geraVetorAleatorio(size_);
                                    double t = bolha(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha - Aleatorio %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 2: {
                                    int *vet = geraVetorCresc(size_);
                                    double t = bolha(vet, size_, &troca, &comparacao);
                                    FILE *arquivo = fopen("saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha - Crescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
                                    }
                                    free(vet);
                                    opcao2 = 0;
                                    break;
                                }
                                case 3: {
                                    int *vet = geraVetorDecresc(size_);
                                    double t = bolha(vet, size_, &troca, &comparacao);
                                    
                                    FILE *arquivo = fopen("saida.txt", "w");
                                    if (arquivo) {
                                        fprintf(arquivo, "Bolha - Decrescente %d:\n", size_);
                                        for(int i=0; i<size_; i++) fprintf(arquivo, "%d\n", vet[i]);
                                        fprintf(arquivo, "Tempo: %.3f | Trocas: %lu | Comp: %lu", t, troca, comparacao);
                                        fclose(arquivo);
                                        printf("Arquivo gerado com sucesso!\n");
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
            case 2:
                printf("\n[2] Executando Selection Sort...\n");
                // selectionSort(copia, tamanho);
                break;
            case 3:
                printf("\n[3] Executando Insertion Sort...\n");
                // insertionSort(copia, tamanho);
                break;
            case 4:
                printf("\n[4] Executando Merge Sort...\n");
                // mergeSort(copia, 0, tamanho - 1);
                break;
            case 5:
                printf("\n[5] Executando Quick Sort...\n");
                // quickSort(copia, 0, tamanho - 1);
                break;
            case 6:
                printf("\n[6] Executando Heap Sort...\n");
                // heapSort(copia, tamanho);
                break;
            case 7:
                printf("\n[7] Executando Shell Sort...\n");
                // shellSort(copia, tamanho);
                break;
            case 8:
                printf("\n[8] Executando Counting Sort...\n");
                // countingSort(copia, tamanho);
                break;
            case 9:
                printf("\n[9] Executando Radix Sort...\n");
                // radixSort(copia, tamanho);
                break;
            case 10:
                printf("\n[10] Executando Bucket Sort...\n");
                // bucketSort(copia, tamanho);
                break;
            case 11:
                printf("\n[11] Executando Cocktail Shaker Sort...\n");
                // cocktailSort(copia, tamanho);
                break;
            case 12:
                printf("\n[12] Executando Gnome Sort...\n");
                // gnomeSort(copia, tamanho);
                break;
            case 13:
                printf("\n[13] Executando Comb Sort...\n");
                // combSort(copia, tamanho);
                break;
            case 14:
                printf("\n[14] Executando TimSort...\n");
                // timSort(copia, tamanho);
                break;
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