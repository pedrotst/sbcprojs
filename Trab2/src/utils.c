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
   sprintf(num, "%10"PRIu32"%10"PRIu32"%10"PRIu32"%10"PRIu32"%10"PRIu32"%10"PRIu32"%10"PRIu32"%10"PRIu32, h[0], h[1], h[2], h[3], h[4], h[5], h[6], h[7]);
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