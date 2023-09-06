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

int quantidadePilha(Pilha *pilha){
    int cont=0, i;
    No *aux = pilha->topo;
    
    for(i=0; aux != NULL; i++){
        cont++;
        aux = aux->prox;
    }
    
    return cont++;
}

Pilha *inverterPilha(Pilha *pilha){
    Pilha *aux = criarPilha();
    No *pilhaAux = pilha->topo;
    int i;
    
    if(vazioPilha(pilha)){
        return aux;
    }
    
    for(i=0;pilhaAux != NULL; i++){
        push(aux, pilhaAux->valor);
        pilhaAux = pilhaAux->prox;
    }
    
    return aux;
}

Pilha *removerDaPilha(Pilha *pilha, int pos){
    No *aux = pilha->topo, *auxNo;
    int i;
    
    if(vazioPilha(pilha)){
        return pilha;
    }
    
    if(pos == 0){
        auxNo = pilha->topo->prox;
        free(pilha->topo);
        pilha->topo = auxNo;
        return pilha;
    }
    
    auxNo = aux;
    
    for(i=0;aux != NULL || i == pos; i++){
        if(i == pos){
            auxNo->prox = aux->prox;
            free(aux);
            aux = auxNo;
        }
        auxNo = aux;
        aux = aux->prox;
    }
    
    return pilha;
}

int compara(Pilha *pilhaUm, Pilha *pilhaDois){
    int tamPilhaUm = 0, tamPilhaDois = 0;
    
    tamPilhaUm = quantidadePilha(pilhaUm);
    tamPilhaDois = quantidadePilha(pilhaDois);
    
    if(tamPilhaUm == tamPilhaDois){
        return 0;
    }
    
    if(tamPilhaUm > tamPilhaDois){
        return 1;
    }
    
    return 2;
}

Pilha *armazenaDigitosPilha(int num){
    Pilha *pilha = criarPilha();
    int numAux = num;
    
    if(num == 0){
        push(pilha, 0);
        return pilha;
    }
    if(numAux > 0){
        do{
            push(pilha, numAux%10);
            numAux = numAux/10;
        }while(numAux > 0);
    }
    
    return pilha;
}

int mostrarDigitosPilha(Pilha *pilhaDigitos){
    int valor = 0;
    No *aux = pilhaDigitos->topo;
    
    if(aux == NULL){
        return valor;
    }
    
    do {
        valor = (valor * 10) + aux->valor;
        aux = aux->prox;
    } while(aux != NULL);
    
    return valor;
}
