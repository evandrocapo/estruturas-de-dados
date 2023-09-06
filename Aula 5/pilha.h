//
//  pilha.h
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 06/09/23.
//

#ifndef pilha_h
#define pilha_h

#include <stdio.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct pilha {
    struct no *topo;
} Pilha;

Pilha *criarPilha(void);
Pilha *push(Pilha *pilha, int valor);
int pop(Pilha **pilha);
int vazioPilha(Pilha *pilha);
void leituraPilha(Pilha *pilha);
void liberaPilha(Pilha **pilha);
int quantidadePilha(Pilha *pilha);
Pilha *inverterPilha(Pilha *pilha);
Pilha *removerDaPilha(Pilha *pilha, int pos);
int compara(Pilha *pilhaUm, Pilha *pilhaDois);
Pilha *armazenaDigitosPilha(int num);
int mostrarDigitosPilha(Pilha *pilhaDigitos);

#endif /* pilha_h */
