//
//  pilha.h
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 06/09/23.
//

#ifndef arvore_h
#define arvore_h

#include <stdio.h>

typedef struct noArvore {
    int info;
    struct noArvore *esq;
    struct noArvore *dir;
} NoArvore;

typedef struct arvore {
    struct noArvore *raiz;
} Arvore;

Arvore *criarArvore();
void apagarArvore(Arvore *arvore);
void apagarFolhasMasDeixarRaiz(Arvore *arvore);
NoArvore *criarFolha();
int ancestrais(NoArvore *arvore);

#endif /* arvore_h */
