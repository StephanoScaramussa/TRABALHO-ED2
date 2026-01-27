#include "Algoritmos.h"

double bolha(int vet[], int size, unsigned long* troc, unsigned long* compare){
    *troc = 0;
    *compare = 0;
    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int auxiliar;
    int i, j;
    for (i = size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            *compare += 1;
            if (vet[j] > vet[j + 1]) {
                *troc += 1;
                auxiliar = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = auxiliar;
            }
        }
    }
    fim = clock();
    temp =  (double)(fim - inicio)/CLOCKS_PER_SEC;
    return temp;
}

double bolhaParada(int vet[], int size, unsigned long* troc, unsigned long* compare){
    *troc = 0;
    *compare = 0;
    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int indice = size - 1;
    bool mudou = true;
    while(mudou){
        int j = 1;
        mudou = false;
        while(j < size){
            *compare += 1;
            if(vet[j-1] > vet[j]){
                *troc += 1;
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
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return temp;
}

double insercaoDireta(int vet[], int size, unsigned long* troc, unsigned long* compare){
    *troc = 0;
    *compare = 0;
    clock_t inicio, fim;
    double temp;

    inicio = clock();
    for (int i = 1; i < size; i++) {
        int chave = vet[i];
        int j = i - 1;
        while (j >= 0) {
            *compare += 1;
            if(vet[j] > chave){
                *troc += 1;
                vet[j + 1] = vet[j];
                j--;
            }else{
                break;
            }
        }

        vet[j + 1] = chave;
    }
    *compare += 1;
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return temp;
}

double insercaoBinaria(int vet[], int size, unsigned long* troc, unsigned long* compare){
    *troc = 0;
    *compare = 0;
    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int auxiliar, esq, dir, meio;
    for (int i = 1; i < size; i++) {
        auxiliar = vet[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            meio = (esq + dir) / 2;
            *compare += 1;
            if (auxiliar > vet[meio]){
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }
        }

        for (int j = i; j > esq; j--) {
            *troc += 1;
            vet[j] = vet[j - 1];
        }

        vet[esq] = auxiliar;
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double insercaoTernaria(int vet[], int size, unsigned long* troc, unsigned long* compare){
    *troc = 0;
    *compare = 0;

    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int auxiliar, esq, dir, m1, m2;
    for (int i = 1; i < size; i++) {
        auxiliar = vet[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            m1 = esq + (dir - esq) / 3;
            m2 = dir - (dir - esq) / 3;

            *compare += 1;
            if (auxiliar < vet[m1]) {
                dir = m1 - 1;
            } 
            else{
                *compare += 1;
                if (auxiliar > vet[m2]) {
                    esq = m2 + 1;
                } 
                else {
                    esq = m1 + 1;
                    dir = m2 - 1;
                }
            }
        }

        for (int j = i; j > esq; j--) {
            *troc += 1;
            vet[j] = vet[j - 1];
        }

        vet[esq] = auxiliar;
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double shellSort(int vet[], int size, unsigned long* troc, unsigned long* compare) {
    *compare = 0;
    *troc = 0;

    clock_t inicio, fim;
    double tempo;

    int h = 1, auxiliar, j;

    while (h < size) {
        h = 3 * h + 1;
    }

    inicio = clock();

    while (h > 1) {
        h = h / 3;

        for (int i = h; i < size; i++) {
            auxiliar = vet[i];
            j = i - h;

            while (j >= 0) {
                (*compare)++;               
                if (auxiliar < vet[j]) {
                    vet[j + h] = vet[j];
                    (*troc)++;                 
                    j -= h;
                } else {
                    break;
                }
            }
            vet[j + h] = auxiliar;             
        }
    }

    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    return tempo;
}

double selectionSort(int vet[], int size, unsigned long* troc, unsigned long* compare){
    *troc = 0;
    *compare = 0;

    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int min, aux;
    for (int i = 0; i < size - 1; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            *compare += 1;              
            if (vet[j] < vet[min]) {
                min = j;
            }
        }

        if (min != i) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
            *troc += 1;                   
        }
    }
    fim = clock();

    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return temp;
}

void criaHeap(int vet[], int ini, int fim, int *troc, int* compare){
    int auxiliar = vet[ini];
    int j = ini*2 + 1;

    while(j <= fim){
        //*compare += 1;
        if(j < fim){
            *compare += 1;
            if(vet[j] < vet[j + 1]){
                j += 1;
            }
        }
        if(auxiliar < vet[j]){
            *troc += 1;
            vet[ini] = vet[j];
            ini = j;
            j = 2*ini + 1;   
        }else{
            j = fim + 1;
        }
    }
    vet[ini] = auxiliar;
}

double heapSort(int vet[], int size, int* troc, int* compare){
    *troc = 0;
    *compare = 0;

    clock_t inicio, fim;
    double temp;

    inicio = clock();
    int aux;
    for(int i = (size - 1)/2; i >= 0; i--){
        criaHeap(vet, i, size - 1, troc, compare);
    }

    for(int i = size - 1; i > 0; i--){
        *troc += 1;
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;

        criaHeap(vet, 0, i - 1, troc, compare);
    }
    fim = clock();

    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;
    return temp;
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

void particaoQuick(int* dados, int esq, int dir, int *i, int *j, int posiPivo, int* troc, int* compare){
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

        while(*i < dir){
            *compare += 1;
            if (dados[*i] < pivo ){
                (*i)++;
            }
            else{
                break;
            }
        }

        *compare += 1;
        while(*j > esq){
            compare += 1;
            if(dados[*j] > pivo){
                (*j)--;
            }else{
                break;
            }
        }

        if(*i <= *j){
            *troc += 1;
            aux = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

double quickSortCentro(int vet[], int esq, int dir, int *troc, int* compare){
    clock_t inicio, fim;
    double temp;
    
    inicio = clock();
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, 1, troc, compare);

    if(i < dir){
        quickSortCentro(vet, i, dir, troc, compare);
    }
    if(j > esq){
        quickSortCentro(vet, esq, j, troc, compare);
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double quickSortFim(int vet[], int esq, int dir, int* troc, int* compare){ 
    clock_t inicio, fim;
    double temp;
    
    inicio = clock();
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, 2, troc, compare);

    if(i < dir){
        quickSortFim(vet, i, dir, troc, compare);
    }
    if(j > esq){
        quickSortFim(vet, esq, j, troc, compare);
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double quickSortMediana(int vet[], int esq, int dir, int* troc, int* compare){ 
    clock_t inicio, fim;
    double temp;
    
    inicio = clock();
    int i, j;

    //i e j como estão sendo passados como referência, receberam seus repectivos valores 
    particaoQuick(vet, esq, dir, &i, &j, 3, troc, compare);

    if(i < dir){
        quickSortMediana(vet, i, dir, troc, compare);
    }
    if(j > esq){
        quickSortMediana(vet, esq, j, troc, compare);
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
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

double margeSort(int vet[], int ini, int fim){
    clock_t inicio, end;
    double temp;
    
    inicio = clock();
    int meio;
    
    if (ini < fim){  
        meio = (ini + fim)/2;
        margeSort(vet, ini, meio);
        margeSort(vet, meio + 1, fim);
        intercalarMarge(vet, ini, meio, fim);
    }
    end = clock();
    temp = (double)(end - inicio)/CLOCKS_PER_SEC;

    return temp;
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


double radixSort(int vet[], int size){
    clock_t inicio, fim;
    double temp;
    
    inicio = clock();
    int maximo = getMax(vet, size);

    for(int exp = 1; maximo/exp > 0; exp *= 10){
        countSort(vet, size, exp);
    }
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}

double bucketSort(int vet[], int size) {
    clock_t inicio, fim;
    double temp;
    
    inicio = clock();
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
            insercaoDireta(buckets[i], count[i], NULL, NULL);
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
    fim = clock();
    temp = (double)(fim - inicio)/CLOCKS_PER_SEC;

    return temp;
}