/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2016
 *
 *  Máquina de Pilha e aritmética via software
 *
 *  Grupo 3:
 *      - Carlos Joel Tavares da Silva  13/0007293
 *      - Felipe Barreto Fernandes      09/0112831
 *      - Felipe Borges Albuquerque     09/93972
 *      - Géssica Neves Sodré da Silva  11/0146115
 *      - Pedro da Costa Abreu Júnior   11/0018800
 *
 *  Arquivo fonte principal "main.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#include "utils.h"

int main(int argc, char **argv){

    huge h;
    char num[79]; //maior numero de 255 bits tem tamanho 77, + sinal + \0
    strcpy(num, argv[1]); 
    init_huge(h);
    printf("%d  %s\n", argc, argv[1]);
    printf("%s \n", num );
    str_to_huge(num, h);
    printf("%" PRIu32 "\n", h[0]);

    /* testing if functions works
     * char *tst = ":;<=>?@ABC";
    for(int i=0; i < strlen(tst); i++){
        printf("%c\n", intochar(chtoi(tst[i])));
    }
    */
    return 0;
}
