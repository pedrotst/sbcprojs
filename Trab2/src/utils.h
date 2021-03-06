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
#include <stdbool.h>

 /*
  * Tamanho da pilha de strings
  */
#define N 100

/*
  * Estrutura da pilha de strings
  */
struct pilhaString {
  int topo;
  char* vet[N];
};

 /*
  * Tipo definito para pilha de strings
  */
typedef struct pilhaString PilhaString;

 /*
  * Tipo definito para manipulação de número com 256bits
  */
typedef uint32_t huge[8];
 /*
  * Tipo definito para manipulação de número com 256bits
  */
typedef uint32_t hugeType;

/*
  * Estrutura da pilha de huges
  */
struct pilha {
  int topo;
  hugeType* vet[N];
};

 /*
  * Tipo definito para pilha de huges
  */
typedef struct pilha Pilha;

 /*
  * Brief       : Inicializa o número huge
  *
  * Descrição   : Inicializa o número huge colocando zeros em todas as posições
  *
  * Parâmetros  : huge h: número de 256bits a ser inicializado
  *
  * Retorno     : Nenhum
  */
void init_huge(huge h);

 /*
  * Brief       : Converte char para int
  *
  * Descrição   : Converte char recebido para int
  *
  * Parâmetros  : char a: char a ser convertido
  *
  * Retorno     : int: número convertido
  */
int chtoi(char a);

 /*
  * Brief       : Converte int para char
  *
  * Descrição   : Converte int recebido para char
  *
  * Parâmetros  : char a: char a ser convertido
  *
  * Retorno     : int: número convertido
  */
char intochar(int i);

 /*
  * Brief       : Verifica se a string está vazia
  *
  * Descrição   : Verifica se a string está vazia, ou seja, contém
  *				  somente zeros
  *
  * Parâmetros  : char *str: string a ser verificada
  *				  int len: 	 tamanho da string
  *
  * Retorno     : int: 0 se a string não está vazia, 1 se a string está vazia
  */
int nilstring(char *str, int len);

 /*
  * Brief       : Converte um decimal para binário
  *
  * Descrição   : Converte um decimal para binário através do algoritmo
  *				  de sucessivas divisões por 2
  *
  * Parâmetros  : char *num: string a ser convertida
  *				  huge h:	 tipo huge que receberá o número binário
  *				  			 convertido
  *
  * Retorno     : Nenhum
  */
void str_to_huge(char* num, huge h);

 /*
  * Brief       : Converte um binário para decimal
  *
  * Descrição   : Converte um binário para decimal
  *
  * Parâmetros  : huge h:	 tipo huge a ser convertido
  *				  char *num: string que receberá o binário convertido para
  *					   		 decimal
  *
  * Retorno     : Nenhum
  */
void huge_to_str(huge h, char *num);

void huge_to_hex(huge h, char *num);

 /*
  * Brief       : Converte notação infixa para pós-fixa
  *
  * Descrição   : Converte notação infixa para pós-fixa
  *
  * Parâmetros  : int* elements: endereço da quantidade de elementos que existem na expressao pos-fixa
  *               char **infix: lista de strings representa a expressao pre-fixa
  *               char ***saida: endereço da expressao pos-fixa
  *
  * Retorno     : Nenhum
  */
void infix_to_postfix(int* elements, char **infix, char*** saida);

 /*
  * Brief       : Empilha um número
  *
  * Descrição   : Empilha um número tipo huge na pilha
  *
  * Parâmetros  : Pilha* p: ponteiro para a pilha
  *               huge number: número de tamanho 256bits
  *
  * Retorno     : Nenhum
  */
void push(Pilha* p, huge number);

 /*
  * Brief       : Desempilha um número
  *
  * Descrição   : Desempilha um número tipo huge da pilha
  *
  * Parâmetros  : Pilha* p: ponteiro para a pilha de huges
  *
  * Retorno     : huge: número desempilhado tamanho 256bits
  */
hugeType* pop(Pilha* p);

 /*
  * Brief       : Executa a operação
  *
  * Descrição   : Executa a operação definida pelo operador passado
  *				  nos dois últimos números da pilha e empilha o resultado
  *
  * Parâmetros  : char operador: operador
  *				  huge res: número de 256bits que receberá o resultado da operação
  *
  * Retorno     : Nenhum
  */
void operacao(char operador, huge res);

 /*
  * Brief       : Executa a operação de soma
  *
  * Descrição   : Executa a operação de soma nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge res: número de 256bits que receberá o resultado da soma
  *				  huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : Nenhum
  */
void soma(huge res, huge esq, huge dir);

 /*
  * Brief       : Executa a operação de diferença
  *
  * Descrição   : Executa a operação de diferença nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge res: número de 256bits que receberá o resultado da subtração
  *				  huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : Nenhum
  */
void subtrai(huge res, huge esq, huge dir);

 /*
  * Brief       : Executa a operação de multiplicação
  *
  * Descrição   : Executa a operação de multiplicação nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge res: número de 256bits que receberá o resultado da multiplicação
  *				  huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : Nenhum
  */
void multiplica(huge res, huge esq, huge dir);

 /*
  * Brief       : Executa a operação de divisao
  *
  * Descrição   : Executa a operação de divisao nos dois números passados
  *				  pela função chamadora
  *
  * Parâmetros  : huge res: número de 256bits que receberá o resultado da divisão
  *				  huge dir: número de 256bits da direita
  *				  huge esq: número de 256bits da esquerda
  *
  * Retorno     : Nenhum
  */
void divide(huge res, huge esq, huge dir);

int shift_left_31(huge res, huge operand, uint32_t n);

int shift_left_255(huge res, huge operand, uint32_t n);

PilhaString*    pilhaString_cria (void);
Pilha*          pilha_cria (void);
bool            pilhaString_vazia (PilhaString* p);
void            pilhaString_libera (PilhaString* p);
bool            isOperador(char* element);
void            pushString (PilhaString* p, char* v);
char*           popString (PilhaString* p);
char*           topString (PilhaString* p);

int prioridade(char* c);

 #endif /* _UTILS_H_ */
