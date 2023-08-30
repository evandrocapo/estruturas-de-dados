//
//  lista.c
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 30/08/23.
//

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

int tamanhoLista(Lista *recebido){
    int tamanho = 0, isVazio = 0;
    Lista *listaAtual = recebido;
    
    do{
        isVazio = vazio(listaAtual);
        if(isVazio == 0) {
            tamanho++;
            listaAtual = listaAtual->prox;
        }
    } while(isVazio != 1);
    
    return tamanho;
}

int somatorioElementoLista(Lista *recebido){
    int soma = 0, isVazio = 0;
    Lista *listaAtual = recebido;
    
    do{
        isVazio = vazio(listaAtual);
        if(isVazio == 0) {
            soma = soma + listaAtual->valor;
            listaAtual = listaAtual->prox;
        }
    } while(isVazio != 1);
    
    return soma;
}

Lista *uniaoLista(Lista *recebidoUm, Lista *recebidoDois){
    Lista *uniao = NULL, *aux = NULL;
    int isVazio = 0, existe = 0;
    uniao = recebidoUm;
    aux = recebidoDois;
    
    do{
        isVazio = vazio(aux);
        if(isVazio == 0) {
            existe = existeValor(uniao, aux->valor);
            if(existe == 0) {
                uniao = insereLista(uniao, aux->valor);
            }
            aux = aux->prox;
            existe = 0;
        }
    } while(isVazio != 1);
    
    return uniao;
}

int existeValor(Lista *recebido, int valor){
    int existe = 0, isVazio = 0;
    Lista *listaAtual = recebido;
    
    do{
        isVazio = vazio(listaAtual);
        if(isVazio == 0) {
            if(listaAtual->valor == valor){
                existe = 1;
            }
            listaAtual = listaAtual->prox;
        }
    } while(isVazio == 0);
    
    return existe;
}

