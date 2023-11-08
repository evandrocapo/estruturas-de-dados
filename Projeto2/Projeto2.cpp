// Projeto2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"
#include <time.h>

double executarTesteDezMil(int sort, int seed);
double executarTesteCinquentaMil(int sort, int seed);
double executarTesteCemMil(int sort, int seed);
double executarTesteQuinhentosMil(int sort, int seed);
double executarTesteUmMilhao(int sort, int seed);
void bubbleSortTest(void);
void insertionSortTest(void);
void shellSortTest(void);
void mergeSortTest(void);
void quickSortLiTest(void);
void quickSortLsTest(void);
void quickSortMidTest(void);

int main(void)
{
//    bubbleSortTest();
//    insertionSortTest();
//    shellSortTest();
//    mergeSortTest();
//    quickSortLiTest();
//    quickSortLsTest();
    quickSortMidTest();
    
    //executarTesteCinquentaMil(1, 200);


    //Insertion Sort
    //executarTesteDezMil(2, 200);
    //executarTesteCinquentaMil(2, 200);

    //Shell Sort
    //executarTesteDezMil(3, 200);

    //Merge Sort
    //executarTesteDezMil(4, 200);

    //Quick Sort - LI
    //executarTesteDezMil(5, 200);

    //Quick Sort - LS
    //executarTesteDezMil(6, 200);

    //Quick Sort - Meio
//    executarTesteDezMil(7, 200);

    //Radix Sort
   // executarTesteDezMil(8, 200);
}

