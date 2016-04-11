#include "base62.h"

void test_fun(){
    printf("Maze Module Included successufully\n");
}

char b62[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};

char getIndexb62(char c) {
    char *p = NULL, index = 0;

    if (c == '9'){
        return -1;
    }


    p = strchr(b62, c);
    index = (char)(p - b62);

    return index;
}

void encode62(char *in, char *out){
    FILE *fp_in = NULL, *fp_out = NULL;
    char CV, um, umQ, umCode, dois, doisQ, doisCode, rest;
    int readNBytes = 6, leftNBytes = 8;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }

    CV = getc(fp_in);
    if(CV == EOF){
        CV = 0b00000000;
    }

    while(feof(fp_in) == 0) {
        if(leftNBytes > 5){
            um = ((CV >> (leftNBytes-readNBytes)) & (int)(pow(2,readNBytes) - 1));
            umQ = ((CV >> (leftNBytes-readNBytes)) & (int)(pow(2,readNBytes) - 1));

            if(um < 61){
                umCode = b62[um];
                putc(umCode, fp_out);
            }
            if(um == 61){
                putc(b62[61], fp_out);
                putc(b62[0], fp_out);
            }
            if(um == 62){
                putc(b62[61], fp_out);
                putc(b62[1], fp_out);
            }
            if(um == 63){
                putc(b62[61], fp_out);
                putc(b62[2], fp_out);
            }

            leftNBytes -= readNBytes;
            rest = ((CV & (int)(pow(2,(8-readNBytes)) - 1)) << (6-leftNBytes));

            //if(um > 1){
                readNBytes = 6 - leftNBytes;
            //} else {
            //    if(leftNBytes < 5){
            //        readNBytes = 5 - leftNBytes;
            //    } else{
            //        readNBytes = 5;
            //    }
            //}

            if(readNBytes == 0){
                readNBytes = 6;
            }
            if(leftNBytes == 0){
                leftNBytes = 8;
                CV = getc(fp_in);
                if(feof(fp_in)){
                    CV = 0b00000000;
                }
            }
        } else{
            CV = getc(fp_in);
            if(feof(fp_in)){
                CV = 0b00000000;
            }

            dois = (rest | (CV >> (8-readNBytes) & (int)(pow(2,readNBytes) - 1)));
            doisQ = (rest | (CV >> (8-readNBytes) & (int)(pow(2,readNBytes) - 1)));

            if(dois < 61){
                doisCode = b62[dois];
                putc(doisCode, fp_out);
            }
            if(dois == 61){
                putc(b62[61], fp_out);
                putc(b62[0], fp_out);
            }
            if(dois == 62){
                putc(b62[61], fp_out);
                putc(b62[1], fp_out);
            }
            if(dois == 63){
                putc(b62[61], fp_out);
                putc(b62[2], fp_out);
            }

            leftNBytes = (8-readNBytes);

            rest = ((CV & (int)(pow(2,(8-readNBytes)) - 1)) << (6-leftNBytes));

            //if(dois > 1){
                readNBytes = 6 - leftNBytes;
            //} else {
            //    if(leftNBytes < 5){
            //        readNBytes = 5 - leftNBytes;
            //    } else{
            //        readNBytes = 5;
            //    }
            //}

            if(readNBytes == 0){
                readNBytes = 6;
            }
            if(leftNBytes == 0){
                leftNBytes = 8;
                CV = getc(fp_in);
            }
        }
    }

    fclose(fp_in);
    fclose(fp_out);
}

void decode62(char *in, char *out){
    FILE *fp_in = NULL, *fp_out = NULL;
    int readNBytes = 6, leftNBytes = 6, i = 0;
    char CV, parteUm, parteDois, resto = 0b00000000, completo;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        exit(0);
    }

    CV = getc(fp_in);
    parteUm = getIndexb62(CV);
    parteUm = parteUm << 2;
    readNBytes = 2;
    leftNBytes = 6;
    while(feof(fp_in) == 0){
        CV = getc(fp_in);
        if(feof(fp_in)){
            break;
        }
        parteDois = getIndexb62(CV);
        if(parteDois == -1){
            CV = getc(fp_in);
            if(CV == 'A'){
                parteDois = 61;
            } else if(CV == 'B'){
                parteDois = 62;
            } else if(CV == 'C'){
                parteDois = 63;
            }
        }

        completo = parteUm | (parteDois >> (6-readNBytes) & (int)pow(2,readNBytes) - 1);
        putc(completo,fp_out);
        leftNBytes = 6 - readNBytes;
        readNBytes = 8 - leftNBytes;
        parteUm = (parteDois & (int)pow(2,leftNBytes) - 1) << readNBytes;
        if(leftNBytes == 0 && readNBytes == 8){
            CV = getc(fp_in);
            if(feof(fp_in)){
                break;
            }

            parteUm = getIndexb62(CV);
            if(parteUm == -1){
                CV = getc(fp_in);
                if(CV == 'A'){
                    parteUm = 61;
                } else if(CV == 'B'){
                    parteUm = 62;
                } else if(CV == 'C'){
                    parteUm = 63;
                }
            }
            readNBytes = 2;
            leftNBytes = 6;

            parteUm = parteUm << 2;
        }
        i++;
    }

    fclose(fp_in);
    fclose(fp_out);
}
