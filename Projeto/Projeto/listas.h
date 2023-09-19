#include "tarefa.h"

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct noLista {
    Tarefa *tarefa;
    int *prox;
} NoLista;

NoLista *insereLista(NoLista *recebido, int valor);
NoLista *removerLista(NoLista *recebido);
int vazio(NoLista *recebido);
void leitura(NoLista *recebido);
int existeValor(NoLista *recebido, int valor);

#endif // LISTAS_H_INCLUDED
