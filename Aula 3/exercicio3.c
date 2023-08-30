//Exercicio 3:
// A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes,
// coletando dados sobre o salário, idade, sexo e número de filhos. Use a
// estrutura seguinte...
// struct dados{
// int idade, filhos;
// float salario;
// int sexo;
// }
// ...faça um programa que leia os dados de 100 habitantes e calcule:
// • A média de idade das mulheres com salário inferior ao salário
// mínimo.
// • A média de salário da população.
// • A média do número de filhos.
// • A menor idade do sexo feminino.


#include <stdio.h>
#include <stdlib.h>

typedef struct habitante {
    int idade, filhos, sexo;
    float salario;
} Habitante;

int main(int argc, const char * argv[]) {
    int quantidade=0, mediaIdade=0, filhosMedioPopulacao=0, menorIdadeFeminino=0;
    float salarioMedioPopulacao=0;
    const float salarioMinimo = 1320;
    Habitante habitantes[100];
    int i;
    
    for(i=0;i<100;i++){
        habitantes[i].idade = 20 + rand() % 80;
        habitantes[i].filhos = rand() % 10;
        habitantes[i].sexo = rand() % 2;
        habitantes[i].salario = rand() % 10000;
        printf("Idade: %d\n", habitantes[i].idade);
        printf("Filhos: %d\n", habitantes[i].filhos);
        printf("Sexo: %d\n", habitantes[i].sexo);
        printf("Salario: %f\n", habitantes[i].salario);
        printf("\n");
    }
    
    for(i=0; i<100;i++){
        if(habitantes[i].sexo == 1){
            if(habitantes[i].salario < salarioMinimo){
                quantidade++;
                mediaIdade = mediaIdade + habitantes[i].idade;
            }
            
            if(menorIdadeFeminino == 0){
                menorIdadeFeminino = habitantes[i].idade;
            }
            if(menorIdadeFeminino > habitantes[i].idade) {
                menorIdadeFeminino = habitantes[i].idade;
            }
        }
        
        salarioMedioPopulacao = salarioMedioPopulacao + habitantes[i].salario;
        filhosMedioPopulacao = filhosMedioPopulacao + habitantes[i].filhos;
    }
    mediaIdade = mediaIdade / quantidade;
    salarioMedioPopulacao = salarioMedioPopulacao / 100;
    filhosMedioPopulacao = filhosMedioPopulacao / 100;
    
    printf("A média da idade das mulheres com salarios inferiores que o salario minimo: %d\n", mediaIdade);
    printf("A média de salário da população: %f\n", salarioMedioPopulacao);
    printf("A média do número de filhos: %d\n", filhosMedioPopulacao);
    printf("A menor idade do sexo feminino: %d\n", menorIdadeFeminino);
    
    return 0;
}
