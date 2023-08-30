// Lista
// Exercicio de Lista

#include "lista.h"
#include <stdlib.h>

Lista *insereLista(Lista *recebido, int valor){
    Lista *novo;
    novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = recebido;
    return novo;
}

Lista *removerLista(Lista *recebido){
    Lista *atual = recebido->prox;
    free(recebido);
    
    return atual;
}

int removerListaRetornandoValorRemovido(Lista **recebido){
    Lista *atual = *recebido;
    Lista *prox = atual->prox;
    int valor = atual->valor;

    free(atual);
    
    *recebido = prox;
    
    return valor;
}

int vazio(Lista *recebido){
    if(recebido == NULL) return 1;
    return 0;
}

void leitura(Lista *recebido){
    int isVazio;
    Lista *listaAtual = recebido;
    
    do{
        isVazio = vazio(listaAtual);
        if(isVazio == 0) {
            printf("Valor: %d\n", listaAtual->valor);
            listaAtual = listaAtual->prox;
        }
    } while(isVazio != 1);
}
