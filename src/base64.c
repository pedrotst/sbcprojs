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
 *  Arquivo fonte "base64.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#include "base64.h"

char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char getIndex(char c) {
    char *p = NULL, index = 0;

    if (c == '=')
        return -1;

    p = strchr(b64, c);
    index = (char)(p - b64);

    return index;
}

void encode64(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[3], outBytes[4];
    int i = 0, charsLine = 0;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }

    while (feof(fp_in) == 0) {
        for (i = 0; i < 3; i++) {
            if ((c = getc(fp_in), feof(fp_in)) == 0)
                inBytes[i] = c;
            else
                break;
        }

        outBytes[0] = outBytes[1] = outBytes[2] = outBytes[3] = 0;
        if (i != 0) {
            outBytes[0] = b64[inBytes[0] >> 2 & 0b00111111];
            outBytes[1] = b64[(inBytes[0] << 4 & 0b00110000) | (inBytes[1] >> 4 & 0b00001111)];
            outBytes[2] = i > 1 ? b64[(inBytes[1] << 2 & 0b00111100) | (inBytes[2] >> 6 & 0b00000011)] : '=';
            outBytes[3] = i > 2 ? b64[inBytes[2] & 0b00111111] : '=';
        }

        for (i = 0; i < 4; i++) {
            putc(outBytes[i], fp_out);
            charsLine++;
        }

        if ( charsLine == 76) {
            putc('\n', fp_out);
            charsLine = 0;
        }
    }

    fclose(fp_in);
    fclose(fp_out);
}

void decode64(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, outBytes[3], inBytes[4];
    int i = 0, j = 0, invalidBytes = 0, charsLine = 0;

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
            if ((c = getc(fp_in), feof(fp_in)) == 0) {
                inBytes[i] = c;
                charsLine++;
            }
            else
                break;
        }

        if (charsLine == 76) {
            (void)getc(fp_in);
            charsLine = 0;
        }

        //Passando os inbytes de char para binário.
        for (j = 0; j < 4; j++) {
            inBytes[j] = getIndex(inBytes[j]);
        }

        //Definindo que bytes reconstruídos a partir do cactere '=' não devem ser escritos
        //no arquivo de saída.
        invalidBytes = 0;
        if (inBytes[2] == -1)
            invalidBytes++;
        if (inBytes[3] == -1)
            invalidBytes++;

        outBytes[0] = outBytes[1] = outBytes[2] = 0;
        if (i != 0) {
            outBytes[0] = (inBytes[0] << 2 & 0b11111100) | (inBytes[1] >> 4 & 0b00000011);
            outBytes[1] = (inBytes[1] << 4 & 0b11110000) | (inBytes[2] >> 2 & 0b00001111);
            outBytes[2] = (inBytes[2] << 6 & 0b11000000) | (inBytes[3] & 0b00111111);

            for (i = 0; i < 3 - invalidBytes; i++) {
                putc(outBytes[i], fp_out);

            }
        }
    }
}
