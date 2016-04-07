//
//  base64.c
//  trab1
//
//  Created by Felipe Albuquerque on 4/6/16.
//  Copyright © 2016 UnB. All rights reserved.
//

#include "base64.h"

char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[3], outBytes[4];
    int i = 0;
    
    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        exit(0);
    }
    
    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        exit(0);
    }
    
    while (c != EOF) {
        for (i = 0; (c = getc(fp_in)) != EOF && i < 3; i++) {
            inBytes[i] = c;
        }
        
        outBytes[0] = outBytes[1] = outBytes[2] = outBytes[3] = 0;
        if (i != 0) {
            outBytes[0] = b64[inBytes[0] >> 2 & 0b00111111];
            outBytes[1] = b64[(inBytes[0] << 4 & 0b00110000) | (inBytes[1] >> 4 & 0b00001111)];
            outBytes[2] = i > 1 ? b64[(inBytes[1] << 2 & 0b00111100) | (inBytes[2] >> 6 & 0b00000011)] : '=';
            outBytes[3] = i > 2 ? b64[inBytes[2] & 0b00111111] : '=';
        }
        
        else if (i == 2) {
            
        }
        
        for (i = 0; i < 4; i++) {
            putc(c, fp_out);
        }
    }
}

void decode(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, outBytes[3], inBytes[4];
    int i = 0;
    
    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("Erro ao abrir o arquivo de entrada.");
        exit(0);
    }
    
    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("Erro ao abrir o arquivo de saída.");
        exit(0);
    }
}