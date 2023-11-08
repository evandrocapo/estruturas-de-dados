// Projeto2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"
#include <time.h>

void executarTesteDezMil(int sort, int seed);
void executarTesteCinquentaMil(int sort, int seed);
void executarTesteCemMil(int sort, int seed);
void executarTesteQuinhentosMil(int sort, int seed);
void executarTesteUmMilhao(int sort, int seed);

int main()
{
    //Bubble Sort
    //executarTesteDezMil(1, 200);
    //executarTesteCinquentaMil(1, 200);


    //Insertion Sort
    //executarTesteDezMil(2, 200);
    //executarTesteCinquentaMil(2, 200);

    //Shell Sort
    //executarTesteDezMil(3, 200);

    //Merge Sort
    //executarTesteDezMil(4, 200);

    //Quick Sort - LI
    //executarTesteDezMil(5, 200);

    //Quick Sort - LS
    //executarTesteDezMil(6, 200);

    //Quick Sort - Meio
    executarTesteDezMil(7, 200);

    //Radix Sort
   // executarTesteDezMil(8, 200);
}

void executarTesteDezMil(int sort, int seed) {
    const int DEZMIL = 10000;
    ChaveValor arrOne[DEZMIL] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, DEZMIL, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[DEZMIL];

        t = clock();
        mergesort(arrOne, DEZMIL, output);
        t = clock() - t;
    }
    else if (sort == 5) {
        t = clock();
        quicksortLI(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 6) {
        t = clock();
        quicksortLS(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 7) {
        t = clock();
        quicksortMEIO(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 8) {
        ChaveValor output[DEZMIL + 1];
        int count[DEZMIL + 1];

        t = clock();
        radixsort(arrOne, DEZMIL, output, count);
        t = clock() - t;
    }

    int deubom = 1;
    for (int i = 0; i < DEZMIL -1; i++) {
        if (arrOne[i].chave < arrOne[i + 1].chave) deubom = 0;
    }

    for (int i = 0; i < DEZMIL; i++) {
        printf("%d ", arrOne[i].chave);
    }

    printf("\ndeu bom: %d", deubom);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("\nO programa levou %f segundo para ordenar\n\n", time_taken);
}

void executarTesteCinquentaMil(int sort, int seed) {
    ChaveValor arrOne[50000] = { 0 };
    clock_t t;
    t = clock();

    if (sort == 1) {
        preencherVetor(arrOne, 50000, seed);
        t = clock();
        bubblesort(arrOne, 50000);
    }
    else if (sort == 2) {
        preencherVetor(arrOne, 50000, seed);
        t = clock();
        insertionsort(arrOne, 50000);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("O programa levou %f segundo para ordenar\n\n", time_taken);
}

void executarTesteCemMil(int sort, int seed) {
    ChaveValor arrOne[100000] = { 0 };
    clock_t t;
    t = clock();

    if (sort == 1) {
        preencherVetor(arrOne, 100000, seed);
        t = clock();
        bubblesort(arrOne, 100000);
    }
    else if (sort == 2) {
        preencherVetor(arrOne, 100000, seed);
        t = clock();
        insertionsort(arrOne, 100000);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("O programa levou %f segundo para ordenar\n\n", time_taken);
}

void executarTesteQuinhentosMil(int sort, int seed) {
    ChaveValor arrOne[500000] = { 0 };
    clock_t t;
    t = clock();

    if (sort == 1) {
        preencherVetor(arrOne, 500000, seed);
        t = clock();
        bubblesort(arrOne, 500000);
    }
    else if (sort == 2) {
        preencherVetor(arrOne, 500000, seed);
        t = clock();
        insertionsort(arrOne, 500000);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("O programa levou %f segundo para ordenar\n\n", time_taken);
}

void executarTesteUmMilhao(int sort, int seed) {
    ChaveValor arrOne[1000000] = { 0 };
    clock_t t;
    t = clock();

    if (sort == 1) {
        preencherVetor(arrOne, 1000000, seed);
        t = clock();
        bubblesort(arrOne, 1000000);
    }
    else if (sort == 2) {
        preencherVetor(arrOne, 1000000, seed);
        t = clock();
        insertionsort(arrOne, 1000000);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    printf("O programa levou %f segundo para ordenar\n\n", time_taken);
}



// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
