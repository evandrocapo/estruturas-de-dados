//
//  pilha.c
//  Tarefas
//
//  Created by Evandro Douglas Capovilla Junior on 30/08/23.
//

#include "arvore.h"
#include <stdlib.h>

Arvore *criarArvore(){
    Arvore arvore = malloc((Arvore *) sizeof(Arvore));
    return arvore;
}

void apagarArvore(Arvore *arvore){
    if(arvore != NULL){
        if(arvore->raiz != NULL){
            percorrerPosOrderApagar(arvore->raiz);
        }
        free(arvore);
    }
}

void apagarFolhasMasDeixarRaiz(Arvore *arvore){
    if(arvore != NULL){
        if(arvore->raiz != NULL){
            percorrerPosOrderApagar(arvore->raiz->direita);
            percorrerPosOrderApagar(arvore->raiz->esquerda);
        }
        
    }
}

NoArvore *criarFolha(){
    NoArvore folha = malloc((NoArvore *) sizeof(NoArvore));
    return folha;
}

// Arvore *inserirFolha(Arvore *arvore, int info){
//     Arvore
// }

void apagarFolha(NoArvore folha){
    free(folha);
}

void percorrerPosOrderApagar(NoArvore *folha){
    if(folha->direita != NULL){
        percorrerPosOrderApagar(folha->direita);
    }
    if(folha->esquerda != NULL){
        percorrerPosOrderApagar(folha->esquerda);
    }
    free(folha);
}

int percorrerPosOrderAncestrais(NoArvore *folha, int value){
    int ancestraisEncontrados = 0;
    if(folha->info == value){
        return 1;
    }
    if(folha->direita != NULL && ancestraisEncontrados == 0){
        ancestraisEncontrados = percorrerPosOrderAncestrais(folha->direita);
    }
    if(folha->esquerda != NULL && ancestraisEncontrados == 0){
        ancestraisEncontrados = percorrerPosOrderAncestrais(folha->esquerda);
    }

    if(ancestraisEncontrados > 0){
        return ancestraisEncontrados++;
    }
    return 0;
}

int ancestrais(NoArvore *arvore){
    int ancestraisEncontrados;
    if(arvore == NULL){
        return -1;
    }
    if(arvore->raiz !== NULL){
        return -1;
    }
    
    ancestraisEncontrados = percorrerPosOrderAncestrais(arvore->raiz);
    ancestraisEncontrados--;
    return ancestraisEncontrados;
}