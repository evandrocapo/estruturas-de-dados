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

    //Radix Sort
    executarTesteDezMil(4, 200);
}

void executarTesteDezMil(int sort, int seed) {
    ChaveValor arrOne[10000] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, 10000, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, 10000);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, 10000);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, 10000);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[10000 + 1];

        t = clock();
        mergesort(arrOne, 10000, output);
        t = clock() - t;
    }
    else if (sort == 6) {
        ChaveValor output[10000 + 1];
        int count[10000 + 1];

        t = clock();
        radixsort(arrOne, 10000, output, count);
        t = clock() - t;
    }

    for (int i = 0; i < 10000; i++) {
        printf("%d ", arrOne[i].chave);
    }

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
