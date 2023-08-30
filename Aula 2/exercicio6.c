//Exercicio 6:
// A multiplicação de dois números inteiros pode ser feita através
// de somas sucessivas. Construa um algoritmo recursivo
// MultipRec(n1,n2) que calcule a multiplicação de dois inteiro

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2,resultado;

    printf("Digite o primeiro valor \"N1\": ");
    scanf("%d", &n1);

    printf("Digite o segundo valor \"N2\": ");
    scanf("%d", &n2);

    resultado = MultipRec(n1,n2);

    printf("O resultado é: %d", resultado);
}

int MultipRec(int n1,int n2){
    if(n1 == 1) return n1;
    if(n2 == 1) return n1;

    return n1 + MultipRec(n1, n2 - 1);
}