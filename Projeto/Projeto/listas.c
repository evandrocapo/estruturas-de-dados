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

NoLista *insereLista(void){
    NoLista *lista = criarLista();
    lista->tarefa = criarTarefa();
    return lista;
}

NoLista *criarLista(void){
    NoLista *lista = malloc((NoLista *) sizeof(NoLista));
    return lista;
}

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
        for(int j = 0; j < tam; i++){
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
