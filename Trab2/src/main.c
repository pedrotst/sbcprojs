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
 *  Arquivo fonte principal "main.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef uint32_t huge[8];

void init_huge(huge h){
    for(int i = 0 ; i < 8; i++){
        h[i] = 0;
    }
}

void str_to_huge(char* str, huge h){
    int i = strlen(str) - 1;
    int pow_index = 0;
    while(i >= 0){
        h[0] += (str[i] - '0') * pow(10, pow_index);
        i--; pow_index++;
    }

}

int main(int argc, char **argv){

    huge h;
    char num[79]; //maior numero de 255 bits tem tamanho 77, + sinal + \0
    strcpy(num, argv[1]); 
    init_huge(h);

    printf("%d  %s\n", argc, argv[1]);
    printf("%s\n", num);
    str_to_huge(num, h);
    printf("%" PRIu32 "\n", h[0]);
    return 0;
}
