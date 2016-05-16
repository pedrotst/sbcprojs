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
    char** pos = (char**) malloc(sizeof(char*));
    infix_to_postfix(&qntElementos, argv, &pos);

    for (int i = 0; i < qntElementos; ++i) {
        printf("%s ", pos[i]);
    }

    return 0;
}
