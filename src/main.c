/*
 *  Universidade de Brasília
 *  Instituto de Ciencias Exatas
 *  Departamento de Ciência da Computação
 *
 *  Software Básico - Turma A - 1/2016
 *
 *  Codificadores Binários
 *
 *  Grupo 3:
 *      - Carlos Joel Tavares da Silva  13/0007293
 *      - Felipe Barreto Fernandes      09/0112831
 *      - Felipe Borges Albuquerque     09/93972
 *      - Géssica Neves Sodré da Silva  11/0146115
 *      - Pedro da Costa Abreu Júnior   11/0018800
 *
 *  Arquivo fonte principal "main.c"
 *
 *  Copyright © 2016 UnB. All rights reserved.
 */
#include "base62.h"
#include "base64.h"
#include "base85.h"
#include "base91.h"
#include "bib.h"

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

void conversor(char opt1, char opt2, char *a_entrada, char *a_saida){
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
                    encode64(a_entrada, a_saida);
                    break;

                // Base 85.
                case '5':
                    encode85(a_entrada, a_saida);
                    break;

                // Base 91.
                case '1':
                    encode91(a_entrada, a_saida);
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
                    decode64(a_entrada, a_saida);
                    break;

                // Base 85.
                case '5':
                    decode85(a_entrada, a_saida);
                    break;

                // Base 91.
                case '1':
                    decode91(a_entrada, a_saida);
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
}

int main(int argc, char **argv){
    char opt1 = '\0', opt2 = '\0';
    char *a_entrada, *a_saida;

    // Se os valores forem passados as variáveis serão inicializadas
    if(argc == 5){
        opt1 = OPT1(argc, argv);
        opt2 = OPT2(argc, argv);
        a_entrada = argv[3];
        a_saida = argv[4];
    }
    // Os parâmetros serão solicitados novamente
    else{
        // Caso argc seja maior que 1, o usuário passou os parâmetros, mas de forma incorreta
		if(argc != 1){
			printf("\nOs valores não foram passados corretamente. Por favor, informe novamente.\n");
		}
		// Pede pela operação que deseja realizar
		while(!existe_opcao(opt1)){
            printf("\nInforme a operação que deseja realizar. 'e' encoding, 'd' decoding.\n");
            scanf("%c", opt1);
            getchar();
		}
		// Pede a base a ser utilizada para realizar a operação
		while(!existe_base(opt2)){
            printf("\nInforme a base que deseja utilizar.\n");
            printf("\n'1' - base91, '2' - base62, '4' - base64 ou '5' - base85\n");
            scanf("%c", opt2);
            getchar();
		}
		// Pede pelo arquivo de entrada a ser codificado ou decodificado
		while(!existe_arquivo(a_entrada)){
            printf("\nInforme o nome do arquivo de entrada:\n");
            scanf("%s", a_entrada);
            getchar();
		}
        // Se não houver arquivo de saída, será criado em uma saída padrão
		a_saida = "saida";
    }

    conversor(opt1, opt2, a_entrada, a_saida);

    return 0;
}
