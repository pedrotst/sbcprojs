/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2016
 *
 *  Codificadores Binários
 *
 *  Grupo 3:
 *      - Carlos Joel Tavares da Silva  13/0007293
 *      - Felipe Barreto Fernandes      09/0112831
 *      - Felipe Borges Albuquerque     09/93972
 *      - Géssica Neves Sodré da Silva  11/0146115
 *      - Pedro da Costa Abreu Júnior   11/0018800
 *
 *  Arquivo fonte "bib.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#include "bib.h"

// checa se uma das bases definidas foi escolhida
int existe_opcao(char opt){
    if(opt == '2' || opt == '4' || opt == '5' || opt == '1'){
        return 1;
    }
    return 0;
}

// checa se um arquivo existe
int existe_arquivo(const char *nome_arquivo){
    FILE *pt_arquivo;

    if((pt_arquivo = fopen(nome_arquivo, "r"))){
        fclose(pt_arquivo);
        return 1;
    }
    return 0;
}


