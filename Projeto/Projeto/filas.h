#include "listas.h"

#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct fila {
    NoLista *inicio;
    NoLista *fim;
} Fila;

Fila *insereFila(Fila *recebido);
Fila *removerFila(Fila *recebido);
Fila *concluirTarefa(Fila *recebido, NoLista **lista, int code);
Fila *mudarStatusPendenteTarefa(Fila *recebido, NoLista **lista, int code);
void *editarItemDaFila(Fila *recebido, int code);
int filaVazio(Fila *recebido);
void filaLeitura(Fila *recebido);
int filaExisteValor(Fila *recebido, int valor);
void imprimirTarefasPendentes(Fila *fila);
void atualizarTarefasAtrasadas(Fila *fila);
Fila *validarStatusDasTarefas(Fila *fila,NoLista **lista);

#endif // FILAS_H_INCLUDED
