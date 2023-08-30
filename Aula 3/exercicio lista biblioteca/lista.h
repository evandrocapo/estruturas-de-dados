// Lista
// Exercicio de Lista

#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct no {
    int valor;
    struct no *prox;
} Lista;


Lista *insereLista(Lista *recebido, int valor);
Lista *removerLista(Lista *recebido);
int removerListaRetornandoValorRemovido(Lista **recebido);
int vazio(Lista *recebido);
void leitura(Lista *recebido);

#endif /* lista_h */
