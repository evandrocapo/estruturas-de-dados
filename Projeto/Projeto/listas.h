#include "tarefa.h"

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct noLista {
    Tarefa *tarefa;
    struct noLista *prox;
} NoLista;

NoLista *insereLista(void);
NoLista *removerLista(NoLista *recebido);
void editarItemDaLista(NoLista *recebido);
int vazio(NoLista *recebido);
void leitura(NoLista *recebido);
int existeValor(NoLista *recebido, int valor);
void lerLista(NoLista *recebido);
#endif // LISTAS_H_INCLUDED
