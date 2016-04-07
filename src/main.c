#include "base62.h"

#define OPT1(ac, av) (ac > 1 ? av[1][0] == '-' ? av[1][1] : '\0' : '\0')

#define OPT2(ac, av) (ac > 2 ? av[2][0] == '-' ? av[2][1] : '\0' : '\0')


// Mensagens de erro.
char *err[] = { "\nSintaxe errada. Utilize a opção -h para obter ajuda.\n\n"};

int main(int argc, char **argv){
    char opt1 = '\0', opt2 = '\0';
    
    opt1 = OPT1(argc, argv);
    opt2 = OPT2(argc, argv);
    
    switch (opt1) {
        case '\0':
            printf("%s", err[0]);
            break;
        case 'h':
            printf("Sintaxe:\n \
main { -b62 | -b64 | -b85 | -b91 } { -e | -d } {arquivo de entrada} {arquivo de saída}\n\
\n\
-b62 A base utilizada será a base 62.\n\
-b64 A base utilizada será a base 64.\n\
-b85 A base utilizada será a base 85.\n\
-b91 A base utilizada será a base 91.\n\
\n\
-e O arquivo será codificado (binário para texto).\n\
-d O arquivo será decodificado (texto para binário).\n\
\n");
            break;
        case 64:
            switch (opt2) {
                case 'e':
                    break;
                case 'd':
                    break;
            }
            break;
            
        default:
            break;
    }

    return 0;
}
