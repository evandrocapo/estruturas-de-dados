//Lista
//Exercicio de Lista


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} Lista;

Lista *insereLista(Lista *recebido, int valor);
Lista *removerLista(Lista *recebido);
int vazio(Lista *recebido);
void leitura(Lista *recebido);

int main(int argc, const char * argv[]) {
    Lista *lista = NULL;
    
    printf("adicionando 3 valores: \n");
    lista = insereLista(lista, 10);
    lista = insereLista(lista, 20);
    lista = insereLista(lista, 30);
    leitura(lista);
    
    printf("Removendo 1 valor: \n");
    lista = removerLista(lista);
    leitura(lista);
    
    printf("%d\n", lista->valor);
    
    return 0;
}

Lista *insereLista(Lista *recebido, int valor){
    Lista *novo;
    novo = (Lista *) malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = recebido;
    return novo;
}

Lista *removerLista(Lista *recebido){
    Lista *atual = recebido->prox;
    free(recebido);
    
    return atual;
}

int vazio(Lista *recebido){
    if(recebido == NULL) return 1;
    return 0;
}

void leitura(Lista *recebido){
    int isVazio;
    Lista *listaAtual = recebido;
    
    do{
        isVazio = vazio(listaAtual);
        if(isVazio == 0) {
            printf("Valor: %d\n", listaAtual->valor);
            listaAtual = listaAtual->prox;
        }
    } while(isVazio != 1);
}
