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
        case '1': case 'e':
            switch (opt2) {
                // Base 62.
                case '2':
                    break;

                // Base 64.
                case '4':
                    encode64(a_entrada, a_saida);
                    printf("Codificado com Sucesso!\n");
                    break;

                // Base 85.
                case '5':
                    encode85(a_entrada, a_saida);
                    printf("Codificado com Sucesso!\n");
                    break;

                // Base 91.
                case '1':
                    encode91(a_entrada, a_saida);
                    printf("Codificado com Sucesso!\n");
                    break;

                default:
                    printf("%s", err[1]);
                    break;
            }
            break;

        // Decodificar.
        case '2': case 'd':
            switch (opt2) {
                // Base 62.
                case '2':
                    break;

                // Base 64.
                case '4':
                    decode64(a_entrada, a_saida);
                    printf("Decodificado com sucesso!\n");
                    break;

                // Base 85.
                case '5':
                    decode85(a_entrada, a_saida);
                    printf("Decodificado com sucesso!\n");
                    break;

                // Base 91.
                case '1':
                    decode91(a_entrada, a_saida);
                    printf("Decodificado com sucesso!\n");
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
    getchar();
    getchar();
}

int main(int argc, char **argv){
    char op = '\0', base = '\0';
    char arq_entrada[20], arq_saida[20];
    /* Se os valores forem passados as variáveis serão inicializadas */
    if(argc == 5){
        op = OPT1(argc, argv);
        base = OPT2(argc, argv);
        strcpy(arq_entrada, argv[3]);
        strcpy(arq_saida, argv[4]);
    }
    /* Os parâmetros serão solicitados novamente*/
    else{
        /* Caso argc seja maior que 1, o usuário passou os parâmetros, mas de forma incorreta*/
        printf("Bem Vindo ao programa de conversoes do Grupo 3!\n");
        printf("E antes que voce pergunte, nao, nao somos Universal\n");

        /* Pede a base a ser utilizada para realizar a operação*/
        do{
            printf("\nInforme a base que deseja utilizar.\n");
            scanf("%c", &base);
            getchar();
            //while(getchar() != '\n');
        }while(!existe_opcao(base));


        /* Pede pela operação que deseja realizar*/
        do{
            printf("\nInforme a operacao que deseja realizar. \n1- encoding \n2- decoding\n");
            scanf("%c", &op);
            getchar();
            //getchar();
        }while(op != '1' &&  op!= '2');

        /* Pede pelo arquivo de entrada a ser codificado ou decodificado*/
        printf("\nInforme o nome do arquivo de entrada: ");
        scanf("%s", arq_entrada);
        while(!existe_arquivo(arq_entrada)){
            printf("\nArquivo informado nao existe! Tente novamente ");
            printf("\nInforme o nome do arquivo que de entrada: ");
            scanf("%s", arq_entrada);
        }

        /* Se não houver arquivo de saída, será criado em uma saída padrão*/

        printf("\nInforme o nome do arquivo de saida: ");
        scanf("%s", arq_saida);
    }

    conversor(op, base, arq_entrada, arq_saida);
    return 0;
}
