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

 /*
  * Tipo definito para manipulação de número com 256bits
  */
typedef uint32_t huge[8];

void init_huge(huge h);

int chtoi(char a);

char intochar(int i);

int nilstring(char *str, int len);

void str_to_huge(char* num, huge h);

void huge_to_str(huge h, char *num);

 /*
  * Brief       : Converte notação infixa para pós-fixa
  *
  * Descrição   : Converte notação infixa para pós-fixa
  * Parâmetros  : char *infix: string com a operação infixa
  * Retorno     : char *posfix: string com a operação pós-fix
  */
char * infix_to_postfix(char *infix);
 // lembrar de incluir a prioridade dos parênteses

 /*
  * Brief       : Empilha um número
  *
  * Descrição   : Empilha um número tipo huge na pilha
  *
  * Parâmetros  : huge number: número de tamanho 256bits
  *
  * Retorno     : Nenhum
  */
void push(huge number);

 /*
  * Brief       : Desempilha um número
  *
  * Descrição   : Desempilha um número tipo huge da pilha
  *
  * Parâmetros  : Nenhum
  *
  * Retorno     : huge: número desempilhado tamanho 256bits
  */
huge pop(void);


 /*
  * Brief       : Executa a operação
  *
  * Descrição   : Executa a operação definida pelo operador passado 
  *				  nos dois últimos números da pilha e empilha o resultado
  *
  * Parâmetros  : char operador: operador
  *
  * Retorno     : Nenhum
  */
void operacao(char operador);
// essa função deve conter um switch comm o operador que direcionará para a operação

 /*
  * Brief       : Executa a operação de soma
  *
  * Descrição   : Executa a operação de soma nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : huge result: número de 256bits resultante da operação de soma
  */
huge soma(huge dir, huge esq);

 /*
  * Brief       : Executa a operação de diferença
  *
  * Descrição   : Executa a operação de diferença nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : huge result: número de 256bits resultante da operação de diferença
  */
huge subtrai(huge dir, huge esq);

 /*
  * Brief       : Executa a operação de multiplicação
  *
  * Descrição   : Executa a operação de multiplicação nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : huge result: número de 256bits resultante da operação de multiplicação
  */
huge multiplica(huge dir, huge esq);

 /*
  * Brief       : Executa a operação de divisao
  *
  * Descrição   : Executa a operação de divisao nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : huge result: número de 256bits resultante da operação de divisao
  */
huge divide(huge dir, huge esq);



 #endif /* _UTILS_H_ */