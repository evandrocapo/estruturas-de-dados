/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    int numerosImpares = 1;
    int valor = 0;
    int i;
    
    printf("Bem vindo ao somador de numeros impares para obter o quadrado do numero desejado\n\n\n");
    printf("Para o funcionamento do sistema, digite apenas o numero desejado!\n");
    printf("Pressione o \"enter\" para continuar\n");
    getchar();
    
    system("cls");
    printf("Digite o numero desejado: ");
    scanf("%d", &number);
    
    for(i=0; i < number; i++){
        valor = valor + numerosImpares;
        numerosImpares = numerosImpares + 2;
    }
    
    printf("\n");
    
    printf("O quadrado do numero é: %d", valor);
    printf("\n\n");
    
    getchar();
    printf("Pressione \"ENTER\" para continuar");
    getchar();
    
    printf("Obrigado por utilizar o sistema :)\n");

    return 0;
}
