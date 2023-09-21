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
NoLista *procurarItemNaFilaERemover(Fila **recebido, int code);

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

NoLista *procurarItemNaFilaERemover(Fila **recebido, int code){
    Fila *recebidoAux = recebido;
    NoLista *lista = recebidoAux->inicio;
    NoLista *aux = NULL;

    if(lista->tarefa->code == code){
        aux = lista;
        lista = lista->prox;

        return aux;
    }

    do {
        if(lista->prox->tarefa->code == code){
            aux = lista->prox;
            lista->prox = aux->prox;

            return aux;
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

Fila *concluirTarefa(Fila *recebido, NoLista **lista, int code){
    NoLista *listaAux = lista;
    NoLista *listaRemovida = NULL;

    int filaNula = filaEstaNula(recebido);

    if(filaNula){
        return recebido;
    }

    listaRemovida = procurarItemNaFilaERemover(recebido, code);

    if(listaAux == NULL){
        listaAux = listaRemovida;
    } else {
        int adicionado = 0;
        do{
            if(listaAux->prox == NULL){
                listaAux->prox = listaRemovida;
                adicionado = 1;
            }
        } while(adicionado == 0);
    }

    return recebido;
}
