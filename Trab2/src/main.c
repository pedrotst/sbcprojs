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
    int qntElementos = argc - 1;
    huge h;
    init_huge(h);
    char** pos = (char**) malloc(sizeof(char*));
    char exp[9999];
    const char delim[2] = " ";
    char** tokens = (char**) malloc(sizeof(char*));

    if(qntElementos < 1){
        int i;
        printf("Insira a expressao a ser avaliada: ");
        fgets(exp, 9999, stdin);
        printf("%s", exp);

        tokens[0] = argv[0];
        tokens[1] = strtok(exp , delim);
        for(i=1; *(tokens+i); i++)
            tokens[i + 1] = strtok(NULL , delim);
        qntElementos = i-1;
        tokens[i-1][strlen(tokens[i-1]) - 1] = '\0'; // tira o \n de forma porca, confesso
    }
    else{
        tokens = argv;
    }
    infix_to_postfix(&qntElementos, tokens, &pos);

    for (int i = 0; i < qntElementos; ++i) {
        printf("%s\n", pos[i]);
    }

    Pilha* p = pilha_cria();

    str_to_huge(pos[0], h);

    printf("huge: %s\n", int2bin(h[7]));
    push(p,h);
    hugeType *h1 = pop(p);
    printf("%s\n", int2bin(h1[7]));

    return 0;


      // huge operand1 = {0}, operand2 = {0}, res_h = {0};
      // char res_string[79], num[79];
      //
      // strcpy(num, argv[1]);
      // str_to_huge(num, operand1);
      // str_to_huge(argv[2], operand2);
      // multiplica(res_h, operand1, operand2);
      // huge_to_hex(res_h, res_string);
      // printf("%s\n", res_string);
      //
      // return 0;

}
