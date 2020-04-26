#include <stdio.h>
#include "funcs.h"
#define DIM 30

void inicalizarLLS(LISTA *LLS)
{
    LLS->nmrElem = 0; //Função serve para inicializar a lista, zero elementos validos, está recebendo o endereço da lista para que as modificações sejam realizadas no campo certo, caso contrario seria modifica a copia da estrutura
}

int inserirElemPosicaoLLS_Ord(LISTA *LLS, REGISTRO valor)
{
    if (LLS->nmrElem >= DIM)
        return 0;

    int i, pos;

    for (pos = LLS->nmrElem; (pos > 0) && (LLS->A[pos - 1].busqData > valor.busqData); pos--)
    {
        LLS->A[pos] = LLS->A[pos - 1];
    }
    LLS->A[pos] = valor;
    LLS->nmrElem++;
    return 1;
}

void mostraLLS(LISTA *LLS)
{
    int i;
    printf("TAREFAS:\n");
    for (i = 0; i < LLS->nmrElem; i++)
    {
        printf("\nTrabalho %d\n\n", i + 1);
        printf("Titulo:     %s", LLS->A[i].nometrab);
        printf("Disciplina: %s", LLS->A[i].dpn);
        printf("Descricao:  %s", LLS->A[i].desc);
        printf("Data:       %i/%i/%i ", LLS->A[i].dd,LLS->A[i].mm,LLS->A[i].ano);
        printf("\n");
    }
    fflush(stdin); //fflush(stdin); //se for windows
    printf("  Digite <enter> para voltar");
    getchar();
}