//
//  filas.c
//  Filas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "filas.h"
#include "listas.h"
#include <stdlib.h>

int filaEstaNula(Fila *recebido);
int filaVazio(Fila *recebido);
Fila *criarFila(void);
NoLista *procurarItemNaFila(Fila *recebido, int code);

Fila *insereFila(Fila *recebido) {
    int filaNula = filaEstaNula(recebido);
    
    if(filaNula){
        recebido = criarFila();
    }
    
    int filaEstaVazia = filaVazio(recebido);

    if(filaEstaVazia){
        recebido->inicio = insereLista();
        recebido->fim = recebido->inicio;
    } else {
        recebido->fim->prox = insereLista();
        recebido->fim = recebido->fim->prox;
    }

    return recebido;
}

void *editarItemDaFila(Fila *recebido, int code) {
    int filaNula = filaEstaNula(recebido);
    
    if(filaNula){
        return recebido;
    }
    
    NoLista *lista = procurarItemNaFila(recebido, code);
    
    if(lista != NULL){
        editarItemDaLista(lista);
    }
    
    return recebido;
}

NoLista *procurarItemNaFila(Fila *recebido, int code){
    NoLista *lista = recebido->inicio;
    do {
        if(lista->tarefa->code == code){
            return lista;
        }
    } while(recebido != NULL);
    return NULL;
}

int filaEstaNula(Fila *recebido){
    if(recebido == NULL){
        return 1;
    }
    return 0;
}

int filaVazio(Fila *recebido){
    if(recebido->inicio == NULL) return 1;
    return 0;
}

Fila *criarFila(void){
        Fila *fila = malloc((Fila *) sizeof(Fila));
        return fila;
}
