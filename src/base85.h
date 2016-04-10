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
 *  Arquivo cabeçalho "base85.h"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#ifndef BASE85_H
#define BASE85_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void encode85(char *in, char *out);


// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void decode85(char *in, char *out);

#endif /* BASE85_H */
