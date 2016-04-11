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
 *  Arquivo fonte "base85.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#include "base85.h"

int pesos[] = {85*85*85*85, 85*85*85, 85*85, 85, 1};

void encode85(char *in, char *out) 
{
	
    FILE *fp_in = NULL, *fp_out = NULL;
    char  outBytes[5];
    int i = 0 ,  contAux = 0 , lim = 0, count = 0;
    unsigned int  c = !EOF ;
    uint32_t aux = 0;
    
    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }
    
    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }
    
    while (feof(fp_in) == 0) {
    	
        for (i = 0; i < 4; i++) {
            if ((c = getc(fp_in), feof(fp_in)) == 0){
				aux |= ((unsigned int)c) << ((3 - count++) * 8);
				}

            else
                break;
        }
        
		if (aux == 0 && count == 4 ){ 
			putc (122	, fp_out); 
			contAux++; 
			if (contAux % 80 == 0) 
				putc(10 , fp_out); 
			
			aux = 0;
    		count = 0;
			continue;
			}
		
		else{
			
			for (i = 0; i < 5; i++) {
				outBytes[i] = aux % 85 + '!';
				aux /= 85;
				}	
		
			lim = 4 - count;
			for (i = 4; i >= lim; i--) {
				putc ( outBytes[i] , fp_out);
				contAux++;	
				if (contAux % 80 == 0) 
					putc(10 , fp_out);
				}
			

   			}	
    	
		aux = 0;
    	count = 0;
    	
	}
	
	fputs ("~>" , fp_out);
	
	fclose(fp_in);
    fclose(fp_out);

}

int get_nextC(FILE *fp_in) {
	
	int c;
	while (isspace(c = getc(fp_in)));
	return c;
	
}


void decode85(char *in, char *out)
{
    
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, count = 0;
    int i = 0 , j = 0 ;
    uint32_t aux = 0;
    
    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }
    
    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }
    
    while (feof(fp_in) == 0) {
        
        if ((c = get_nextC(fp_in), feof(fp_in)) == 0){
           	if (c == '~' ){
                c = get_nextC(fp_in);
                if (c != '>') {
                    printf("\n Falta o final do arquivo '~>'\n Falha no decode\n");
                    exit (1);
                }
                
                if (count > 0) {
                    aux += pesos[count-1];
                    for (j = 1 ; j<count ; j++)
                        putc(aux >> ((4 - j) * 8),fp_out);
                    break;
                }
                break;
            }
        }
        
        if (c == 'z' && count == 0) {
            for (j = 1 ; j<5 ; j++)
                putc(0,fp_out);
            continue;
        }
        
        
        if (c < '!' || c > 'u') {
            printf("\n Caracter invalido no arquivo...Impossivel decodificar...\n");
            printf("%c ", c);
            exit(0);
        }
        
        aux += ((unsigned int)(c - '!')) * pesos[count++];
        
        if (count == 5) {
            for (j = 1 ; j<count ; j++){
                putc(aux >> ((4 - j) * 8),fp_out);
                
            }
            
            aux = 0;
            count = 0;
        }
        
    }
    
    fclose(fp_in);
    fclose(fp_out);
    
    
}