#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#define DIM 30

int main()
{

    int x = 0, TEMP, tmpD, tmpM, tmpA;
    char opcao[20];
    char teste[10] = {"Pendente"};
    LISTA LLS;
    REGISTRO valor;
    inicalizarLLS(&LLS);

    do
    {
        system("@cls||clear");

        printf("\nEntre com a opcao:\n");
        printf(" 'I' - inserir um trabalho na agenda\n");
        printf(" 'R' - Remover trabalho da agenda\n");
        printf(" 'C' - Consultar os trabalhos na agenda\n");
        printf(" 'E' - Exibir os trabalhos da agenda por data\n");
        printf(" 'F' - Sair\n");
        scanf("%str", opcao);

        if (opcao[1] != '\0')
            opcao[0] = 'V';
        else if (opcao[0] == 'i')
            opcao[0] = 'I';
        else if (opcao[0] == 'r')
            opcao[0] = 'R';
        else if (opcao[0] == 'c')
            opcao[0] = 'C';
        else if (opcao[0] == 'e')
            opcao[0] = 'E';
        else if (opcao[0] == 'f')
            opcao[0] = 'F';

        fflush(stdin);
        getchar();
        switch (opcao[0])

        {

        case 'I':
            system("@cls||clear");

            printf(" Preencha os campos para que a tarefa seja computada:\n\n");
            printf("Digite o Nome do Trabalho: ");

            fgets(valor.nometrab, 20, stdin);
            printf("Digite a Disciplina do trabalho: ");

            fgets(valor.dpn, 20, stdin);

            printf("Digite uma Descricao para o trabalho: ");
            fgets(valor.desc, 200, stdin);

            do
            {
                system("@cls||clear");
                printf("Digite a Data de Entraga para do trabalho:\n");
                printf("Dia: ");
                scanf("%d", &valor.dd);
                if (valor.dd <= 0 || valor.dd > 31)
                {
                    printf("FORMATO INVALIDO!!\nFavor insira um numero de 1 a 31\n");
                    getchar();
                    getchar();
                }
            } while (valor.dd <= 0 || valor.dd > 31);
            do
            {
                printf("Mes: ");
                scanf("%d", &valor.mm);
                if (valor.mm <= 0 || valor.mm > 12)
                {
                    printf("Favor insira um numero de 1 a 12\n");
                    getchar();
                    getchar();
                    system("@cls||clear");
                }
            } while (valor.mm <= 0 || valor.mm > 12);

            do
            {
                printf("Ano: ");
                scanf("%d", &valor.ano);
                if (valor.ano < 2019 || valor.ano > 2099)
                {
                    printf("Favor insira um numero entre 2019 e 2099\n");
                    getchar();
                    getchar();
                    system("@cls||clear");
                }
            } while (valor.ano < 2019 || valor.ano > 2099);

            valor.codigo = (valor.ano * 10000) + (valor.mm * 100) + valor.dd;
            fflush(stdin);
            getchar();
            TEMP = inserirElemPosicaoLLS_Ord(&LLS, valor);
            if (TEMP == 0)
            {
                printf("Ocorreu um ERRO, talvez a posicao desejada nao exista na lista\n"); //Ou está vazia na lista
            }
            else
            {
                printf("SUCESSO\n");
            }

            printf("Digite <enter> para voltar");

            getchar();

            break;

        case 'R':
            system("@cls||clear");

            printf("\nEntre com a opcao:\n");
            printf(" 'A' - Remover da agenda todos os trabalhos com status 'Entregue \n");
            printf(" 'D' - Remover trabalhos de uma determinada data na agenda\n");
            scanf("%str", opcao);
            if (opcao[1] != '\0')
                opcao[0] = 'V';
            else if (opcao[0] == 'a')
                opcao[0] = 'A';
            else if (opcao[0] == 'd')
                opcao[0] = 'D';

                            switch (opcao[0])

                    {

                    case 'A':
                        system("@cls||clear");
                        printf("TESTE A");
                        break;

                    case 'D':
                        system("@cls||clear");
                        do
                    {
                        system("@cls||clear");
                        printf("Digite a Data Corespondente as tarefas que deseja excluir:\n");
                        printf("Dia: ");
                        scanf("%d", &tmpD);
                        if (tmpD <= 0 || tmpD > 31)
                        {
                            printf("FORMATO INVALIDO!!\nFavor insira um numero de 1 a 31\n");
                            getchar();
                            getchar();
                        }
                    } while (tmpD <= 0 || tmpD > 31);
                    do
                    {
                        printf("Mes: ");
                        scanf("%d", &tmpM);
                        if (tmpM <= 0 || tmpM > 12)
                        {
                            printf("Favor insira um numero de 1 a 12\n");
                            getchar();
                            getchar();
                            system("@cls||clear");
                        }
                    } while (tmpM <= 0 || tmpM > 12);

                    do
                    {
                        printf("Ano: ");
                        scanf("%d", &tmpA);
                        if (tmpA < 2019 || tmpA > 2099)
                        {
                            printf("Favor insira um numero entre 2019 e 2099\n");
                            getchar();
                            getchar();
                            system("@cls||clear");
                        }
                    } while (tmpA < 2019 || tmpA > 2099);

                    TEMP = (tmpA * 10000) + (tmpM * 100) + tmpD;
                    fflush(stdin);
                    getchar();
excluirElemLLS(TEMP,&LLS);
                        break;

                    default:
                        system("@cls||clear");
                        printf("ATENCAO - Opcao invalida! \n");
                        printf("Digite <enter> para voltar");
                        getchar();
                        getchar();
                        break;
                    }

            break;
        case 'C':
            system("@cls||clear");
            mostraLLS(&LLS);

            break;
        case 'E':
            system("@cls||clear");
            printf("TESTE E");

            break;

        case 'F':
            system("@cls||clear");
            printf("\nSolicitou a opcao - sair!\n");
            exit(0);
            break;
        default:
            system("@cls||clear");
            printf("ATENCAO - Opcao invalida! \n");
            printf("Digite <enter> para voltar");
            getchar();
            break;
        }
    } while (x == 0);
}
