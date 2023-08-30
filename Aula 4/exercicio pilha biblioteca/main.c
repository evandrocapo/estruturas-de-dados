//Lista
//Exercicio de Lista


#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, const char * argv[]) {
    Pilha *pilha = NULL;
    int valorRemovido = 0, pilhaVazia = 0;
    
    printf("Criando pilha: \n");
    pilha = criarPilha();
    
    pilhaVazia = vazioPilha(pilha);
    printf("A pilha está vazia \"0\": NAO, \"1\": SIM -> %d\n\n", pilhaVazia);
    
    leituraPilha(pilha);
    
    printf("Adicionando 3 valores: \n");
    pilha = push(pilha, 10);
    pilha = push(pilha, 20);
    pilha = push(pilha, 30);
    
    leituraPilha(pilha);
    
    pilhaVazia = vazioPilha(pilha);
    printf("A pilha está vazia \"0\": NAO, \"1\": SIM -> %d\n\n", pilhaVazia);
    
    printf("Removendo 1 valor: \n");
    valorRemovido = pop(&pilha);
    printf("O valor é: %d\n\n", valorRemovido);
    
    printf("Adicionando 1 valor: \n");
    pilha = push(pilha, 40);
    
    leituraPilha(pilha);
    
    printf("\nLiberando pilha\n");
    liberaPilha(&pilha);
    
    pilhaVazia = vazioPilha(pilha);
    printf("A pilha está vazia \"0\": NAO, \"1\": SIM -> %d\n\n", pilhaVazia);
    
    return 0;
}
