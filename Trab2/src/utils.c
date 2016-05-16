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
 *  Arquivo de fonte "utils.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#include "utils.h"

void init_huge(huge h){
    for(int i = 0 ; i < 8; i++){
        h[i] = 0;
    }
}

int chtoi(char a){
    return (int) a - '0';
}

char intochar(int i){
    return (char) i + '0';
}

int nilstring(char *str, int len){
    for(int i=len-1; i >= 0 ; i--) // begin from the end for optimization
        if(str[i] != '0')
            return 0;
    return 1;
}

void str_to_huge(char* num, huge h){ // len(str) == 79
    char divided_num[79] = {0};
    int aux, len, i, j=0, k=7;
    init_huge(h);

    num[78] = 0;

    len = strlen(num); // assumimos que o número está formatado corretamente
    do{
        // processo de divisão estilo "primário"
        for(i = 0; i < len; i++){ // percorre cada posição do int passado
            aux = chtoi(num[i]); // converte o inteiro da primeira posição para int
            if(aux % 2 != 0) // se nao for divisivel, vai um
                num[i+1] = intochar(chtoi(num[i+1])) + 10; // soma dez para emular o "resta um"
            divided_num[i] = intochar(aux / 2); // adiciona o resultado da divisão de aux por dois ao array
        }
        // grava o número em bits no array huge
        divided_num[i] = '\0';

        if(num[i] != '\0')
           h[k] += 1 << j;

        j++;

        // trata o overflow andando no array huge
        if(j == 32)
            j = 0, k--;

        // copia o resto da divisão para num, e continua dividindo a partir daí
        strcpy(num, divided_num);
        len = strlen(num);
    }while(!nilstring(num, len));
}

void huge_to_str(huge h, char *num){
   sprintf(num, "%11"PRIu32"%11"PRIu32"%11"PRIu32"%11"PRIu32"%11"PRIu32"%11"PRIu32"%11"PRIu32"%11"PRIu32, h[0], h[1], h[2], h[3], h[4], h[5], h[6], h[7]);
}

void huge_to_hex(huge h, char *num){
   sprintf(num, "%11x""%11x""%11x""%11x""%11x""%11x""%11x""%11x", h[0], h[1], h[2], h[3], h[4], h[5], h[6], h[7]);
}

///////// DELETAR ANTES DE ENVIAR PELAMORDEDEUS
char *int2bin(uint32_t a){
 char *str,*tmp;
 int cnt = 31;
 str = (char *) malloc(33); /*32 + 1 , because its a 32 bit bin number*/
 tmp = str;
 while ( cnt > -1 ){
      str[cnt]= '0';
      cnt --;
 }
 cnt = 31;
 while (a > 0){
       if (a%2==1){
           str[cnt] = '1';
        }
      cnt--;
        a = a/2 ;
 }
 return tmp;
}

void infix_to_postfix(int* elements, char** infix, char*** pos){
    PilhaString* p = pilhaString_cria();
    int saidaHelp = 0;
    int qntElements = 1;
    int elementsSem = *elements;

    for (int i = 1; i <= *elements; ++i) {
        if(isOperador(infix[i])){
            while(topString(p) != NULL && (prioridade(topString(p)) >= prioridade(infix[i]))){
                qntElements++;
                *pos = (char**) realloc(*pos, (saidaHelp+1)*sizeof(char*));
                (*pos)[saidaHelp] = (char*) malloc(strlen(topString(p))*(sizeof(char)));
                strcpy((*pos)[saidaHelp],popString(p));
                saidaHelp++;
            }
            pushString(p,infix[i]);
        } else if(strcmp("(",infix[i]) == 0){
            elementsSem--;
            pushString(p,infix[i]);
        } else if(strcmp(")",infix[i]) == 0){
            elementsSem--;
            while(!pilhaString_vazia(p) && strcmp("(",topString(p)) != 0){
                qntElements++;
                *pos = (char**) realloc(*pos, (saidaHelp+1)*sizeof(char*));
                (*pos)[saidaHelp] = (char*) malloc(strlen(topString(p))*(sizeof(char)));
                strcpy((*pos)[saidaHelp],popString(p));
                saidaHelp++;
            }
            popString(p);
        } else{
            qntElements++;
            *pos = (char**) realloc(*pos, (saidaHelp+1)*sizeof(char*));
            (*pos)[saidaHelp] = (char*) malloc(strlen(infix[i])*(sizeof(char)));
            strcpy((*pos)[saidaHelp],infix[i]);
            saidaHelp++;
        }
    }

    while(!pilhaString_vazia(p)){
        qntElements++;
        *pos = (char**) realloc(*pos, (saidaHelp+1)*sizeof(char*));
        (*pos)[saidaHelp] = (char*) malloc(strlen(topString(p))*(sizeof(char)));
        strcpy((*pos)[saidaHelp], popString(p));
        saidaHelp++;
    }

    *elements = elementsSem;
}

