// Exercicio 2:
// Faça uma função que leia cinco valores inteiros e imprima, no
// programa principal, o maior e o menor valor

#include <stdio.h>
#include <stdlib.h>

void encontrarValores(int *valorMenor, int *valorMaior, int tentativas,
                      int condicaoInicial);

int main(void) {
  int *valorMenor, *valorMaior;
  valorMenor = (int *)malloc(sizeof(int));
  valorMaior = (int *)malloc(sizeof(int));

  *valorMenor = 0;
  *valorMaior = 0;

  encontrarValores(valorMenor, valorMaior, 5, 1);

  printf("Menor valor: %d\n", *valorMenor);
  printf("Maior valor: %d\n", *valorMaior);

  return 0;
}

void encontrarValores(int *valorMenor, int *valorMaior, int tentativas,
                      int condicaoInicial) {
  int i = 0;
  int valor;

  if (tentativas == 0)
    return;

  printf("Digite um valor: ");
  scanf("%d", &valor);
  printf("\n");

  if (condicaoInicial) {
    *valorMenor = valor;
    *valorMaior = valor;
  } else {
    if (valor < *valorMenor) {
      *valorMenor = valor;
    }
    if (valor > *valorMaior) {
      *valorMaior = valor;
    }
  }

  encontrarValores(valorMenor, valorMaior, tentativas - 1, 0);
}