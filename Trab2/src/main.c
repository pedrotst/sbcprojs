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
 *  Arquivo fonte principal "main.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef uint32_t huge[8];

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
    char divided_num[79];
    int aux, len, i, j=0, k=0;
    init_huge(h);

    num[78] = 0;

    len = strlen(num); // we assume num is well formed
    do{
        for(i = 0; i < len; i++){
            aux = chtoi(num[i]);
            if(aux % 2 != 0) // se nao for divisivel, vai um
                num[i+1] = intochar(chtoi(num[i+1])) + 10; 
            divided_num[i] = intochar(aux / 2);
        }
        divided_num[78] = '\0';
        if(num[i] != '\0')
           h[k] += 1 << j; 
        j++;
        if(j == 33)
            j = 0, k++;
        strcpy(num, divided_num);
        len = strlen(num);
    }while(!nilstring(num, len));
    
}

int main(int argc, char **argv){

    huge h;
    char num[79]; //maior numero de 255 bits tem tamanho 77, + sinal + \0
    strcpy(num, argv[1]); 
    init_huge(h);
    printf("%d  %s\n", argc, argv[1]);
    printf("%s \n", num );
    str_to_huge(num, h);
    printf("%" PRIu32 "\n", h[0]);

    /* testing if functions works
     * char *tst = ":;<=>?@ABC";
    for(int i=0; i < strlen(tst); i++){
        printf("%c\n", intochar(chtoi(tst[i])));
    }
    */
    return 0;
}
