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
#ifndef BASE64_H
#define BASE64_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Brief: codifica um arquivo de entrada em base 64.
//
// Descrição:
// Lê todos os bytes do arquivo de entrada e os codifica em base 64 no arquivo de saída.
// Cada 3 bytes do arquivo de entrada são codificados em 4 bytes no arquivo de saída, como
// a seguir:
//                      Exemplo 1
// Bytes lidos                    00010001 00110011 01110111
// Bytes escritos na saída        00000100 00010011 00001101 00110111
//
//                      Exemplo 2
// Bytes lidos                    01001101 01100001 01101110
//                          ASCII     M       a        n
// Bytes em B64                   00010011 00010110 00000101 00101110
//                          B64       T       W        F        u
// Bytes escritos na saída        01010100 01010111 01000110 01110101
//                          ASCII     T       W        F        u
//
// Como pode ser observado, os bits foram separados de 6 em 6 e tiveram 2 zeros adicionados
// a sua esquerda para completar um byte.
//
// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void encode64(char *in, char *out);

// Brief: decodifica um arquivo de entrada em base 64.
//
// Descrição:
// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void decode64(char *in, char *out);

#endif /* BASE64_H */
