//
//  filas.c
//  Filas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "filas.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

int filaEstaNula(Fila *recebido);
int filaVazio(Fila *recebido);
Fila *criarFila(void);
NoLista *procurarItemNaFila(Fila *recebido, int code);
NoLista *procurarItemNaFilaERemover(Fila **recebido, int code);

Fila *insereFila(Fila *recebido, int prioridade) {
    int filaNula = filaEstaNula(recebido);

    if(filaNula){
        recebido = criarFila();
    }

    int filaEstaVazia = filaVazio(recebido);

    if(filaEstaVazia){
        recebido->inicio = insereLista(prioridade);
        recebido->fim = recebido->inicio;
    } else {
        recebido->fim->prox = insereLista(prioridade);
        recebido->fim = recebido->fim->prox;
    }

    return recebido;
}

Fila *insereFilaComDados(Fila *recebido, NoLista *lista) {
    int filaNula = filaEstaNula(recebido);

    if(filaNula){
        recebido = criarFila();
    }

    int filaEstaVazia = filaVazio(recebido);

    if(filaEstaVazia){
        recebido->inicio = lista;
        recebido->fim = recebido->inicio;
    } else {
        recebido->fim->prox = lista;
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
    
    if(lista == NULL){
        return NULL;
    }
    
    do {
        if(lista->tarefa->code == code){
            return lista;
        }
        lista = lista->prox;
    } while(lista != NULL);
    return NULL;
}

NoLista *procurarItemNaFilaERemover(Fila **recebido, int code){
    Fila *recebidoAux = *recebido;
    NoLista *lista = recebidoAux->inicio;
    NoLista *aux = NULL;
    
    if(lista == NULL){
        return NULL;
    }

    if(lista->tarefa->code == code){
        if(recebidoAux->inicio == recebidoAux->fim){
            recebidoAux->inicio = lista->prox;
            recebidoAux->fim = lista->prox;
        } else {
            recebidoAux->inicio = lista->prox;
            if(lista->prox == NULL){
                recebidoAux->fim = NULL;
            }
        }

        return lista;
    }

    do {
        if(lista->prox == NULL){
            return NULL;
        }
        if(lista->prox->tarefa->code == code){
            aux = lista->prox;
            lista->prox = aux->prox;

            return aux;
        }
        lista = lista->prox;
    } while(lista != NULL);
    return NULL;
}

int filaEstaNula(Fila *recebido){
    if(recebido == NULL){
        return 1;
    }
    return 0;
}

int filaVazio(Fila *recebido){
    if(recebido == NULL) return 1;
    if(recebido->inicio == NULL) return 1;
    return 0;
}

Fila *criarFila(void){
        Fila *fila = malloc((Fila *) sizeof(Fila));
        return fila;
}

Fila *concluirTarefa(Fila *recebido, NoLista **lista, int code){
    NoLista *listaAux = *lista;
    NoLista *listaRemovida = NULL;

    int filaNula = filaEstaNula(recebido);

    if(filaNula){
        return recebido;
    }

    listaRemovida = procurarItemNaFilaERemover(&recebido, code);
    if(listaRemovida == NULL){
        return recebido;
    }
    listaRemovida->prox = NULL;
    
    listaRemovida->tarefa = atualizarStatusDaTarefa(listaRemovida->tarefa);
    
    if(recebido->inicio == listaRemovida){
        recebido->inicio = listaRemovida->prox;
    }
    
    if(recebido->fim == listaRemovida){
        if(recebido->inicio == NULL){
            recebido->fim = NULL; // precisar ser o anterior;
        } else {
            listaAux = recebido->inicio;
            if(listaAux->prox != NULL){
                do{
                    listaAux = listaAux->prox;
                }while(listaAux->prox != NULL);
            }
            recebido->fim = listaAux;
            listaAux = *lista;
        }
    }

    if(listaAux == NULL){
        *lista = listaRemovida;
    } else {
        int adicionado = 0;
        do{
            if(listaAux->prox == NULL){
                listaAux->prox = listaRemovida;
                adicionado = 1;
            } else {
                listaAux = listaAux->prox;
            }
        } while(adicionado == 0 && listaAux != NULL);
    }

    return recebido;
}

Fila *mudarStatusPendenteTarefa(Fila *recebido, NoLista **lista, int code){
    NoLista *listaAux = *lista;
    NoLista *listaRemovida = NULL;

    int filaNula = filaEstaNula(recebido);

    if(filaNula){
        return recebido;
    }

    listaRemovida = procurarItemNaFilaERemover(&recebido, code);
    if(listaRemovida == NULL){
        return recebido;
    }
    listaRemovida->prox = NULL;
    listaRemovida->tarefa->status = -1;

    if(listaAux == NULL){
        *lista = listaRemovida;
    } else {
        int adicionado = 0;
        do{
            if(listaAux->prox == NULL){
                listaAux->prox = listaRemovida;
                adicionado = 1;
            } else {
                listaAux = listaAux->prox;
            }
        } while(adicionado == 0 && listaAux != NULL);
    }

    return recebido;
}

void mudarStatusNaoPendenteTarefa(Fila *recebidoP1, Fila *recebidoP2, Fila *recebidoP3, NoLista **lista, int code){
    NoLista *listaAux = *lista;
    NoLista *listaRemovida = NULL;
    
    int filaP1Nula = filaEstaNula(recebidoP1);
    int filaP2Nula = filaEstaNula(recebidoP2);
    int filaP3Nula = filaEstaNula(recebidoP3);
    
    listaRemovida = removerItemDaLista(lista, code);
    if(listaRemovida != NULL){
        listaRemovida->tarefa->status = 0;
        
        if(listaRemovida->tarefa->prioridade == 1 && filaP1Nula == 0){
            insereFilaComDados(recebidoP1, listaRemovida);
        } else if(listaRemovida->tarefa->prioridade == 2 && filaP2Nula == 0){
            insereFilaComDados(recebidoP2, listaRemovida);
        } else if(listaRemovida->tarefa->prioridade == 3 && filaP3Nula == 0){
            insereFilaComDados(recebidoP3, listaRemovida);
        } else {
            insereListaComDados(lista, listaRemovida);
        }
    }
}

void imprimirTarefasPendentes(Fila *fila){
    int filaEstaVazia = filaVazio(fila);
    
    if(filaEstaVazia){
        printf("Nenhuma Tarefa Pendente!\n");
        system("pause");
    } else {
        NoLista *lista = fila->inicio;
        lerLista(lista);
    }
}

void atualizarTarefasAtrasadas(Fila *fila){
    int filaEstaVazia = filaVazio(fila);
    
    if(filaEstaVazia != 1){
        NoLista *lista;
        for(lista = fila->inicio;lista != NULL; lista = lista->prox){
            lista->tarefa = atualizarStatusDaTarefa(lista->tarefa);
        }
    }
}

Fila *validarStatusDasTarefas(Fila *fila, NoLista **lista){
    int filaEstaVazia = filaVazio(fila);
    
    if(filaEstaVazia != 1){
        NoLista *listaAux;
        for(listaAux = fila->inicio;listaAux != NULL; listaAux = listaAux->prox){
            if(listaAux->tarefa->status == -1){
                fila = concluirTarefa(fila, lista, listaAux->tarefa->code);
            }
        }
    }
    
    return fila;
}

void limparFila(Fila *fila){
    if(!filaVazio(fila)){
        NoLista *lista = fila->inicio;
        limparLista(lista);
        free(fila);
    }
}
