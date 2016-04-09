//
//  base64.c

#include "base64.h"

void encode85(char *in, char *out) 
{
	
    FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[3];
    int i = 0 , aux;
    
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
            if ((c = getc(fp_in), feof(fp_in)) == 0)
				inBytes[i] = c;
				
            else
                break;
        }
        
        aux = inBytes[0]*256*256*256 + inBytes[1]*256*256 + inBytes[2]*256 + inBytes[3];
		
		if (inBytes[0] > 0) putc (aux/(85*85*85*85) % 85 + 33	, fp_out);
        if (inBytes[0] > 0) putc (aux/(85*85*85) % 85 + 33		, fp_out);
        if (inBytes[1] > 0) putc (aux/(85*85) % 85 + 33			, fp_out);
    	if (inBytes[2] > 0) putc (aux/(85) % 85 + 33			, fp_out);
    	if (inBytes[3] > 0) putc (aux%85 + 33					, fp_out);
	}
	
	fclose(fp_in);
    fclose(fp_out);

}



void decode85(char *in, char *out) 
{
	
	FILE *fp_in = NULL, *fp_out = NULL;
    char c = !EOF, inBytes[4];
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
