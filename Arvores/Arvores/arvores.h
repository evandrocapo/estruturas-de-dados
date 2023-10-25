//
//  arvores.h
//  Arvores
//
//  Created by Evandro Douglas Capovilla Junior on 25/10/23.
//

#ifndef arvores_h
#define arvores_h

typedef struct NoArvore {
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArv;

typedef struct BaseArv {
    NoArv *raiz;
} Arv;

Arv* criarArvore(void);
Arv* removerArvore(Arv *raiz, int num);
int arvoreVazia(Arv *base);
void insereArvore(Arv *arvore, int num);
void imprimirPreOrder(NoArv *arvore);
void imprimirInOrder(NoArv *arvore);
void imprimirPosOrder(NoArv *arvore);

#endif /* arvores_h */
