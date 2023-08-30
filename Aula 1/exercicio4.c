/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define numerosMax 5

int main()
{
    float numeros[numerosMax];
    int i;
    float total;
    float media;
    int quantidadeNumerosMaiorQueMedia = 0;
    
    for(i = 0; i < numerosMax; i++){ 
        scanf("%f", &numeros[i]);
        printf("%f\n", numeros[i]);
    }
    
    for(i=0; i < numerosMax; i++){
        total = numeros[i];
    }
    
    media = total / 2;
    
    printf("\nmedia: %f", media);
    
    for(i=0; i < numerosMax; i++){
        if(numeros[i] > media){
            quantidadeNumerosMaiorQueMedia++;
        }
    }
    
    printf("\nquantidadeNumerosMaiorQueMedia: %d", quantidadeNumerosMaiorQueMedia);

    return 0;
}
