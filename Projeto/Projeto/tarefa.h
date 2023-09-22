//
//  tarefa.h
//  Tarefa
//
//  Created by Evandro Douglas Capovilla Junior on 18/09/23.
//

#ifndef TAREFA_H_INCLUDED
#define TAREFA_H_INCLUDED

typedef struct tarefa {
    int code;
    char name[30];
    char projeto[30];
    int initialDate;
    int finalDate;
    int status;
    int prioridade;
} Tarefa;

Tarefa *criarTarefa(void);
void editarTarefa(Tarefa *tarefa);
void lerTarefa(Tarefa *tarefa);

#endif // TAREFA_H_INCLUDED
