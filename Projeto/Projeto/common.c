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
    
    return tm.tm_mon;
}

int obterAnoAtual(void){
    time_t tempoAtual;
    tempoAtual = time(NULL);
    struct tm tm = *localtime(&tempoAtual);
    
    return tm.tm_year;
}
