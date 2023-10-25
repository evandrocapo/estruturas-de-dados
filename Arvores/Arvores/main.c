//
//  main.c
//  Arvores
//
//  Created by Evandro Douglas Capovilla Junior on 25/10/23.
//

#include <stdio.h>
#include "arvores.h"

int main(int argc, const char * argv[]) {
    Arv *arvore = criarArvore();
    int arvoreEstaVazia = arvoreVazia(arvore);
    int buscaResultado = 0, quantidadeNosInternoResultado = 0;
    printf("A arvore está vazia: %d\n", arvoreEstaVazia);
    
    insereArvore(arvore, 10);
    insereArvore(arvore, 5);
    insereArvore(arvore, 6);
    insereArvore(arvore, 4);
    insereArvore(arvore, 11);
    insereArvore(arvore, 9);
    insereArvore(arvore, 10);
    
    arvoreEstaVazia = arvoreVazia(arvore);
    printf("A arvore está vazia: %d\n", arvoreEstaVazia);
    
    buscaResultado = busca(arvore->raiz, 5);
    printf("O numero 5 existe na arvore: %d\n", buscaResultado);
    
    buscaResultado = busca(arvore->raiz, 10);
    printf("O numero 10 existe na arvore: %d\n", buscaResultado);
    
    buscaResultado = busca(arvore->raiz, 20);
    printf("O numero 20 existe na arvore: %d\n", buscaResultado);
    
    quantidadeNosInternoResultado = qntNosInterno(arvore);
    printf("O numero de nos internos na arvore: %d\n", quantidadeNosInternoResultado);
    
    arvore = removerArvore(arvore);
    return 0;
}
