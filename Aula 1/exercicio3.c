/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, i, j = 0;
    int *conjuntoNumerosDivisiveis;
    int total=0;

    scanf("%d", &number);

    conjuntoNumerosDivisiveis = malloc(number * sizeof(int));

    for(i=1; i < number; i++){
        int notDivisible = number % i;
        if(!notDivisible){
            *(conjuntoNumerosDivisiveis + j) = i;
            printf("%d ", *(conjuntoNumerosDivisiveis + j));
            j++;
        }
    }

    for(i=0; i < j; i++){
        // printf("\ntotal = %d, numero = %d", total, *(conjuntoNumerosDivisiveis + i));
        total = total + *(conjuntoNumerosDivisiveis + i);
    }

    printf("\nO valor total é: %d", total);

    if(number > total) {
        printf("\n\n O numero é deficiente");
    } else {
        printf("\n\n O numero NAO é deficiente");
    }

    return 0;
}
