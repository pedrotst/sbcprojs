#include "base91.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_bit(char c, int bit_n){
    return (c >> bit_n) & 1;
}

char ENCODING_TABLE[91] = 
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '#', '$',
	  '%', '&', '(', ')', '*', '+', ',', '.', '/', ':', ';', '<', '=',
  '>', '?', '@', '[', ']', '^', '_', '`', '{', '|', '}', '~', '"'};
/*
int DECODE_TABLE[92] = 
  {91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91,
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
  91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91};
*/

void encode91(char *in, char *out) {
    FILE *fp_in = NULL, *fp_out = NULL;
    char c1, c2, c;
    int b13_bits, remainder;
    int i = 0;

    if ((fp_in = fopen(in, "rb")) == NULL) {
        printf("\nErro ao abrir o arquivo de entrada.\n\n");
        return;
    }

    if ((fp_out = fopen(out, "w")) == NULL) {
        printf("\nErro ao abrir o arquivo de sa�da.\n\n");
        return;
    }

    char *buffer;
    long filelen;
    fseek(fp_in, 0, SEEK_END);
    filelen = ftell(fp_in);
    rewind(fp_in);
    /*buffer = (char *) malloc((filelen+1)*sizeof(char));
    fread(buffer, filelen, 1, fp_in);
    buffer[filelen] = '\0';
    printf("%s", buffer);
*/
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
            fprintf(fp_out, "%c%c", c1, c2);
        }
    }
    if(en > 0){
        fprintf(fp_out, "%c", ENCODING_TABLE[ebq%91]);
        if(en > 7 || ebq > 90){
            fprintf(fp_out, "%c", ENCODING_TABLE[ebq/91]);
        }
    }
           



    /*    printf("%s\n", out);

    c1 = fgetc(fp_in);
    c2 = fgetc(fp_in);
    //printf("%d\n", c1 << 8);
    //concatena c1 e os cinco primeiros bits de c2
    b13_bits = c1 << 5 | (c2 >> 3);
    
    //pega os 3 ultimos bits de c2
    remainder = c2 & 0x7;
    printf("%d\n", b13_bits);
    printf("%d\n", remainder);
    c1 = b13_bits >> 8;
    //pega os 5 ultimos bits de b13 shifta 3  e junta com remainder
    c2 = ((b13_bits & 0x1f) << 3) | remainder;
    printf("%d\n", c1); 
    printf("%d\n", c2); 

    c1 = ENCODING_TABLE[(int)b13_bits/91];
    c2 = ENCODING_TABLE[(int)b13_bits%91];
    printf("%c\n", c1);
    printf("%c\n", c2);
    fprintf(fp_out, "%c%c", c1, c2);

   /* fwrite(fp_out, 1, c2);
    
    
    printf("%d\n", c >> 3 & 1);
    for(i = 0; i < 8; i++){
        c2 = get_bit(c, i); 
        //fprintf("%d", c2);
        printf("%d", c2);
    }
*/
    printf("\n");
    fclose(fp_in);
    fclose(fp_out);
}

void decode91(char *in, char *out){

}
