#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(ChaveValor arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam-1; j++) {
            if (arr[j].chave < arr[j + 1].chave) {
                ChaveValor aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

void insertionsort(ChaveValor arr[], int tam) {
    for (int i = 1; i < tam; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j - 1].chave < arr[j].chave) {
                ChaveValor aux = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = aux;
            }
        }
    }
}

// Function to get the largest element from an array
int getMax(ChaveValor arr[], int n) {
    int max = arr[0].chave;
    for (int i = 1; i < n; i++)
        if (arr[i].chave > max)
            max = arr[i].chave;
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(ChaveValor arr[], int tam, int place, ChaveValor output[], int count[]) {
    int max = (arr[0].chave / place) % 10;

    for (int i = 1; i < tam; i++) {
        if (((arr[i].chave / place) % 10) > max)
            max = arr[i].chave;
    }

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < tam; i++) {
        count[9 - ((arr[i].chave / place) % 10)]++; // 9 - pos
    }
        
    // Calculate cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = tam - 1; i >= 0; i--) {
        output[count[9 - (arr[i].chave / place) % 10] - 1] = arr[i]; // 9 - pos
        count[9 - (arr[i].chave / place) % 10]--; // 9 - pos
    }

    for (int i = 0; i < tam; i++)
        arr[i] = output[i];
}

void radixsortORG(ChaveValor arr[], int tam, ChaveValor output[], int count[]) {
    // Get maximum element
    int max = getMax(arr, tam);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, tam, place, output, count);
}

void shellsort(ChaveValor arr[], int n){
    int i, j, h;
    ChaveValor aux;
    for (h = 1; h < n; h = 3 * h + 1); /* calcula o h inicial. */
    while (h > 0) {
        h = (h - 1) / 3; /* atualiza o valor de h. */
        for (i = h; i < n; i++) {
            aux = arr[i];
            j = i;
            /* efetua compara��es entre elementos com dist�ncia h: */
            while (arr[j - h] .chave < aux.chave) {
                arr[j] = arr[j - h];
                j -= h;
                if (j < h) break;
            }
            arr[j] = aux;
        }
    }
}

void mergeaux(ChaveValor arr[], ChaveValor c[], int i, int m, int f) {
    int z, iv = i, ic = m + 1;
    for (z = i; z <= f; z++) {
        c[z] = arr[z];
    }
    z = i;

    while (iv <= m && ic <= f) {
        if (c[iv].chave >= c[ic].chave) {
            arr[z++] = c[iv++];
        }
        else {
            arr[z++] = c[ic++];
        }
    }

    while (iv <= m) {
        arr[z++] = c[iv++];
    }

    while (ic <= f) {
        arr[z++] = c[ic++];
    }
}

void mergesortaux(ChaveValor arr[], ChaveValor c[], int i, int f) {
    if (i < f) {
        int m = (i + f) / 2;
        mergesortaux(arr, c, i, m);
        mergesortaux(arr, c, m+1, f);
        mergeaux(arr, c, i, m, f);
    }
}

void mergesortORG(ChaveValor arr[], int n, ChaveValor output[]) {
    mergesortaux(arr, output, 0, n - 1);
}

int particaoLI(ChaveValor arr[], int LI, int LS) {
    ChaveValor aux, pivo;
    int e = LI, d = LS;
    pivo = arr[e];
    while (e < d)
    {
        while ((arr[e].chave >= pivo.chave) && (e < LS)) { e++; } // <= para >=
        while ((arr[d].chave < pivo.chave) && (d > LI)) { d--; } // > para <
        if (e < d)
        {
            aux = arr[e];
            arr[e] = arr[d];
            arr[d] = aux;
        }
    }
    aux = arr[LI];
    arr[LI] = arr[d];
    arr[d] = aux;
    return d;
}

void quicksortLI(ChaveValor arr[], int LI, int LS) {
    if (LI < LS)
    {
        int p;
        p = particaoLI(arr, LI, LS);
        quicksortLI(arr, LI, p - 1);
        quicksortLI(arr, p + 1, LS);
    }
}

int particaoLS(ChaveValor arr[], int LI, int LS) {
    ChaveValor aux, pivo;
    int e = LI, d = LS;
    pivo = arr[d]; // troca do pivo
    while (e < d)
    {
        while ((arr[e].chave > pivo.chave) && (e < LS)) { e++; }
        while ((arr[d].chave <= pivo.chave) && (d > LI)) { d--; }
        if (e < d)
        {
            aux = arr[e];
            arr[e] = arr[d];
            arr[d] = aux;
        }
    }
    aux = arr[LS]; // LI para LS
    arr[LS] = arr[e];
    arr[e] = aux;
    return e; // retorna E
}

void quicksortLS(ChaveValor arr[], int LI, int LS) {
    if (LI < LS)
    {
        int p;
        p = particaoLS(arr, LI, LS);
        quicksortLS(arr, LI, p - 1);
        quicksortLS(arr, p + 1, LS);
    }
}

int particaoMEIO(ChaveValor arr[], int LI, int LS) {
    ChaveValor aux, pivo;
    int e = LI, d = LS;
    int mid = (LS+LI)/2;
    pivo = arr[mid]; // pivo do meio
    while (1)
    {
        while ((arr[d].chave < pivo.chave)){ d--; }
        while ((arr[e].chave > pivo.chave)) { e++; }
        
        if (e >= d)
        {
            return d;
        }
        
        aux = arr[d];
        arr[d] = arr[e];
        arr[e] = aux;
        e++;
        d--;
    }
}

void quicksortMEIO(ChaveValor arr[], int LI, int LS) {
    if (LI < LS)
    {
        int p;
        p = particaoMEIO(arr, LI, LS);
        quicksortMEIO(arr, LI, p);
        quicksortMEIO(arr, p + 1, LS);
    }
}

void preencherVetor(ChaveValor arr[], int tam, int seed) {
    for (int i = 0; i < tam; i++) {
        if (seed == 1) {
            clock_t t;
            t = clock();
            srand(t);

            arr[i].chave = 10 + i;
            arr[i].valor = rand() % 100;
        }
        else {
            srand(seed);
            arr[i].chave = rand() % 100;
            arr[i].valor = rand() % 100;
        }
    }
}