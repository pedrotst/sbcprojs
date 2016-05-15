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
    
    str_to_huge(num, h);
    printf("Resultado 256bits\n");
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", int2bin(h[7]), int2bin(h[6]), int2bin(h[5]), int2bin(h[4]), int2bin(h[3]), int2bin(h[2]), int2bin(h[1]), int2bin(h[0]));
    
    huge_to_str(h, num);
    printf("Resultado em blocos de int\n");
    printf("%s\n\n", num);

    return 0;
}
