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
 *  Arquivo fonte "base91.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#include "base91.h"

char ENCODING_TABLE[91] =
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '#', '$',
	  '%', '&', '(', ')', '*', '+', ',', '.', '/', ':', ';', '<', '=',
  '>', '?', '@', '[', ']', '^', '_', '`', '{', '|', '}', '~', '"'};



void encode91(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c1, c2, c;
    int b13_bits, remainder;
    int i = 0;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        return;
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n\n");
        return;
    }

    char *buffer;
    long filelen;
    fseek(fp_in, 0, SEEK_END);
    filelen = ftell(fp_in);
    rewind(fp_in);
    int ebq=0, en=0, ev=0;

    for(i=0; i<filelen; ++i){
        c = fgetc(fp_in);
        ebq |= (c & 255) << en;
        en += 8;
        if(en > 13){
            ev = ebq & 8191;
            if(ev > 88){
                ebq >>= 13;
                en -= 13;
            } else {
                ev = ebq & 16383;
                ebq >>= 14;
                en -= 14;
            }
            c1 = ENCODING_TABLE[(int)ev/91];
            c2 = ENCODING_TABLE[(int)ev%91];
            fprintf(fp_out, "%c%c", c2, c1);
        }
    }
    if(en > 0){
        fprintf(fp_out, "%c", ENCODING_TABLE[ebq%91]);
        if(en > 7 || ebq > 90){
            fprintf(fp_out, "%c", ENCODING_TABLE[ebq/91]);
        }
    }



    printf("Codificado com Sucesso! Parabens\n");
    fclose(fp_in);
    fclose(fp_out);
}

void decode91(char *in, char *out){
    int DECODING_TABLE[256] = {
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //000..015
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //016..031
            91, 62, 90, 63, 64, 65, 66, 91, 67, 68, 69, 70, 71, 91, 72, 73, //032..047
            52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 74, 75, 76, 77, 78, 79, //048..063
            80,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, //064..079
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 81, 91, 82, 83, 84, //080..095
            85, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, //096..111
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 86, 87, 88, 89, 91, //112..127
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //128..143
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //144..159
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //160..175
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //176..191
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //192..207
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //208..223
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, //224..239
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91  //240..255 */
};
    FILE *fp_in = NULL, *fp_out = NULL;
    char c1, c2, c;
    int b13_bits, remainder;
    int i, j ;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        return;
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n\n");
        return;
    }

    char *buffer;
    long filelen;
    fseek(fp_in, 0, SEEK_END);
    filelen = ftell(fp_in);
    rewind(fp_in);
    int dv = -1, dbq=0, dn=0;

    for(i=0; i<filelen; ++i){
        c = fgetc(fp_in);
        if (DECODING_TABLE[(int)c] != 91){ // ignore non-alphabetic chars
            if(dv == -1)
                dv = DECODING_TABLE[(int)c]; // start next value
            else{
                dv += DECODING_TABLE[(int)c] * 91;
                dbq |= dv << dn;
                if ((dv & 8191) > 88)
                    dn += 13;
                else
                    dn += 14;
                do{
                    fprintf(fp_out, "%c", dbq);
                    dbq >>= 8;
                    dn -= 8;
                }while(dn > 7);
                dv = -1; // mark value complete
            }
        }
    }
    //progress remaining bits; write at most 1 byte
    if(dv != -1)
        fprintf(fp_out, "%c", dbq | dv << dn);

    fclose(fp_in);
    fclose(fp_out);

    printf("Decodificado com sucesso!\n");
}
