// Exercicio 5:
// Faça uma função que faça a rotação de três números. Tais números
// precisam ser passados como parâmetros, por referência. Por exemplo,
// se a função receber os valores 5 8 e 9, nesta ordem, os valores de saída
// nessas variáveis serão 8, 9 e 5, respectivamente

#include <stdio.h>
#include <stdlib.h>

void inverterSequencia(int *a, int *b, int *c, int quantidade);

int main() {
  int a, b, c;

  printf("Digite o valor de A: ");
  scanf("%d", &a);

  printf("Digite o valor da B: ");
  scanf("%d", &b);

  printf("Digite o valor da C: ");
  scanf("%d", &c);

  inverterSequencia(&a, &b, &c, 3);

  printf("O valor de A: %d\n", a);
  printf("O valor de B: %d\n", b);
  printf("O valor de C: %d\n", c);
}

void inverterSequencia(int *a, int *b, int *c, int quantidade) {
  if(quantidade == 0) return;
  
  int aux, aux2;

  aux = *b;
  aux2 = *c;
  
  *b = *a;
  *c = aux;
  *a = aux2;

  inverterSequencia(a, b, c, quantidade-1);
}