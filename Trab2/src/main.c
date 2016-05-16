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
    Pilha* p = pilha_cria();

    for (int i = 0; i < qntElementos; ++i) {
        printf("Processando: %s\n", pos[i]);
        if(!isOperador(pos[i])){
          huge h;
          str_to_huge(pos[i], h);
          push(p, h);
        }
        else{
            hugeType *esq, *dir;
            huge resp;
            esq = pop(p);
            dir = pop(p);
            switch (pos[i][0]){
            case '+':
                soma(resp, esq, dir);
                break;
            case '-':
                subtrai(resp, esq, dir);
                break;
            case 'x':
                multiplica(resp, esq, dir);
                break;
            case '/':
                divide(resp, esq, dir);
                break;
            }
            push(p, resp);
        }
    }






    //printf("huge: %s\n", int2bin(h[7]));
    //push(p,h);
    hugeType *h1 = pop(p);
    //printf("%s\n", int2bin(h1[7]));
    printf("0: %05x\n", h1[0]);
    printf("1: %05x\n", h1[1]);
    printf("2: %05x\n", h1[2]);
    printf("3: %05x\n", h1[3]);
    printf("4: %05x\n", h1[4]);
    printf("5: %05x\n", h1[5]);
    printf("6: %05x\n", h1[6]);
    printf("7: %05x\n", h1[7]);
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
