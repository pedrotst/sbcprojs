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
 *  Arquivo de cabeçalho "utils.h"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#ifndef _UTILS_H_
#define _UTILS_H_
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>

 typedef uint32_t huge[8];

 void init_huge(huge h);

 int chtoi(char a);

 char intochar(int i);

 int nilstring(char *str, int len);

 void str_to_huge(char* num, huge h);

 #endif /* _UTILS_H_ */