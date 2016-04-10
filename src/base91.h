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
 *  Arquivo cabeçalho "base91.h"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#ifndef BASE91_H
#define BASE91_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_bit(char c, int bit_n);

// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void encode91(char *in, char *out);

// Brief: decodifica um arquivo de entrada em base 64.
//
// Descrição:
// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void decode91(char *in, char *out);

#endif /* BASE91_H */
