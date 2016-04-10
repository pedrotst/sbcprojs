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

void encode85(char *in, char *out) 
{
	
    FILE *fp_in = NULL, *fp_out = NULL;
    char  outBytes[4];
    int i = 0 ,  contAux = 0;
    uint32_t aux, c = !EOF, inBytes[3] ;
    
    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }
    
    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }
    
    
    
    while (feof(fp_in) == 0) {
    	
    	for (i = 0; i < 4; i++)
        	inBytes[i] = 0;
        
        for (i = 0; i < 4; i++) {
            if ((c = getc(fp_in), feof(fp_in)) == 0){
				inBytes[i] = c;
				}

            else
                break;
        }
        
		
	    aux = inBytes[0]*256*256*256 + inBytes[1]*256*256 + inBytes[2]*256 + inBytes[3];

		
		if (aux == 0 ) 		{ putc (122							, fp_out); contAux++; continue;} 
		else{
			if (inBytes[0] > 0) { putc (aux/(85*85*85*85) % 85 + 33	|0, fp_out);contAux++; }
        	if (inBytes[0] > 0) { putc (aux/(85*85*85) % 85 + 33	|0, fp_out);contAux++; }
        	if (inBytes[1] > 0) { putc (aux/(85*85) % 85 + 33		|0, fp_out);contAux++; }
    		if (inBytes[1] > 0) { putc (aux/(85) % 85 + 33			|0, fp_out);contAux++; }
    		if (inBytes[2] > 0) { putc (aux%85 + 33					|0, fp_out);contAux++; }
    		if (contAux % 80 == 0) putc ( 10 						|0, fp_out);
    		if (feof(fp_in)) 	  fputs ("~>"						  , fp_out); 
    		}
    	
	}
	
	fclose(fp_in);
    fclose(fp_out);

}


void decode85(char *in, char *out)
{

	FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[5];
    int i = 0 , j=0 , aux;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }

    while (feof(fp_in) == 0) {

		for (i = 0; i < 5; i++)
        	inBytes[i] = 0;

        for (i = 0; i < 5; i++) {
            if ((c = getc(fp_in), feof(fp_in)) == 0){
				inBytes[i] = c;
			}
            else
                break;
        }


		for (j = 0; j < 5; j++) {
            if(( inBytes[j] < 33 && inBytes[j] > 117) || inBytes[j] != 122 )
				inBytes[j] = inBytes[j] - 33;

        }

		aux = inBytes[0]*85*85*85*85 + inBytes[1]*85*85*85 + inBytes[2]*85*85 + inBytes[3]*85 + inBytes[4];


		if (inBytes[0] > 0) putc (aux/(256*256*256) % 256	, fp_out);
        if (inBytes[1] > 0) putc (aux/(256*256) % 256		, fp_out);
        if (inBytes[2] > 0) putc (aux/(256) % 256			, fp_out);
    	if (inBytes[3] > 0) putc (aux % 256 				, fp_out);

	}

	fclose(fp_in);
    fclose(fp_out);


}
