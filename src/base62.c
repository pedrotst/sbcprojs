#include "base62.h"

void test_fun(){
    printf("Maze Module Included successufully\n");
}

char b62[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};

char getIndexb62(char c) {
    char *p = NULL, index = 0;

    p = strchr(b62, c);
    index = (char)(p - b62);

    return index;
}

void encode62(char *in, char *out){
    FILE *fp_in = NULL, *fp_out = NULL;
    char CV, um, umQ, umCode, dois, doisQ, doisCode, rest;
    int readNBytes = 6, leftNOffBytes = 8, shift = 0;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        exit(0);
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saida.\n\n");
        exit(0);
    }

    CV = getc(fp_in);
    if(CV == EOF){
        CV = 0b00000000;
    }
    //fprintf(fp_out, BYTETOBINARYPATTERN, BYTETOBINARY(CV));

    while(feof(fp_in) == 0) {
        if(leftNOffBytes > 5){
            if(shift == 0){
                um = ((CV >> (leftNOffBytes-readNBytes)) & (int)(pow(2,readNBytes) - 1))%62;
                umQ = ((CV >> (leftNOffBytes-readNBytes)) & (int)(pow(2,readNBytes) - 1))/62;
//                printf("%d %d ", readNBytes, leftNOffBytes);
//                printf("REST: "BYTETOBINARYPATTERN" ", BYTETOBINARY(rest));
//                printf("UM: "BYTETOBINARYPATTERN6" ", BYTETOBINARY6(um));
//                printf("CV: "BYTETOBINARYPATTERN"\n", BYTETOBINARY(CV));
            } else{
                um = ((CV >> (leftNOffBytes-readNBytes)) & (int)(pow(2,readNBytes) - 1));
                umQ = ((CV >> (leftNOffBytes-readNBytes)) & (int)(pow(2,readNBytes) - 1));
                um = (((rest >> 1) << 1) | doisQ)%62;
                umQ = (((rest >> 1) << 1) | doisQ)/62;
//                printf("%d %d ", readNBytes, leftNOffBytes);
//                printf("REST: "BYTETOBINARYPATTERN" ", BYTETOBINARY(rest));
//                printf("SHUM: "BYTETOBINARYPATTERN6" ", BYTETOBINARY6(um));
//                printf("CV: "BYTETOBINARYPATTERN"\n", BYTETOBINARY(CV));
                shift = 0;
            }

            umCode = b62[um];
            putc(umCode, fp_out);
            //fprintf(fp_out, BYTETOBINARYPATTERN6"|", BYTETOBINARY6(um));

            leftNOffBytes -= readNBytes;
            if(leftNOffBytes < 6)
                rest = ((CV & (int)(pow(2,(leftNOffBytes)) - 1)) << (6-leftNOffBytes));
            else
                rest = (CV & (int)(pow(2,(leftNOffBytes)) - 1));

            if(um > 1){
                if(leftNOffBytes >= 6){
                    readNBytes = 6;
                } else{
                    readNBytes = 6 - leftNOffBytes;
                }
            } else {
                if(leftNOffBytes >= 5){
                    readNBytes = 5;
                } else{
                    readNBytes = 5 - leftNOffBytes;
                }
                shift = 1;
                if(leftNOffBytes >= 5){
                    um = (((rest >> 1) << 1) | umQ)%62;
                    umQ = (((rest >> 1) << 1) | umQ)/62;
                    umCode = b62[um];
                    putc(umCode, fp_out);
//                    fprintf(fp_out, BYTETOBINARYPATTERN6"|", BYTETOBINARY6(um));
//                    printf("%d %d ", readNBytes, leftNOffBytes);
//                    printf("REST: "BYTETOBINARYPATTERN" ", BYTETOBINARY(rest));
//                    printf("REUM: "BYTETOBINARYPATTERN6" ", BYTETOBINARY6(um));
//                    printf("CV: "BYTETOBINARYPATTERN"\n", BYTETOBINARY(CV));
                    leftNOffBytes -= readNBytes;
                    rest = rest & (int)(pow(2,leftNOffBytes) - 1);
                    readNBytes = 6 - leftNOffBytes;
                    shift = 0;
                }
            }

            if(readNBytes <= 0){
                readNBytes = 6;
            }
            if(leftNOffBytes <= 0){
                leftNOffBytes = 8;
                CV = getc(fp_in);
                if(feof(fp_in)){
                    CV = 0b00000000;
                }
                //fprintf(fp_out, BYTETOBINARYPATTERN, BYTETOBINARY(CV));
            }

        } else{
            CV = getc(fp_in);
            if(CV == EOF){
                CV = 0b00000000;
            }
            //fprintf(fp_out, BYTETOBINARYPATTERN, BYTETOBINARY(CV));
            if(shift == 0){
                dois = (rest | (CV >> (8-readNBytes) & (int)(pow(2,readNBytes) - 1)))%62;
                doisQ = (rest | (CV >> (8-readNBytes) & (int)(pow(2,readNBytes) - 1)))/62;
//                printf("%d %d ", readNBytes, leftNOffBytes);
//                printf("REST: "BYTETOBINARYPATTERN" ", BYTETOBINARY(rest));
//                printf("DOIS: "BYTETOBINARYPATTERN6" ", BYTETOBINARY6(dois));
//                printf("CV: "BYTETOBINARYPATTERN"\n", BYTETOBINARY(CV));
            } else{
                dois = (rest | (CV >> (8-readNBytes) & (int)(pow(2,readNBytes) - 1)));
                doisQ = (rest | (CV >> (8-readNBytes) & (int)(pow(2,readNBytes) - 1)));
                dois = (((dois >> 1) << 1) | umQ)%62;
                doisQ = (((dois >> 1) << 1) | umQ)/62;
//                printf("%d %d ", readNBytes, leftNOffBytes);
//                printf("REST: "BYTETOBINARYPATTERN" ", BYTETOBINARY(rest));
//                printf("SHDOIS: "BYTETOBINARYPATTERN6" ", BYTETOBINARY6(dois));
//                printf("CV: "BYTETOBINARYPATTERN"\n", BYTETOBINARY(CV));
                shift = 0;
            }

            doisCode = b62[dois];
            putc(doisCode, fp_out);
            //fprintf(fp_out, BYTETOBINARYPATTERN6"|", BYTETOBINARY6(dois));

            leftNOffBytes = (8-readNBytes);
            if(leftNOffBytes < 6)
                rest = ((CV & (int)(pow(2,(leftNOffBytes)) - 1)) << (6-leftNOffBytes));
            else
                rest = (CV & (int)(pow(2,(leftNOffBytes)) - 1));

            if(dois > 1){
                if(leftNOffBytes >= 6){
                    readNBytes = 6;
                } else{
                    readNBytes = 6 - leftNOffBytes;
                }
            } else {
                if(leftNOffBytes >= 5){
                    readNBytes = 5;
                } else{
                    readNBytes = 5 - leftNOffBytes;
                }
                shift = 1;
                if(leftNOffBytes >= 5){
                    dois = (((rest >> 1) << 1) | doisQ)%62;
                    doisQ = (((rest >> 1) << 1) | doisQ)/62;
                    doisCode = b62[dois];
                    putc(doisCode, fp_out);
//                    fprintf(fp_out, BYTETOBINARYPATTERN6"|", BYTETOBINARY6(dois));
//                    printf("%d %d ", readNBytes, leftNOffBytes);
//                    printf("REST: "BYTETOBINARYPATTERN" ", BYTETOBINARY(rest));
//                    printf("REDOIS: "BYTETOBINARYPATTERN6" ", BYTETOBINARY6(dois));
//                    printf("CV: "BYTETOBINARYPATTERN"\n", BYTETOBINARY(CV));
                    leftNOffBytes -= readNBytes;
                    rest = rest & (int)(pow(2,leftNOffBytes) - 1);
                    readNBytes = 6 - leftNOffBytes;
                    shift = 0;
                }
            }

            if(readNBytes <= 0){
                readNBytes = 6;
            }
            if(leftNOffBytes <= 0){
                leftNOffBytes = 8;
                CV = getc(fp_in);
                if(CV == EOF){
                    CV = 0b00000000;
                }
                //fprintf(fp_out, BYTETOBINARYPATTERN, BYTETOBINARY(CV));
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
        printf("\nErro ao abrir o arquivo de saida.\n\n");
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
