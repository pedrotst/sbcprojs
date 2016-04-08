//
//  base64.c
//  trab1
//
//  Created by Felipe Albuquerque on 4/6/16.
//  Copyright © 2016 UnB. All rights reserved.
//

#include "base64.h"

char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int getIndex(char c) {
    char *p = NULL;
    int index = 0;
    
    p = strchr(b64, c);
    index = (int)(b64 - p);
    
    return index;
}

void encode64(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[3], outBytes[4];
    int i = 0;
    
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
        }
    }
    
    fclose(fp_in);
    fclose(fp_out);
}

void decode64(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, outBytes[3], inBytes[4];
    int i = 0;
    
    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }
    
    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }
}