PilhaString* pilhaString_cria (void) {
  PilhaString* p = (PilhaString*) malloc (sizeof(PilhaString));

  p->topo = 0;
  return p;
}

bool isOperador(char* element){
    if(strcmp(element,"+") == 0 || strcmp(element,"-") == 0 || strcmp(element,"x") == 0 || strcmp(element,"/") == 0){
        return true;
    }
    return false;
}

void pushString (PilhaString* p, char* v) {
  if (p->topo == N) {
    printf ("\nCapacidade esgotada!\n");
    printf ("Seu programa sera abortado\n");
    exit (1);
  }

  p->vet[p->topo] = v;
  p->topo++;
}

char* popString (PilhaString* p) {
  if (p->topo <= 0) {
    printf ("\nPilha vazia! Nao ha o qu deletar.\n");
    printf ("Seu programa sera abortado\n");
    exit (1);
  }

  char* v = p->vet[p->topo - 1];
  p->topo--;
  return v;
}

char* topString (PilhaString* p) {
    if (p->topo <= 0) {
        return NULL;
    }

    char* v = p->vet[p->topo - 1];
    return v;
}

bool pilhaString_vazia (PilhaString* p) {
  if (p->topo <= 0)
    return true;
  else
    return false;
}

int prioridade(char* caracter){
    if(strcmp("+",caracter) == 0 || strcmp("-",caracter) == 0){
        return 1;
    } else if(strcmp("x",caracter) == 0 || strcmp("/",caracter) == 0){
        return 2;
    }
    return 0;
}

/////////

/*void operacao(char operador, huge res){
    // declara e inicializa os operandos
    huge esq = {0};
    huge dir = {0};

    // desempilha os operandos da pilha
    esq = pop();
    dir = pop();

    switch(operador){
        case '+': soma(res, dir, esq);
                  break;
        case '-': subrai(res, dir, esq);
                  break;
        case '*': multiplica(res, dir, esq);
                  break;
        case '/': divide(res, dir, esq);
                  break;
    }
}*/

void soma(huge res, huge esq, huge dir) {
      uint32_t bit1 = 0, bit2 = 0, sum_bit = 0;
      int32_t i = 0, shift = 0;
      uint32_t overflow = 0;
      huge aux_res = {0};

      for (i = 7; i >= 0; i--) {
            for (shift = 0; shift < 32; shift++) {
                  bit1 = esq[i] >> shift & 0x00000001;
                  bit2 = dir[i] >> shift & 0x00000001;
                  sum_bit = bit1 ^ bit2 ^ overflow;
                  overflow = (bit1 & bit2) | (bit1 & overflow) | (bit2 & overflow);
                  aux_res[i] = aux_res[i] | (sum_bit << shift);
            }
      }

      memcpy(res, aux_res, 32);

      return;
}

