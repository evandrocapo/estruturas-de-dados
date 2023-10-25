#include "tarefa.h"

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct noLista {
    Tarefa *tarefa;
    struct noLista *prox;
} NoLista;

NoLista *insereLista(int prioridade);
NoLista *removerLista(NoLista *recebido);
NoLista *removerItemDaLista(NoLista **lista,int code);
void editarItemDaLista(NoLista *recebido);
int vazio(NoLista *recebido);
void leitura(NoLista *recebido);
int existeValor(NoLista *recebido, int valor);
void lerLista(NoLista *recebido);
void lerListaConcluidasComESemAtrasos(NoLista *recebido);
NoLista *ordenarLista(NoLista *lista);
void limparLista(NoLista *lista);
void insereListaComDados(NoLista **lista, NoLista *listaComDados);

#endif // LISTAS_H_INCLUDED
