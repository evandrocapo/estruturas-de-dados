//Lista
//Exercicio de Lista


#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, const char * argv[]) {
    Lista *lista = NULL, *lista2 = NULL, *uniao = NULL;
    int valorRemovido = 0;
    int tamanho = 0;
    int somatorio = 0;
    
    printf("Adicionando 3 valores: \n");
    lista = insereLista(lista, 10);
    lista = insereLista(lista, 20);
    lista = insereLista(lista, 30);
    leitura(lista);
    
    printf("\nRemovendo 1 valor: \n");
    lista = removerLista(lista);
    leitura(lista);
    
    printf("\nRemovendo 2 valor: ");
    valorRemovido = removerListaRetornandoValorRemovido(&lista);
    printf("%d\n", valorRemovido);
    
    printf("\nMostrando array final \n");
    leitura(lista);
    
    printf("\nAdicionando 3 valores: \n");
    lista = insereLista(lista, 40);
    lista = insereLista(lista, 50);
    lista = insereLista(lista, 60);
    leitura(lista);
    
    tamanho = tamanhoLista(lista);
    printf("\nTamanho da Lista: %d\n", tamanho);
    
    somatorio = somatorioElementoLista(lista);
    printf("\nSomatorio da Lista: %d\n", somatorio);
    
    printf("\nAdicionando 6 valores: \n");
    lista2 = insereLista(lista2, 10);
    lista2 = insereLista(lista2, 10);
    lista2 = insereLista(lista2, 20);
    lista2 = insereLista(lista2, 30);
    lista2 = insereLista(lista2, 40);
    lista2 = insereLista(lista2, 50);
    leitura(lista2);
    
    printf("\nUnindo as duas listas: \n");
    uniao = uniaoLista(lista, lista2);
    leitura(uniao);
    return 0;
}
