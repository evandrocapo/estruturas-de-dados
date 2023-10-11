//
//  listas.c
//  Listas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "listas.h"
#include "tarefa.h"
#include <stdlib.h>
#include <stdio.h>

NoLista *criarLista(void);

NoLista *insereLista(int prioridade){
    NoLista *lista = criarLista();
    lista->tarefa = criarTarefa(prioridade);
    return lista;
}

void insereListaComDados(NoLista **lista, NoLista *listaComDados){
    NoLista *listaAux = *lista;
    if(listaAux != NULL){
        while(listaAux->prox != NULL){
            listaAux = listaAux->prox;
        }
        listaAux->prox = listaComDados;
    } else {
        lista = &listaComDados;
    }
}

NoLista *criarLista(void){
    NoLista *lista = malloc((NoLista *) sizeof(NoLista));
    return lista;
}

NoLista *removerItemDaLista(NoLista **lista,int code){
    NoLista *listaAux = *lista;

    if(lista == NULL){
        return listaAux;
    }
    
    if(listaAux->tarefa->code == code){
        *lista = listaAux->prox;
        listaAux->prox = NULL;
        return listaAux;
    }
    
    for(listaAux = *lista; listaAux->prox != NULL; listaAux = listaAux->prox){
        if(listaAux->prox->tarefa->code == code) {
            listaAux->prox = listaAux->prox->prox;
            return *lista;
        }
    }
    
    return *lista;
};

void editarItemDaLista(NoLista *recebido){
    editarTarefa(recebido->tarefa);
}

void lerLista(NoLista *recebido){
    do {
        lerTarefa(recebido->tarefa);
        recebido = recebido->prox;
    }while(recebido != NULL);
}

void lerListaConcluidasComESemAtrasos(NoLista *recebido){
    NoLista *listaAux = recebido;
    
    do {
        printf("Tarefas Atrasadas\n\n");
        if(listaAux->tarefa->status == 1){
            lerTarefa(listaAux->tarefa);
        }
        listaAux = listaAux->prox;
    } while(listaAux != NULL);
    
    listaAux = recebido;
    
    do {
        printf("Tarefas Sem Atrasos\n\n");
        if(listaAux->tarefa->status == 0){
            lerTarefa(listaAux->tarefa);
        }
        listaAux = listaAux->prox;
    } while(listaAux != NULL);
}

int tamanhoLista(NoLista *lista){
    NoLista *aux;
    int tam = 0;
    
    for(aux = lista; aux != NULL; aux = aux->prox){
        tam++;
    }
    
    return tam;
};

NoLista *ordenarLista(NoLista *lista){
    int tam = tamanhoLista(lista) - 1;
    
    if(tam <= 1){
        return lista;
    }
    
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(tarefaUmMaiorTarefaDois(lista->tarefa, lista->prox->tarefa)){
                NoLista *listaAux = lista;
                lista = lista->prox;
                lista->prox = listaAux;
            }
        }
    }
    
    return lista;
};

void limparLista(NoLista *lista){
    if(lista != NULL){
        NoLista *listaAux = lista->prox;
        if(lista != NULL){
            do{
                limparTarefa(lista->tarefa);
                free(lista);
                lista = listaAux;
                listaAux = lista->prox;
            }while(lista != NULL);
        }
    }
}
