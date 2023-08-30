// Exercicio 8:
// Elabore um programa que contenha uma função recursiva para
// encontrar o menor elemento de um vetor.

#include <stdio.h>
#include <stdlib.h>

void encontrarValorMenor(int *vetor, int *valorMenor, int tamanho);

int main(void) {
  int *valorMenor, vetor[10] = {20, 20, 50, 70, 555, 12, 30, 70, 79, 99};
  valorMenor = (int *)malloc(sizeof(int));

  encontrarValorMenor(vetor, valorMenor, 10);

  for(int i =0;i < 10; i++){
    printf("%d numero do vetor: %d\n", i+1, vetor[i]);
  }

  printf("\nMenor valor: %d\n", *valorMenor);

  return 0;
}

void encontrarValorMenor(int *vetor, int *valorMenor, int tamanho) {
  if (tamanho == 0) {
    return;
  }

  if(tamanho == 10){
    *valorMenor = *(vetor + tamanho - 1);
  } else {
    if (*valorMenor > vetor[tamanho]) {
      *valorMenor = *(vetor + tamanho - 1);
    }
  }

  encontrarValorMenor(vetor, valorMenor, tamanho - 1);
}