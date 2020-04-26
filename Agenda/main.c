#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"
#define DIM 30

int main()
{

    int x = 0, TEMP;
    char opcao[20];
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

            printf(" Preencha os campos para que a tarefa seja computada:\n\n");
            printf("Digite o Nome do Trabalho: ");

            fgets(valor.nometrab, 20, stdin);
            printf("Digite a Disciplina do trabalho: ");

            fgets(valor.dpn, 80, stdin);

            printf("Digite uma Descricao para o trabalho: ");

            fgets(valor.desc, 80, stdin);

            printf("Digite a Data de Entraga para do trabalho:\n");
            printf("Dia: ");
            scanf("%d", &valor.dd);
            printf("Mes: ");
            scanf("%d", &valor.mm);
            printf("Ano: ");
            scanf("%d", &valor.ano);
            valor.busqData = (valor.ano * 10000) + (valor.mm * 100) + valor.dd;
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
            printf("TESTE R");

            break;
        case 'C':
            mostraLLS(&LLS);

            break;
        case 'E':
            printf("TESTE E");

            break;

        case 'F':
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
