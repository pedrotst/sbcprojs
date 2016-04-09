#ifndef base85_h
#define base85_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void encode85(char *in, char *out);


// Parâmetros:
// *in : nome do arquivo de entrada.
// *out : nome do arquivo de saída.
void decode85(char *in, char *out);

#endif /* base85_h */
