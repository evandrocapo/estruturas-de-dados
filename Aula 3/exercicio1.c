// Exercicio 1:
// Elabore um programa que crie uma estrutura com as
// seguintes informações de um produto:
// • Código do produto – inteiro de 3 dígitos
// • Quantidade em estoque - inteiro
// • Valor de compra - real
// • Valor de Venda - real
// • O programa deverá ler a informação de 10 produtos e
// determinar
// • O código do produto com maior quantidade de estoque
// • O quantidade de estoque do produto que proporciona
// o maior lucro

#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    int code;
    int quantidade;
    float valorCompra;
    float valorVenda;
} Produto;

int main(int argc, const char * argv[]) {
    Produto produtos[10];
    Produto produtoSelecionado;
    int i;
    
    for(i=0;i<10;i++){
        produtos[i].code = i;
        produtos[i].quantidade = rand() % 100;
        produtos[i].valorCompra = rand() % 100;
        produtos[i].valorVenda = rand() % 100;
        printf("Codigo: %d\n", produtos[i].code);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Valor Compra:%f\n", produtos[i].valorCompra);
        printf("Valor Venda:%f\n", produtos[i].valorVenda);
        printf("Lucro:%f\n", produtos[i].valorVenda - produtos[i].valorCompra);
        printf("\n");
    }
    
    produtoSelecionado = produtos[0];
    for(i=1; i<10;i++){
        if(produtoSelecionado.quantidade < produtos[i].quantidade){
            produtoSelecionado = produtos[i];
        }
    }
    
    printf("Produto %d tem a maior quantidade de estoque\n\n", produtoSelecionado.code);
    
    produtoSelecionado = produtos[0];
    for(i=1; i<10;i++){
        float lucroSelecionado, lucroAtual;
        
        lucroSelecionado = produtoSelecionado.valorVenda - produtoSelecionado.valorCompra;
        lucroAtual = produtos[i].valorVenda - produtos[i].valorCompra;
        
        if(lucroSelecionado < lucroAtual) {
            produtoSelecionado = produtos[i];
        }
    }
    
    printf("Produto %d tem a maior lucro\n", produtoSelecionado.code);
    printf("Seu estoque e de %d \n", produtoSelecionado.quantidade);
    
    return 0;
}
