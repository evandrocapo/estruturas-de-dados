//
//  lista.h
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 30/08/23.
//

#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct no {
    int valor;
    struct no *prox;
} Lista;


Lista *insereLista(Lista *recebido, int valor);
Lista *removerLista(Lista *recebido);
int removerListaRetornandoValorRemovido(Lista **recebido);
int vazio(Lista *recebido);
void leitura(Lista *recebido);
int tamanhoLista(Lista *recebido);
int somatorioElementoLista(Lista *recebido);
Lista *uniaoLista(Lista *recebidoUm, Lista *recebidoDois);
int existeValor(Lista *recebido, int valor);

#endif /* lista_h */
