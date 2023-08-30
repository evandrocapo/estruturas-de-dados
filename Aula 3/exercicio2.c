//Exercicio 2:
// Faça um programa que realize a leitura dos seguintes dados
// relativos a um conjunto de alunos:
// • RA - inteiro
// • Código da Disciplina - inteiro de 4 dígitos
// • Nota1 e Nota 2 – valores reais que podem ser
// armazenados na forma de um vetor de 2 posições
// • Considere uma turma de até 10 alunos. Após ler todos os dados
// digitados, e depois de armazená-los em um vetor de estrutura,
// exibir na tela a listagem final dos alunos com as suas respectivas
// medias finais (use uma média ponderada: Nota1 com peso=1.0 e
// Nota2 com peso=2.0).

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int ra;
    int codigo;
    float notas[2];
} Aluno;

int main(int argc, const char * argv[]) {
    Aluno alunos[10];
    int i;
    
    for(i=0;i<10;i++){
        alunos[i].ra = i;
        alunos[i].codigo = rand() % 100;
        alunos[i].notas[0] = rand() % 10;
        alunos[i].notas[1] = rand() % 10;
        printf("RA: %d\n", alunos[i].ra);
        printf("Codigo da Disciplina: %d\n", alunos[i].codigo);
        printf("Nota 1: %f\n", alunos[i].notas[0]);
        printf("Nota 2: %f\n", alunos[i].notas[1]);
        printf("\n");
    }

    for(i=0; i<10;i++){
        float mediaFinal = (alunos[i].notas[0] * 1 + alunos[i].notas[1] * 2)/3;
        printf("Aluno de RA: %d, tem a media: %f\n\n", alunos[i].ra, mediaFinal);
    }
    
    return 0;
}
