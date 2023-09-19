#include "listas.h"

#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct fila {
    NoLista *inicio;
    NoLista *fim;
} Fila;

Fila *criarFila();
Fila *insereFila(Fila *recebido);
Fila *removerFila(Fila *recebido);
int filaVazio(Fila *recebido);
void filaLeitura(Fila *recebido);
int filaExisteValor(Fila *recebido, int valor);

#endif // FILAS_H_INCLUDED
