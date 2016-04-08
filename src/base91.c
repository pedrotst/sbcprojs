#include "base91.h"
#include <stdio.h>
#include <string.h>
void encode91(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[3], outBytes[4];
    int d[13];
    int i = 0;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("%s", in);
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        return;
    }

    if ((fp_out = fopen(out, "wb")) == NULL) {
        printf("\nErro ao abrir o arquivo de saída.\n\n");
        return;
    }
    fgets(d, 13, fp_in);
    for(i =0; i < 14; i++)
        printf("%d", d[i]);
}

void decode91(char *in, char *out){

}
