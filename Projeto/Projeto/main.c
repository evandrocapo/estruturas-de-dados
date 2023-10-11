//
//  main.c
//  Projeto
//
//  Created by Evandro Douglas Capovilla Junior on 20/09/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "filas.h"
#include "listas.h"
#include "common.h"

int menu(void);
int solicitarCodigoDaTarefa(int opcao);
int solicitarAdicionarOuRemoverPendencia(void);
int solicitarPrioridadeDaTarefa();

int main(int argc, const char * argv[])  {
    int opcao = 0;
    Fila *filaP1 = NULL;
    Fila *filaP2 = NULL;
    Fila *filaP3 = NULL;
    NoLista *lista = NULL;
    NoLista *listaPendente = NULL;

    do {
        opcao = menu();
        limparTela();

        if(opcao == 0){
            if(filaP1 != NULL && filaP1->inicio != NULL){
                lerLista(filaP1->inicio);
            }
            if(filaP2 != NULL && filaP2->inicio != NULL){
                lerLista(filaP1->inicio);
            }
            if(filaP3 != NULL && filaP3->inicio != NULL){
                lerLista(filaP1->inicio);
            }
        } else if(opcao == 1){
            int prioridade = solicitarPrioridadeDaTarefa();
            if(prioridade == 1){
                filaP1 = insereFila(filaP1, prioridade);
            }
            if(prioridade == 2){
                filaP2 = insereFila(filaP2, prioridade);
            }
            if(prioridade == 3){
                filaP3 = insereFila(filaP3, prioridade);
            }
        } else if(opcao == 2){
            int code;
            code = solicitarCodigoDaTarefa(2);
            editarItemDaFila(filaP1, code);
            editarItemDaFila(filaP2, code);
            editarItemDaFila(filaP3, code);
        } else if(opcao == 3){
            int code;
            code = solicitarCodigoDaTarefa(3);
            filaP1 = concluirTarefa(filaP1, &lista, code);
            filaP2 = concluirTarefa(filaP2, &lista, code);
            filaP3 = concluirTarefa(filaP3, &lista, code);
            lista = ordenarLista(lista);
        } else if(opcao == 4){
            int code;
            code = solicitarCodigoDaTarefa(4);
            int tipo;
            tipo = solicitarAdicionarOuRemoverPendencia();
            if(tipo == 1){
                filaP1 = mudarStatusPendenteTarefa(filaP1, &listaPendente, code);
                filaP2 = mudarStatusPendenteTarefa(filaP2, &listaPendente, code);
                filaP3 = mudarStatusPendenteTarefa(filaP3, &listaPendente, code);
            } else if (tipo == 2){
                mudarStatusNaoPendenteTarefa(filaP1, filaP2, filaP3, &listaPendente, code);
            } else {
                printf("\nOpcao nao encontrada!\n");
            }
            listaPendente = ordenarLista(listaPendente);
        } else if(opcao == 5){
            if(filaP1 != NULL && filaP1->inicio != NULL){
                imprimirTarefasPendentes(filaP1);
            }
            if(filaP2 != NULL && filaP2->inicio != NULL){
                imprimirTarefasPendentes(filaP2);
            }
            if(filaP3 != NULL && filaP3->inicio != NULL){
                imprimirTarefasPendentes(filaP3);
            }
        } else if(opcao == 6){
            if(lista != NULL){
                lerLista(lista);
            }
        } else if(opcao == 7){
            if(lista != NULL){
                lerListaConcluidasComESemAtrasos(lista);
            }
        } else if(opcao == 8){
                limparLista(lista);
                limparLista(listaPendente);
                limparFila(filaP1);
                limparFila(filaP2);
                limparFila(filaP3);
            printf("\nSaindo do sistema\n");
        } else {
            printf("\nOpcao invalida !\n");
        }
    } while(opcao != 8);

    return 0;
}

int menu(void){
    int opcao = 0;
    printf("\nDigite a opcao desejada:\n\n");
    printf("0 - Listar todas as tarefas\n");
    printf("1 - Adicionar uma nova tarefa\n");
    printf("2 - Modificar uma Tarefa\n");
    printf("3 - Concluir Tarefa\n");
    printf("4 - Atualizacao do Status da Tarefa\n");
    printf("5 - Lista de Tarefas Pendentes\n");
    printf("6 - Lista de Tarefas Concluidas\n");
    printf("7 - Lista de Tarefas Concluidas com e sem Atrasos\n");
    printf("8 - Sair do Programa\n\n");

    scanf("%d", &opcao);
    return opcao;
}

int solicitarPrioridadeDaTarefa(){
    int code = 0;

    printf("\nDigite a prioridade da tarefa: ");
    scanf("%d", &code);

    return code;
}

int solicitarCodigoDaTarefa(int tipo){
    int code = 0;

    if(tipo == 2){
        printf("\nDigite o codigo da tarefa para edição: ");
    } else  if(tipo == 3){
        printf("\nDigite o codigo da tarefa para concluir: ");
    } else  if(tipo == 4){
        printf("\nDigite o codigo da tarefa para trocar para pendente: ");
    } else {
        printf("\nDigite o codigo da tarefa: ");
    }
    scanf("%d", &code);

    return code;
}

int solicitarAdicionarOuRemoverPendencia(void){
    int code = 0;

    printf("\nDigite para adicionar ou remover pendencia!");
    printf("\nDigite 1 para adicionar pendencia");
    printf("\nDigite 2 para remover pendencia\n");
    scanf("%d", &code);

    return code;
}
