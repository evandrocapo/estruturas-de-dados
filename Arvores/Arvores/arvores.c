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
int qntNosInternoAux(NoArv *no);
void removerArvoreAux(NoArv *raiz);
NoArv* removeItemArvoreAux(NoArv *arvore, int num);

Arv* criarArvore(void) {
    Arv *aux;
    aux = (Arv*) malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;
}

Arv* removerArvore(Arv *arvore){
    if(arvoreVazia(arvore) == 0){
        removerArvoreAux(arvore->raiz);
    }
    free(arvore);
    return NULL;
}

void removerArvoreAux(NoArv *raiz){
    if (raiz != NULL){
        removerArvoreAux(raiz->dir);
        removerArvoreAux(raiz->esq);
        free(raiz);
    }
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

Arv* removeItemArvore(Arv *arvore, int num){
    if(arvoreVazia(arvore) == 0){
        arvore->raiz = removeItemArvoreAux(arvore->raiz, num);
    }
    
    return arvore;
}

NoArv* removeItemArvoreAux(NoArv *arvore, int num){
    if (arvore == NULL){
        return NULL;
    } else if (arvore->info > num){
        arvore->esq = removeItemArvoreAux(arvore->esq, num);
    } else if (arvore->info < num){
        arvore->dir = removeItemArvoreAux(arvore->dir, num);
    } else { /* achou o elemento */
        if (arvore->esq == NULL && arvore->dir == NULL) { /* elemento sem filhos */
            free(arvore);
            arvore = NULL;
        }
        else if (arvore->esq == NULL) { /* só tem filho à direita */
            NoArv* t = arvore;
            arvore = arvore->dir;
            free(t);
        }
        else if (arvore->dir == NULL) { /* só tem filho à esquerda */
            NoArv* t = arvore;
            arvore = arvore->esq;
            free(t);
        }
        else { /* tem os dois filhos */
            NoArv* pai = arvore;
            NoArv* f = arvore->esq;
            while (f->dir != NULL) {
                pai = f;
                f = f->dir;
            }
            arvore->info = f->info; /* troca as informações */
            f->info = num;
            arvore->esq = removeItemArvoreAux(arvore->esq,num);
        }
    }
    return r;
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

int busca(NoArv *no, int num){
    if(no == NULL){
        return 0;
    }
    if(no->info == num){
        return 1;
    }
    if(num > no->info){
        return busca(no->dir, num);
    } else {
        return busca(no->esq, num);
    }
}

int qntNosInterno(Arv *arvore){
    NoArv *raiz = arvore->raiz;
    
    if(raiz == NULL){
        return 0;
    }
    
    if(raiz->esq == NULL && raiz->dir == NULL){
        return 0;
    }
    
    return qntNosInternoAux(raiz->esq) + qntNosInternoAux(raiz->dir);
}

int qntNosInternoAux(NoArv *no){
    if(no == NULL){
        return 0;
    }
    
    if(no->esq != NULL || no->dir != NULL){
        return 1 + qntNosInternoAux(no->esq) + qntNosInternoAux(no->dir);
    }
    
    return 0;
}
