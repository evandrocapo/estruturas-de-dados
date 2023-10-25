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
#include <time.h>

int menuAlteracaoTarefa(void);

Tarefa *criarTarefa(int prioridade){
    Tarefa *tarefa = malloc((Tarefa *) sizeof(Tarefa));

    int code;
    printf("Digite o codigo da tarefa: ");
    scanf("%d", &code);
    tarefa->code = code;

    char name[30];
    printf("Digite o nome da tarefa: ");
    scanf("%s", name);
    strcpy(tarefa->name, name);

    char projeto[30];
    printf("Digite o nome do projeto: ");
    scanf("%s", projeto);
    strcpy(tarefa->projeto, projeto);

    int initialDate;
    printf("Digite a data inicial: ");
    scanf("%d", &initialDate);
    tarefa->initialDate = initialDate;

    int finalDate;
    printf("Digite a data final: ");
    scanf("%d", &finalDate);
    tarefa->finalDate = finalDate;
    
    tarefa->prioridade = prioridade;
    tarefa->status = 0;
    
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
            scanf("%d", &code);
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
            
            printf("Digite o nome do projeto: ");
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
    printf("Status: %d\n", tarefa->status);
    printf("Projeto: %s\n", tarefa->projeto);
    printf("Prioridade: %d\n", tarefa->prioridade);
    printf("Data inicial: %d\n", tarefa->initialDate);
    printf("Data final: %d\n\n", tarefa->finalDate);
}

Tarefa *atualizarStatusDaTarefa(Tarefa *tarefa){
    int diaAtual = obterDiaAtual();
    int mesAtual = obterMesAtual();
    int anoAtual = obterAnoAtual();

    int tarefaDiaAtual = obterTarefaDia(tarefa->finalDate);
    int tarefaMesAtual = obterTarefaMes(tarefa->finalDate);
    int tarefaAnoAtual = obterTarefaAno(tarefa->finalDate);
    
    tarefa->finalDate = obterDataAtual();
    
    if(tarefaAnoAtual >= anoAtual){
        if(tarefaMesAtual >= mesAtual){
            if(tarefaDiaAtual >= diaAtual){
                return tarefa;
            }
        }
    }
    
    tarefa->status = 1;
    return tarefa;
}

int tarefaUmMaiorTarefaDois(Tarefa *tarefa1, Tarefa *tarefa2){
    int tarefaUmDiaAtual = obterTarefaDia(tarefa1->finalDate);
    int tarefaUmMesAtual = obterTarefaMes(tarefa1->finalDate);
    int tarefaUmAnoAtual = obterTarefaAno(tarefa1->finalDate);
    
    int tarefaDoisDiaAtual = obterTarefaDia(tarefa2->finalDate);
    int tarefaDoisMesAtual = obterTarefaMes(tarefa2->finalDate);
    int tarefaDoisAnoAtual = obterTarefaAno(tarefa2->finalDate);
    
    if(tarefaUmDiaAtual > tarefaDoisDiaAtual){
        if(tarefaUmDiaAtual > tarefaDoisMesAtual){
            if(tarefaUmDiaAtual > tarefaDoisAnoAtual){
                return 1;
            }
        }
    }
    return 0;
}

void limparTarefa(Tarefa *tarefa){
    free(tarefa);
}
