//
//  pilha.h
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 30/08/23.
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

#endif /* pilha_h */
