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
    printf("%d %d %d %d\n", h[3], h[2], h[1], h[0]);
    huge_to_str(h, num);
    //printf("%" PRIu32, h[3]); // eu sei q eh estranho, mas eh assim q printa uint32_t
    //printf("%" PRIu32, h[2]);
    printf("%" PRIu32"\n", h[1]);
    printf("%" PRIu32 "\n", h[0]);
    printf("%s\n", num);

    /* testing if functions works
     * char *tst = ":;<=>?@ABC";
    for(int i=0; i < strlen(tst); i++){
        printf("%c\n", intochar(chtoi(tst[i])));
    }
    */
    return 0;
}
