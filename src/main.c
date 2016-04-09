#include "base62.h"
#include "base64.h"
#include "base85.h"
#include "base91.h"

#define OPT1(ac, av) (ac > 1 ? av[1][0] == '-' ? av[1][1] : '\0' : '\0')

#define OPT2(ac, av) (ac > 2 ? av[2][0] == '-' ? av[2][3] : '\0' : '\0')


// Mensagens de erro.
char *err[] = { "\nSintaxe errada. Utilize a opcao -h para obter ajuda.\n\n",
                "\nBase nao implementada. Utilize a opcao -h para obter ajuda.\n\n"};

char *help = "\nSintaxe:\n \
main { -e | -d | -h} { -b62 | -b64 | -b85 | -b91 } {arquivo de entrada} {arquivo de saida}\n\
\n\
-e O arquivo sera codificado (binario para texto).\n\
-d O arquivo sera decodificado (texto para binario).\n\
-h Menu de ajuda.\n\
\n\
-b62 A base utilizada sera a base 62.\n\
-b64 A base utilizada sera a base 64.\n\
-b85 A base utilizada sera a base 85.\n\
-b91 A base utilizada sera a base 91.\n\
\n";

int main(int argc, char **argv){
    char opt1 = '\0', opt2 = '\0';

    opt1 = OPT1(argc, argv);
    opt2 = OPT2(argc, argv);

    switch (opt1) {
        // Ajuda.
        case 'h':
            printf("%s", help);
            break;

        // Codificar.
        case 'e':
            switch (opt2) {
                // Base 62.
                case '2':
                    break;

                // Base 64.
                case '4':
                    encode64(argv[3], argv[4]);
                    break;

                // Base 85.
                case '5':
                    encode85(argv[3], argv[4]);
                    break;

                // Base 91.
                case '1':
                    encode91(argv[3], argv[4]);
                    break;

                default:
                    printf("%s", err[1]);
                    break;
            }
            break;

        // Decodificar.
        case 'd':
            switch (opt2) {
                // Base 62.
                case '2':
                    break;

                // Base 64.
                case '4':
                    decode64(argv[3], argv[4]);
                    break;

                // Base 85.
                case '5':
                    decode85(argv[3], argv[4]);
                    break;

                // Base 91.
                case '1':
                    decode91(argv[3], argv[4]);
                    break;

                default:
                    printf("%s", err[1]);
                    break;
            }
            break;

        default:
            printf("%s", err[0]);
            break;
    }

    return 0;
}
