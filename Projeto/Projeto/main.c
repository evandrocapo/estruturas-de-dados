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

int main(int argc, const char * argv[])  {
    int opcao = 0;
    Fila *fila = NULL;
    NoLista *lista = NULL;
    NoLista *listaPendente = NULL;

    do {
        opcao = menu();
        limparTela();

        if(opcao == 0){
            lerLista(fila->inicio);
        } else if(opcao == 1){
            fila = insereFila(fila);
        } else if(opcao == 2){
            int code;
            code = solicitarCodigoDaTarefa(2);
            editarItemDaFila(fila, code);
        } else if(opcao == 3){
            int code;
            code = solicitarCodigoDaTarefa(3);
            fila = concluirTarefa(fila, &lista, code);
            lista = ordenarLista(lista);
        } else if(opcao == 4){
            int code;
            code = solicitarCodigoDaTarefa(4);
            int tipo;
            tipo = solicitarAdicionarOuRemoverPendencia();
            if(tipo == 1){
                fila = mudarStatusPendenteTarefa(fila, &listaPendente, code);
            } else if (tipo == 2){
                fila = mudarStatusNaoPendenteTarefa(fila, &listaPendente, code);
            } else {
                printf("\nOpcao nao encontrada!\n");
            }
            listaPendente = ordenarLista(listaPendente);
//            atualizarTarefasAtrasadas(fila);
//            fila = validarStatusDasTarefas(fila, &listaPendente);
        } else if(opcao == 5){
            imprimirTarefasPendentes(fila);
        } else if(opcao == 6){
            lerLista(lista);
        } else if(opcao == 7){
            lerListaConcluidasComESemAtrasos(lista);
        } else if(opcao == 8){
            limparLista(lista);
            limparLista(listaPendente);
            limparFila(fila);
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