void bubbleSortTest(void){
    //Bubble Sort - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;
    
    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(1, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Dez Mil: \n");
    printf("Bubble Sort MIN: %f\n", min);
    printf("Bubble Sort media: %f\n", media);
    printf("Bubble Sort MAX: %f\n", max);
    
    //Bubble Sort - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(1, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Cinquenta Mil: \n");
    printf("Bubble Sort MIN: %f\n", min);
    printf("Bubble Sort media: %f\n", media);
    printf("Bubble Sort MAX: %f\n", max);
    
    //Bubble Sort - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(1, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Cem Mil: \n");
    printf("Bubble Sort MIN: %f\n", min);
    printf("Bubble Sort media: %f\n", media);
    printf("Bubble Sort MAX: %f\n", max);
    
    //Bubble Sort - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(1, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Quinhentos Mil: \n");
    printf("Bubble Sort MIN: %f\n", min);
    printf("Bubble Sort media: %f\n", media);
    printf("Bubble Sort MAX: %f\n", max);
    
    //Bubble Sort - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(1, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Um Milhao: \n");
    printf("Bubble Sort MIN: %f\n", min);
    printf("Bubble Sort media: %f\n", media);
    printf("Bubble Sort MAX: %f\n", max);
}

void insertionSortTest(void){
    //Insertion Sort - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;
    
    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(2, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Dez Mil: \n");
    printf("Insertion Sort MIN: %f\n", min);
    printf("Insertion Sort media: %f\n", media);
    printf("Insertion Sort MAX: %f\n", max);
    
    //Insertion Sort - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(2, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Cinquenta Mil: \n");
    printf("Insertion Sort MIN: %f\n", min);
    printf("Insertion Sort media: %f\n", media);
    printf("Insertion Sort MAX: %f\n", max);
    
    //Insertion Sort - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(2, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Cem Mil: \n");
    printf("Insertion Sort MIN: %f\n", min);
    printf("Insertion Sort media: %f\n", media);
    printf("Insertion Sort MAX: %f\n", max);
    
    //Insertion Sort - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(2, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Quinhentos Mil: \n");
    printf("Insertion Sort MIN: %f\n", min);
    printf("Insertion Sort media: %f\n", media);
    printf("Insertion Sort MAX: %f\n", max);
    
    //Insertion Sort - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(2, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }
    
    printf("Um Milhao: \n");
    printf("Insertion Sort MIN: %f\n", min);
    printf("Insertion Sort media: %f\n", media);
    printf("Insertion Sort MAX: %f\n", max);
}

void shellSortTest(void){
    //Shell Sort - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;

    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(3, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Dez Mil: \n");
    printf("Shell Sort MIN: %f\n", min);
    printf("Shell Sort media: %f\n", media);
    printf("Shell Sort MAX: %f\n", max);

    //Shell Sort - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(3, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cinquenta Mil: \n");
    printf("Shell Sort MIN: %f\n", min);
    printf("Shell Sort media: %f\n", media);
    printf("Shell Sort MAX: %f\n", max);

    //Shell Sort - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(3, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cem Mil: \n");
    printf("Shell Sort MIN: %f\n", min);
    printf("Shell Sort media: %f\n", media);
    printf("Shell Sort MAX: %f\n", max);

    //Shell Sort - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(3, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Quinhentos Mil: \n");
    printf("Shell Sort MIN: %f\n", min);
    printf("Shell Sort media: %f\n", media);
    printf("Shell Sort MAX: %f\n", max);

    //Shell Sort - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(3, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Um Milhao: \n");
    printf("Shell Sort MIN: %f\n", min);
    printf("Shell Sort media: %f\n", media);
    printf("Shell Sort MAX: %f\n", max);
}

void mergeSortTest(void) {
    //Merge Sort - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;

    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(4, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Dez Mil: \n");
    printf("Merge Sort MIN: %f\n", min);
    printf("Merge Sort media: %f\n", media);
    printf("Merge Sort MAX: %f\n", max);

    //Merge Sort - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(4, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cinquenta Mil: \n");
    printf("Merge Sort MIN: %f\n", min);
    printf("Merge Sort media: %f\n", media);
    printf("Merge Sort MAX: %f\n", max);

    //Merge Sort - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(4, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cem Mil: \n");
    printf("Merge Sort MIN: %f\n", min);
    printf("Merge Sort media: %f\n", media);
    printf("Merge Sort MAX: %f\n", max);

    //Merge Sort - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(4, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Quinhentos Mil: \n");
    printf("Merge Sort MIN: %f\n", min);
    printf("Merge Sort media: %f\n", media);
    printf("Merge Sort MAX: %f\n", max);

    //Merge Sort - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(4, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Um Milhao: \n");
    printf("Merge Sort MIN: %f\n", min);
    printf("Merge Sort media: %f\n", media);
    printf("Merge Sort MAX: %f\n", max);
}

void quickSortLiTest(void){
    //Quick Sort LI - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;

    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(5, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Dez Mil: \n");
    printf("Quick Sort LI MIN: %f\n", min);
    printf("Quick Sort LI media: %f\n", media);
    printf("Quick Sort LI MAX: %f\n", max);

    //Quick Sort LI - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(5, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cinquenta Mil: \n");
    printf("Quick Sort LI MIN: %f\n", min);
    printf("Quick Sort LI media: %f\n", media);
    printf("Quick Sort LI MAX: %f\n", max);

    //Quick Sort LI - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(5, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cem Mil: \n");
    printf("Quick Sort LI MIN: %f\n", min);
    printf("Quick Sort LI media: %f\n", media);
    printf("Quick Sort LI MAX: %f\n", max);

    //Quick Sort LI - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(5, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Quinhentos Mil: \n");
    printf("Quick Sort LI MIN: %f\n", min);
    printf("Quick Sort LI media: %f\n", media);
    printf("Quick Sort LI MAX: %f\n", max);

    //Quick Sort LI - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(5, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Um Milhao: \n");
    printf("Quick Sort LI MIN: %f\n", min);
    printf("Quick Sort LI media: %f\n", media);
    printf("Quick Sort LI MAX: %f\n", max);
}

void quickSortLsTest(void){
    //Quick Sort LS - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;

    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(6, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Dez Mil: \n");
    printf("Quick Sort LS MIN: %f\n", min);
    printf("Quick Sort LS media: %f\n", media);
    printf("Quick Sort LS MAX: %f\n", max);

    //Quick Sort LS - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(6, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cinquenta Mil: \n");
    printf("Quick Sort LS MIN: %f\n", min);
    printf("Quick Sort LS media: %f\n", media);
    printf("Quick Sort LS MAX: %f\n", max);

    //Quick Sort LS - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(6, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cem Mil: \n");
    printf("Quick Sort LS MIN: %f\n", min);
    printf("Quick Sort LS media: %f\n", media);
    printf("Quick Sort LS MAX: %f\n", max);

    //Quick Sort LS - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(6, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Quinhentos Mil: \n");
    printf("Quick Sort LS MIN: %f\n", min);
    printf("Quick Sort LS media: %f\n", media);
    printf("Quick Sort LS MAX: %f\n", max);

    //Quick Sort LS - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(6, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Um Milhao: \n");
    printf("Quick Sort LS MIN: %f\n", min);
    printf("Quick Sort LS media: %f\n", media);
    printf("Quick Sort LS MAX: %f\n", max);
}

void quickSortMidTest(void){
    //Quick Sort MID - 10.000
    double min = 20000000;
    double max = -200;
    double media = 0;
    double atual = 0;

    for(int i = 0; i< 10; i++){
        atual = executarTesteDezMil(7, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Dez Mil: \n");
    printf("Quick Sort MID MIN: %f\n", min);
    printf("Quick Sort MID media: %f\n", media);
    printf("Quick Sort MID MAX: %f\n", max);

    //Quick Sort MID - 50.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCinquentaMil(7, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cinquenta Mil: \n");
    printf("Quick Sort MID MIN: %f\n", min);
    printf("Quick Sort MID media: %f\n", media);
    printf("Quick Sort MID MAX: %f\n", max);

    //Quick Sort MID - 100.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteCemMil(7, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Cem Mil: \n");
    printf("Quick Sort MID MIN: %f\n", min);
    printf("Quick Sort MID media: %f\n", media);
    printf("Quick Sort MID MAX: %f\n", max);

    //Quick Sort MID - 500.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteQuinhentosMil(7, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Quinhentos Mil: \n");
    printf("Quick Sort MID MIN: %f\n", min);
    printf("Quick Sort MID media: %f\n", media);
    printf("Quick Sort MID MAX: %f\n", max);

    //Quick Sort MID - 1.000.000
    min = 20000000;
    max = -200;
    media = 0;
    atual = 0;
    for(int i = 0; i< 10; i++){
        atual = executarTesteUmMilhao(7, 200 + i * 10);
        
        if(media == 0) {
            media = atual;
        } else {
            media = (media + atual) / 2;
        }
        
        if(atual > max){
            max = atual;
        }
        if(atual < min) {
            min = atual;
        }
    }

    printf("Um Milhao: \n");
    printf("Quick Sort MID MIN: %f\n", min);
    printf("Quick Sort MID media: %f\n", media);
    printf("Quick Sort MID MAX: %f\n", max);
}

double executarTesteDezMil(int sort, int seed) {
    const int DEZMIL = 10000;
    ChaveValor arrOne[DEZMIL] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, DEZMIL, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[DEZMIL];

        t = clock();
        mergesortORG(arrOne, DEZMIL, output);
        t = clock() - t;
    }
    else if (sort == 5) {
        t = clock();
        quicksortLI(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 6) {
        t = clock();
        quicksortLS(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 7) {
        t = clock();
        quicksortMEIO(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 8) {
        ChaveValor output[DEZMIL + 1];
        int count[DEZMIL + 1];

        t = clock();
        radixsortORG(arrOne, DEZMIL, output, count);
        t = clock() - t;
    }

//    int deubom = 1;
//    for (int i = 0; i < DEZMIL -1; i++) {
//        if (arrOne[i].chave < arrOne[i + 1].chave) deubom = 0;
//    }
//
//    for (int i = 0; i < DEZMIL; i++) {
//        printf("%d ", arrOne[i].chave);
//    }
//    printf("\n");
    
//    printf("seed: %d", seed);

//    printf("\ndeu bom: %d", deubom);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
//    printf("\nO programa levou %f segundo para ordenar\n\n", time_taken);
    return time_taken;
}

double executarTesteCinquentaMil(int sort, int seed) {
    const int DEZMIL = 50000;
    ChaveValor arrOne[DEZMIL] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, DEZMIL, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[DEZMIL];

        t = clock();
        mergesortORG(arrOne, DEZMIL, output);
        t = clock() - t;
    }
    else if (sort == 5) {
        t = clock();
        quicksortLI(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 6) {
        t = clock();
        quicksortLS(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 7) {
        t = clock();
        quicksortMEIO(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 8) {
        ChaveValor output[DEZMIL + 1];
        int count[DEZMIL + 1];

        t = clock();
        radixsortORG(arrOne, DEZMIL, output, count);
        t = clock() - t;
    }

//    int deubom = 1;
//    for (int i = 0; i < DEZMIL -1; i++) {
//        if (arrOne[i].chave < arrOne[i + 1].chave) deubom = 0;
//    }
//
//    for (int i = 0; i < DEZMIL; i++) {
//        printf("%d ", arrOne[i].chave);
//    }

//    printf("\ndeu bom: %d", deubom);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
//    printf("\nO programa levou %f segundo para ordenar\n\n", time_taken);
    return time_taken;
}

double executarTesteCemMil(int sort, int seed) {
    const int DEZMIL = 100000;
    ChaveValor arrOne[DEZMIL] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, DEZMIL, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[DEZMIL];

        t = clock();
        mergesortORG(arrOne, DEZMIL, output);
        t = clock() - t;
    }
    else if (sort == 5) {
        t = clock();
        quicksortLI(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 6) {
        t = clock();
        quicksortLS(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 7) {
        t = clock();
        quicksortMEIO(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 8) {
        ChaveValor output[DEZMIL + 1];
        int count[DEZMIL + 1];

        t = clock();
        radixsortORG(arrOne, DEZMIL, output, count);
        t = clock() - t;
    }

//    int deubom = 1;
//    for (int i = 0; i < DEZMIL -1; i++) {
//        if (arrOne[i].chave < arrOne[i + 1].chave) deubom = 0;
//    }
//
//    for (int i = 0; i < DEZMIL; i++) {
//        printf("%d ", arrOne[i].chave);
//    }

//    printf("\ndeu bom: %d", deubom);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
//    printf("\nO programa levou %f segundo para ordenar\n\n", time_taken);
    return time_taken;
}

double executarTesteQuinhentosMil(int sort, int seed) {
    const int DEZMIL = 500000;
    ChaveValor arrOne[DEZMIL] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, DEZMIL, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[DEZMIL];

        t = clock();
        mergesortORG(arrOne, DEZMIL, output);
        t = clock() - t;
    }
    else if (sort == 5) {
        t = clock();
        quicksortLI(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 6) {
        t = clock();
        quicksortLS(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 7) {
        t = clock();
        quicksortMEIO(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 8) {
        ChaveValor output[DEZMIL + 1];
        int count[DEZMIL + 1];

        t = clock();
        radixsortORG(arrOne, DEZMIL, output, count);
        t = clock() - t;
    }

//    int deubom = 1;
//    for (int i = 0; i < DEZMIL -1; i++) {
//        if (arrOne[i].chave < arrOne[i + 1].chave) deubom = 0;
//    }
//
//    for (int i = 0; i < DEZMIL; i++) {
//        printf("%d ", arrOne[i].chave);
//    }

//    printf("\ndeu bom: %d", deubom);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
//    printf("\nO programa levou %f segundo para ordenar\n\n", time_taken);
    return time_taken;
}

double executarTesteUmMilhao(int sort, int seed) {
    const int DEZMIL = 1000000;
    ChaveValor arrOne[DEZMIL] = { 0 };
    clock_t t;
    t = 0;

    preencherVetor(arrOne, DEZMIL, seed);

    if (sort == 1) {
        t = clock();
        bubblesort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 2) {
        t = clock();
        insertionsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 3) {
        t = clock();
        shellsort(arrOne, DEZMIL);
        t = clock() - t;
    }
    else if (sort == 4) {
        ChaveValor output[DEZMIL];

        t = clock();
        mergesortORG(arrOne, DEZMIL, output);
        t = clock() - t;
    }
    else if (sort == 5) {
        t = clock();
        quicksortLI(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 6) {
        t = clock();
        quicksortLS(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 7) {
        t = clock();
        quicksortMEIO(arrOne, 0, DEZMIL - 1);
        t = clock() - t;
    }
    else if (sort == 8) {
        ChaveValor output[DEZMIL + 1];
        int count[DEZMIL + 1];

        t = clock();
        radixsortORG(arrOne, DEZMIL, output, count);
        t = clock() - t;
    }

//    int deubom = 1;
//    for (int i = 0; i < DEZMIL -1; i++) {
//        if (arrOne[i].chave < arrOne[i + 1].chave) deubom = 0;
//    }
//
//    for (int i = 0; i < DEZMIL; i++) {
//        printf("%d ", arrOne[i].chave);
//    }

//    printf("\ndeu bom: %d", deubom);
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
//    printf("\nO programa levou %f segundo para ordenar\n\n", time_taken);
    return time_taken;
}



// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar:
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
