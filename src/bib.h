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
 *  Arquivo cabeçalho "bib.h"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#ifndef BIB_H
#define BIB_H

#include <stdint.h>
#include <stdio.h>

// Descrição: checa se uma das opçõse de encoding ou decoding foi escolhida
// Parâmetros:
// char opção: caracter que representa uma das bases suportadas
uint8_t existe_opcao(char opcao);

// Descrição: checa se uma das bases definidas foi escolhida
// Parâmetros:
// char base: caracter que representa uma das bases suportadas
//            1 - base91
//            2 - base62
//            3 - base64
//            5 - base85
uint8_t existe_base(char base);

// Descrição: checa se um arquivo existe a partir da sua localização/nome
// Parâmetros:
// char *nome_arquivo: nome do arquivo a ser verificado
uint8_t existe_arquivo(const char *nome_arquivo);

#endif /* BIB_H */
