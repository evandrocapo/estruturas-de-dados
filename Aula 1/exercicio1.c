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
    int i;
    int primo;
    
    printf("Bem vindo ao verificador de numeros primos\n\n\n");
    printf("Para o funcionamento do sistema, digite apenas o numero desejado!\n");
    printf("Para cancelar o programa digite o numero 0\n");
    printf("Pressione o \"enter\" para continuar\n");
    getchar();
    
    do{
        primo = 1;
        system("cls");
        printf("Digite o numero desejado: ");
        scanf("%d", &number);
        
        for(i=2; i < number/2;i++){
            if(number % i == 0) {
                primo = 0;
            }
        }
        
        printf("\n");
        
        if(primo){
            printf("O numero %d e primo\n\n", number);
        } else {
            printf("O numero %d NAO e primo\n\n", number);
        }
        
        getchar();
        printf("Pressione \"ENTER\" para continuar");
        getchar();
    }while(number != 0);
    
    printf("Obrigado por utilizar o sistema :)\n");

    return 0;
}
