#include <stdio.h>
#include "funcs.h"
#define DIM 30






void inicalizarLLS(LISTA *LLS)
{
    LLS->nmrElem = 0;            //Função serve para inicializar a lista, zero elementos validos, está recebendo o endereço da lista para que as modificações sejam realizadas no campo certo, caso contrario seria modifica a copia da estrutura
}



int inserirElemPosicaoLLS_Ord(LISTA *LLS, REGISTRO valor)
{
    if (LLS->nmrElem >= DIM)
        return 0;

    int i, pos;

    for (pos = LLS->nmrElem; (pos > 0) && (LLS->A[pos - 1].teste > valor.busqData); pos--)
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
    printf("LISTA: < ");
    for (i = 0; i < LLS->nmrElem; i++)
    {
        printf("%i, ", LLS->A[i].busqData);
    
    }
    fflush(stdin); //fflush(stdin); //se for windows
    printf(" >\n Digite <enter> para voltar");
    getchar();
}