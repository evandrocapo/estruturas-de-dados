//
//  tarefa.c
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "tarefa.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuAlteracaoTarefa(void);

Tarefa *criarTarefa(void){
    Tarefa *tarefa = malloc((Tarefa *) sizeof(Tarefa));

    int code;
    printf("Digite o codigo da tarefa: ");
    scanf("%d", &code);
    tarefa->code = code;

    char name[30];
    printf("Digite o nome da tarefa: ");
    scanf("%s", name);
    strcpy(tarefa->name, name);

    int prioridade;
    printf("Digite a prioridade: ");
    scanf("%d", &prioridade);
    tarefa->prioridade = prioridade;

    char projeto[30];
    printf("Digite o nome do projeto: ");
    scanf("%s", projeto);
    strcpy(tarefa->projeto, projeto);

    int status;
    printf("Digite o status: ");
    scanf("%d", &status);
    tarefa->status = status;

    int initialDate;
    printf("Digite a data inicial: ");
    scanf("%d", &initialDate);
    tarefa->initialDate = initialDate;

    int finalDate;
    printf("Digite a data final: ");
    scanf("%d", &finalDate);
    tarefa->finalDate = finalDate;

    return tarefa;
}

void removerTarefa(Tarefa *tarefa){
    free(tarefa);
}

void editarTarefa(Tarefa *tarefa){
    int opcao = 0;
    
    do {
        opcao = menuAlteracaoTarefa();
        limparTela();

        if(opcao == 1){
            int code;
            printf("Opção 1\n\n");
            
            printf("Digite o codigo da tarefa: ");
            scanf("%d", code);
            tarefa->code = code;
        } else if(opcao == 2){
            char name[30];
            printf("Opção 2\n\n");
            
            printf("Digite o nome da tarefa: ");
            scanf("%s", name);
            strcpy(tarefa->name, name);
        } else if(opcao == 3){
            char projeto[30];
            printf("Opção 3\n\n");
            
            printf("Digite o noem do projeto: ");
            scanf("%s", projeto);
            strcpy(tarefa->projeto, projeto);
        } else if(opcao == 4){
            int prioridade;
            printf("Opção 4\n\n");
            
            printf("Digite a prioridade da tarefa: ");
            scanf("%d", &prioridade);
            tarefa->prioridade = prioridade;
        } else if(opcao == 5){
            int initialDate;
            printf("Opção 5\n\n");
            
            printf("Digite a data inicial da tarefa: ");
            scanf("%d", &initialDate);
            tarefa->initialDate = initialDate;
        } else if(opcao == 6){
            int finalDate;
            printf("Opção 6\n\n");
            
            printf("Digite a data final da tarefa: ");
            scanf("%d", &finalDate);
            tarefa->finalDate = finalDate;
        } else if(opcao == 7){
            printf("\nCancelado alteracao\n");
        } else {
            printf("\nOpcao invalida !\n");
        }
    } while(opcao != 7);
}

int menuAlteracaoTarefa(void){
    int opcao = 0;
    printf("\nDigite a opcao desejada:\n\n");
    printf("1 - Alterar codigo\n");
    printf("2 - Alterar nome\n");
    printf("3 - Alterar projeto\n");
    printf("4 - Alterar prioridade\n");
    printf("5 - Alterar data inicial\n");
    printf("6 - Alterar data final\n");
    printf("7 - Cancelar\n\n");
    
    scanf("%d", &opcao);
    return opcao;
}

void lerTarefa(Tarefa *tarefa){
    printf("Tarefa %d\n", tarefa->code);
    printf("Nome: %s\n", tarefa->name);
    printf("Projeto: %s\n", tarefa->projeto);
    printf("Prioridade: %d\n", tarefa->prioridade);
    printf("Data inicial: %d\n", tarefa->initialDate);
    printf("Data final: %d\n\n", tarefa->finalDate);
}
