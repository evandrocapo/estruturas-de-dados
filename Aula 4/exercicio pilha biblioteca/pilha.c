//
//  pilha.c
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 30/08/23.
//

#include "pilha.h"
#include <stdlib.h>

Pilha *criarPilha(void){
    Pilha *pilha;
    pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

Pilha *push(Pilha *pilha, int valor){
    No *novo;
    novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return pilha;
}

int pop(Pilha **pilha){
    int valorPilha;
    No *aux = (*pilha)->topo;
    valorPilha = aux->valor;
    (*pilha)->topo = aux->prox;
    free(aux);
    return valorPilha;
}

int vazioPilha(Pilha *pilha){
    if(pilha->topo == NULL) {
        return 1;
    }
    return 0;
}

void leituraPilha(Pilha *pilha){
    No *aux = pilha->topo;
    if(!vazioPilha(pilha)){
        do {
            printf("%d ", aux->valor);
            aux = aux->prox;
        } while(aux != NULL);
        printf("\n");
    }
}

void liberaPilha(Pilha **pilha) {
    No *aux = (*pilha)->topo;
    No *aux2;
    if(!vazioPilha((*pilha))){
        do {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
        } while(aux != NULL);
        (*pilha)->topo = NULL;
    }
}
