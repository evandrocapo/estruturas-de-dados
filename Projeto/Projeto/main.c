#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

int menu();
void limparTela();

int main() {
    int opcao = 0;
    Fila *fila = NULL;

    do {
        opcao = menu();
        limparTela();

        if(opcao == 1){
            fila = insereFila(fila);
        } else if(opcao == 2){

        } else if(opcao == 3){

        } else if(opcao == 4){

        } else if(opcao == 5){

        } else if(opcao == 6){

        } else if(opcao == 7){

        } else if(opcao == 8){
            printf("\nSaindo do sistema\n");
        } else {
            printf("\nOpcao invalida !\n");
        }
    } while(opcao != 8);

    return 0;
}

int menu(){
    int opcao = 0;
    printf("\nDigite a opcao desejada:\n\n");
    printf("1 - Adicionar uma nova tarefa\n");
    printf("2 - Modificar uma Tarefa\n");
    printf("3 - Concluir Tarefa\n");
    printf("4 - Atualização do Status da Tarefa\n");
    printf("5 - Lista de Tarefas Pendentes\n");
    printf("6 - Lista de Tarefas Concluídas\n");
    printf("7 - Lista de Tarefas Concluídas com e sem Atrasos\n");
    printf("8 - Sair do Programa\n\n");

    scanf("%d", &opcao);
    return opcao;
}

void limparTela(){
    system("cls");
}
