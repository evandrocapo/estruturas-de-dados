//
//  listas.c
//  Listas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "listas.h"
#include "tarefa.h"
#include <stdlib.h>

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
