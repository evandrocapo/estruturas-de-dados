//
//  arvores.c
//  Arvores
//
//  Created by Evandro Douglas Capovilla Junior on 25/10/23.
//

#include "arvores.h"
#include <stdio.h>
#include <stdlib.h>

NoArv* insereArvoreAux(NoArv *no, int num);

Arv* criarArvore(void) {
    Arv *aux;
    aux = (Arv*) malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

Arv* removerArvore(Arv *raiz, int num){
    return NULL;
}

int arvoreVazia(Arv *arvore){
    if(arvore->raiz == NULL){
        return 1;
    }
    
    return 0;
}

void insereArvore(Arv *arvore, int num){
    arvore->raiz = insereArvoreAux(arvore->raiz, num);
}

NoArv* insereArvoreAux(NoArv *no, int num){
    int flag;
    NoArv *pai;
    NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if(no == NULL){
        return novo;
    } else {
        pai = no;
        flag = 0;
        while (flag == 0) {
            if(pai->info < num){
                if(pai->dir == NULL){
                    pai->dir = novo;
                    flag = 1;
                } else {
                    pai = pai->dir;
                }
            } else if(pai->info > num){
                if(pai->esq == NULL){
                    pai->esq = novo;
                    flag = 1;
                } else {
                    pai = pai->esq;
                }
            } else {
                // pai->info == num
                flag = 1;
            }
        }
    }
    return no;
}

void imprimirPreOrder(NoArv *no){
    printf("%d", no->info);
    if(no->dir != NULL){
        imprimirPreOrder(no->dir);
    }
    if(no->esq != NULL){
        imprimirPreOrder(no->esq);
    }
}

void imprimirInOrder(NoArv *no){
    if(no->dir != NULL){
        imprimirInOrder(no->dir);
    }
    printf("%d", no->info);
    if(no->esq != NULL){
        imprimirInOrder(no->esq);
    }
}

void imprimirPosOrder(NoArv *no){
    if(no->dir != NULL){
        imprimirPosOrder(no->dir);
    }
    if(no->esq != NULL){
        imprimirPosOrder(no->esq);
    }
    printf("%d", no->info);
}
