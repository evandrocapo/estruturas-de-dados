//
//  filas.c
//  Filas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "filas.h"
#include "listas.h"
#include <stdlib.h>

Fila *insereFila(Fila *recebido) {
    Fila aux;
    int filaEstaVazia = filaVazio(recebido);

    // se a fila estiver vazia
    // então é preciso:
    // 1 - criar uma fila
    // 2 - inserir uma lista no inicio e no fim da fila
    // 3 - inserir uma tarefa dentro do ListaNo
    if(filaEstaVazia){
        recebido = criarFila();
    }

    return recebido;
}

int filaVazio(Fila *recebido){
    if(recebido->inicio == NULL) return 1;
    return 0;
}

Fila *criarFila(){
        Fila *fila = malloc((Fila *) sizeof(Fila));
        NoLista *lista = malloc((NoLista *) sizeof(NoLista)); // criar uma funcao para criar lista
        fila->inicio = lista;
        fila->fim = lista;

        return fila;
}