void subtrai(huge res, huge esq, huge dir){
    int i;
    // recebe a negação do segundo operando
    huge inverte = {0};

    huge um = {0};
    huge sub = {0};

    for(i = 7; i >= 0; i--){
        inverte[i] = ~dir[i];
    }

    um[7] = 1;

    // soma 1 do complemento a dois
    soma(sub, inverte, um);

    // faz a soma com o resultado do complemento a dois
    soma(res, sub, esq);
}

// void multiplica(huge res, huge esq, huge dir) {
//       huge counter = {0}, one = {0};
//
//       // Garantindo que o res está com 0.
//       init_huge(res);
//
//       // Inicializando o huge com 1.
//       one[7] = 1;
//
//       for (init_huge(counter) ; memcmp(dir, counter, 32); soma(counter, counter, one))
//             soma(res, res, esq);
//
//       return;
// }

void multiplica(huge res, huge esq, huge dir) {
      huge aux_res = {0};
      int bit_mul = 0, n = 0;

      for (n = 255; n >= 0 ; n--) {
            shift_left_255(aux_res, esq, 255 - n);

            bit_mul = dir[n/32] >> (31 - n%32) & 0x00000001;
            if (bit_mul == 0)
                  init_huge(aux_res);

            soma(res, res, aux_res);
      }

      return;
}

void divide(huge res, huge esq, huge dir){
    huge counter = {0}, zero = {0}, one = {0}, tmp = {0};

    // Garantindo que o res está com 0
    init_huge(res);

    // inicializando o huge com 1
    one[7] = 1;

    // copia o número em que faremos as sucessivas subtrações
    // para um huge temporário
    memcpy(tmp, esq, 32);

    // faz sucessivas subtrações do número direito no esquerdo
    for(init_huge(counter); !(memcmp(tmp, dir, 32) < 0) ; soma(counter, counter, one)){
        subtrai(tmp, tmp, dir);
    }

    // a quantidade de subtrações necessárias é igual ao counter
    memcpy(res, counter, 32);

    return;
}

void push (Pilha* p, huge v) {
  if (p->topo == N) {
    printf ("\nCapacidade esgotada!\n");
    printf ("Seu programa sera abortado\n");
    exit (1);
  }

  p->vet[p->topo] = v;
  p->topo++;
}

hugeType* pop (Pilha* p) {
  if (p->topo <= 0) {
    printf ("\nPilha vazia! Nao ha o qu deletar.\n");
    printf ("Seu programa sera abortado\n");
    exit (1);
  }

  hugeType *v = p->vet[p->topo - 1];
  p->topo--;
  return v;
}

Pilha* pilha_cria (void) {
  Pilha* p = (Pilha*) malloc (sizeof(Pilha));

  p->topo = 0;
  return p;
}

// Shifta um huge n casas para a esquerda. n pode ser no máximo 31.
int shift_left_31(huge res, huge operand, uint32_t n) {
      huge aux_res = {0};
      uint32_t aux = 0;
      int i = 0;

      // Se o shift deslocar 256 casas ou mais, o resultado é 0.
      if (n >= 32) {
            init_huge(operand);
            return 0;
      }


      // Esse loop funciona para shifts de até 31 bits;
      for (i = 7; i >= 0; i--) {
            // Shifta o int para a esquera e coloca os bits originados do int
            // anterior mais a direita.
            aux_res[i] = operand[i] << n | aux;
            // Salva os bits mais a esquerda que serão passados para o próximo int.
            aux = operand[i] >> (32 - n);
      }

      memcpy(res, aux_res, 32);

      return 1;
}

// Shifta um huge n casas para a esquerda. n pode ser no máximo 255.
int shift_left_255(huge res, huge operand, uint32_t n) {
      uint32_t aux = 0;
      int i = 0;

      // Se o shift deslocar 256 casas ou mais, o resultado é 0.
      if (n >= 256) {
            init_huge(operand);
            return 0;
      }

      memcpy(res, operand, 32);

      for (i = 0; i < n/31; i++)
            shift_left_31(res, res, 31);


      shift_left_31(res, res, (n%31));

      return 1;
}
