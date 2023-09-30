//
//  common.c
//  Projeto
//
//  Created by Evandro Douglas Capovilla Junior on 20/09/23.
//

#include "common.h"
#include <stdlib.h>
#include <time.h>

void limparTela(void){
    system("cls");
}

int obterDiaAtual(void){
    time_t tempoAtual;
    tempoAtual = time(NULL);
    struct tm tm = *localtime(&tempoAtual);
    
    return tm.tm_mday;
}

int obterMesAtual(void){
    time_t tempoAtual;
    tempoAtual = time(NULL);
    struct tm tm = *localtime(&tempoAtual);
    
    return tm.tm_mon + 1; // +1 porque o mes é retornado como -1
}

int obterAnoAtual(void){
    time_t tempoAtual;
    tempoAtual = time(NULL);
    struct tm tm = *localtime(&tempoAtual);
    
    int ano = 0; int mult = 1;
    int i;
    
    for(i=0; i < 2; i++){
        ano = (ano + (tm.tm_year % 10)* mult);
        mult = mult * 10;
        tm.tm_year = tm.tm_year / 10; // pode ocorrer erro de data por causa dessa alteração direta na memoria ?
    }

    ano = 2000 + ano;
    
    return ano;
}

int obterTarefaDia(int date){
    int dia = 0; int mult = 1;
    int i;
    
    date = date / 1000000;
    
    for(i=0; i < 2; i++){
        dia = (dia + (date % 10)* mult);
        mult = mult * 10;
        date = date / 10;
    }
    
    return dia;
}

int obterTarefaMes(int date){
    int mes = 0; int mult = 1;
    int i;
    
    date = date / 10000;
    
    for(i=0; i < 2; i++){
        mes = (mes + (date % 10)* mult);
        mult = mult * 10;
        date = date / 10;
    }
    
    return mes;
}

int obterTarefaAno(int date){
    int ano = 0; int mult = 1;
    int i;
    
    for(i=0; i < 4; i++){
        ano = (ano + (date % 10)* mult);
        mult = mult * 10;
        date = date / 10;
    }
    
    return ano;
}
