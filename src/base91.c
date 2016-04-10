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





void encode91(char *in, char *out) {

char ENCODING_TABLE[91] =
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '#', '$',
  '%', '&', '(', ')', '*', '+', ',', '.', '/', ':', ';', '<', '=',
  '>', '?', '@', '[', ']', '^', '_', '`', '{', '|', '}', '~', '"'};


    FILE *fp_in = NULL, *fp_out = NULL;
    char c1, c2, c;
    int i = 0;
    long filelen;
    int buf=0, bit_loc=0, val=0;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        return;
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n\n");
        return;
    }

    fseek(fp_in, 0, SEEK_END);
    filelen = ftell(fp_in);
    rewind(fp_in);

    for(i=0; i<filelen; ++i){
        c = fgetc(fp_in);
        buf |= (c & 255) << bit_loc;
        bit_loc += 8;
        if(bit_loc > 13){
            val = buf & 8191;
            if(val > 88){
                buf >>= 13;
                bit_loc -= 13;
            } else {
                val = buf & 16383;
                buf >>= 14;
                bit_loc -= 14;
            }
            c1 = ENCODING_TABLE[(int)val/91];
            c2 = ENCODING_TABLE[(int)val%91];
            fprintf(fp_out, "%c%c", c2, c1);
        }
    }
    if(bit_loc > 0){
        fprintf(fp_out, "%c", ENCODING_TABLE[buf%91]);
        if(bit_loc > 7 || buf > 90){
            fprintf(fp_out, "%c", ENCODING_TABLE[buf/91]);
        }
    }



    fclose(fp_in);
    fclose(fp_out);
}

void decode91(char *in, char *out){
    int DECODING_TABLE[256] = {
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 62, 90, 63, 64, 65, 66, 91, 67, 68, 69, 70, 71, 91, 72, 73,
            52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 74, 75, 76, 77, 78, 79,
            80,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 81, 91, 82, 83, 84,
            85, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 86, 87, 88, 89, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
            91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91
    };
    FILE *fp_in = NULL, *fp_out = NULL;
    char c;
    int i, val = -1, buf=0, bit_loc=0;
    long filelen;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        return;
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n\n");
        return;
    }

    fseek(fp_in, 0, SEEK_END);
    filelen = ftell(fp_in);
    rewind(fp_in);

    for(i=0; i<filelen; ++i){
        c = fgetc(fp_in);
        if (DECODING_TABLE[(int)c] != 91){ // ignore non-alphabetic chars
            if(val == -1)
                val = DECODING_TABLE[(int)c]; // start next value
            else{
                val += DECODING_TABLE[(int)c] * 91;
                buf |= val << bit_loc;
                if ((val & 8191) > 88)
                    bit_loc += 13;
                else
                    bit_loc += 14;
                do{
                    fprintf(fp_out, "%c", buf);
                    buf >>= 8;
                    bit_loc -= 8;
                }while(bit_loc > 7);
                val = -1; // mark value complete
            }
        }
    }
    //progress remaining bits; write at most 1 byte
    if(val != -1)
        fprintf(fp_out, "%c", buf | val << bit_loc);

    fclose(fp_in);
    fclose(fp_out);

}
