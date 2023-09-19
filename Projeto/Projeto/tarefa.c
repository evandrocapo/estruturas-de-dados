//
//  tarefa.c
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#include "tarefa.h"
#include <stdlib.h>
#include <string.h>

Tarefa *criarTarefa(){
    Tarefa *tarefa = malloc((Tarefa *) sizeof(Tarefa));

    int code;
    printf("Digite o codigo da tarefa: ");
    scanf("%d", code);
    tarefa->code = code;

    char name[30];
    printf("Digite o nome da tarefa: ");
    scanf("%s", name);
    strcpy(tarefa->name, name);

    int prioridade;
    printf("Digite a prioridade: ");
    scanf("%d", prioridade);
    tarefa->prioridade = prioridade;

    char projeto[30];
    printf("Digite o nome do projeto: ");
    scanf("%s", projeto);
    strcpy(tarefa->projeto, projeto);

    int status;
    printf("Digite o status: ");
    scanf("%d", status);
    tarefa->status = status;

    int initialDate;
    printf("Digite a data inicial: ");
    scanf("%d", initialDate);
    tarefa->initialDate = initialDate;

    int finalDate;
    printf("Digite a data final: ");
    scanf("%d", finalDate);
    tarefa->finalDate = finalDate;

    return tarefa;
}

void removerTarefa(Tarefa *tarefa){
    free(tarefa);
}
