// Exercicio 4:
// Faça uma função que receba um vetor v, o número n de elementos do
// vetor v ( máximo 15 elementos) e um valor x. Retorne verdade caso x
// for igual a algum dos elementos de v, e falso caso contrário

#include <stdio.h>
#include <stdlib.h>

void duplicidade(int *v, int n, int x);

int main() {
  int x, i, n;
  int v[15];
  int resultado;

  printf("Os numeros da array são \"V\": ");

  for (i = 0; i < 15; i++) {
    v[i] = i;
    printf("%d ", i);
  }

  printf("\nDigite o numero para validação \"X\": ");
  scanf("%d", &x);

  printf("Quantidade de numeros para validar \"N\": ");
  scanf("%d", &n);
  printf("\n");

  duplicidade(v, n - 1, x);
}

void duplicidade(int *v, int n, int x) {
  int valorDaArray = *(v + n);

  if (n < 0) {
    printf("Falso");
    return;
  }

  if (valorDaArray == x) {
    printf("Verdadeiro");
    return;
  }

  duplicidade(v, n - 1, x);
}
