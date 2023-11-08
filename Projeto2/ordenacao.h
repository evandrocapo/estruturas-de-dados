#pragma once
#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct chaveValor {
	int chave;
	float valor;
} ChaveValor;

void bubblesort(ChaveValor arr[], int tam);
void insertionsort(ChaveValor arr[], int tam);
// Para o funcionamento correto do radixsort é necessario que 
// os parametros "OUTPUT" e "COUNT" devem ter tamanho do
// vetor a ser comparado + 1;
void radixsort(ChaveValor arr[], int tam, ChaveValor output[], int count[]);
void shellsort(ChaveValor arr[], int n);
void mergesort(ChaveValor arr[], int n, ChaveValor output[]);
void quicksortLI(ChaveValor arr[], int LI, int LS);
void quicksortLS(ChaveValor arr[], int LI, int LS);
void quicksortMEIO(ChaveValor arr[], int LI, int LS);
void preencherVetor(ChaveValor arr[], int tam, int seed);

#endif /* ORDENACAO_H */