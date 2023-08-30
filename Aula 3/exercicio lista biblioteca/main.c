//Lista
//Exercicio de Lista

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, const char * argv[]) {
    Lista *lista = NULL;
    
    printf("adicionando 3 valores: \n");
    lista = insereLista(lista, 10);
    lista = insereLista(lista, 20);
    lista = insereLista(lista, 30);
    leitura(lista);
    
    printf("Removendo 1 valor: \n");
    lista = removerLista(lista);
    leitura(lista);
    
    printf("\nRemovendo 2 valor: ");
    valorRemovido = removerListaRetornandoValorRemovido(&lista);
    printf("%d\n", valorRemovido);
    
    printf("\nMostrando array final \n");
    leitura(lista);
    
    return 0;
}