#include <stdio.h>
#include "funcs.h"
#define DIM 30

void inicalizarLLS(LISTA *LLS)
{
    LLS->nmrElemMAX = 1;
    LLS->nmrElem = 0; //Função serve para inicializar a lista, zero elementos validos, está recebendo o endereço da lista para que as modificações sejam realizadas no campo certo, caso contrario seria modifica a copia da estrutura
}

int inserirElemPosicaoLLS_Ord(LISTA *LLS, REGISTRO valor)
{
    if (LLS->nmrElem >= DIM)
        return 0;

    int i, pos;

    valor.codigo = LLS->nmrElemMAX;
    for (pos = LLS->nmrElem; (pos > 0) && (LLS->A[pos - 1].cddata > valor.cddata); pos--) //SE existir uma posição sobreescreva ela colocando todos os itens a direita 1 casa para esqueda
    
    {
        LLS->A[pos] = LLS->A[pos - 1];
    }

    valor.sts = "Pendente";
    LLS->A[pos] = valor;
    LLS->nmrElem++;
    LLS->nmrElemMAX++;
    return 1;
}

void mostraLLS(LISTA *LLS)
{
    int i;
    printf("TAREFAS:\n");
    for (i = 0; i < LLS->nmrElem; i++)
    {
        printf("\n Codigo da Tarefa    %d    Status: %s\n\n", LLS->A[i].codigo, LLS->A[i].sts);
        printf("Titulo:     %s", LLS->A[i].nometrab);
        printf("Disciplina: %s", LLS->A[i].dpn);
        printf("Descricao:  %s", LLS->A[i].desc);
        printf("Data:       %i/%i/%i ", LLS->A[i].dd, LLS->A[i].mm, LLS->A[i].ano);
        printf("\n");
    }
    fflush(stdin); //fflush(stdin); //se for windows
    printf("  Digite <enter> para voltar");
    getchar();
}

int buscaBinariaLLS(LISTA *LLS, int ch)
{
    int esq, dir, meio;
    esq = 0;
    dir = LLS->nmrElem - 1;
    while (esq <= dir)
    {
        meio = ((esq + dir) / 2);
        if (LLS->A[meio].cddata == ch)
            return meio;
        else
        {
            if (LLS->A[meio].cddata < ch)
                esq = meio + 1;
            else
                dir = meio - 1;
        }
    }

    return -1;
}

int excluirElemLLS(int ch, LISTA *LLS)
{
    int pos, j, TESTE = 0, i;

    pos = buscaBinariaLLS(LLS, ch);

    if (pos == -1) //QUER DIZER QUE ELE NÃO ACHOU O ELEMENTO
        return 0;

    while (LLS->A[pos - 1].cddata == ch) //COMO A busca binaria encontra apenas a posição de um elemento esse "while" garante que todos serão excluidos

    {

        if (LLS->A[pos].cddata == ch) //IF de redundancia
        {
            pos--;
        }
    }

    while (LLS->A[pos].cddata == ch)
    {

        if (LLS->A[0].cddata == ch && LLS->nmrElem == 1)
        {
            LLS->nmrElem = 0;
            return 1;
        }
        else if (LLS->A[1].cddata == ch && LLS->nmrElem <= 2 && LLS->A[1].cddata != LLS->A[0].cddata)
        {
            LLS->nmrElem--;
            return 1;
        }

        for (j = pos; j < LLS->nmrElem - 1; j++) //MOVE TODOS ELEMENTOS 1 POSIÇÃO PRA TRAS
            LLS->A[j] = LLS->A[j + 1];
        LLS->nmrElem--;
    }
    return 1;
}

int buscaElemDAt(int ch, LISTA *LLS)
{
    int pos, j, x, i;

    pos = buscaBinariaLLS(LLS, ch);

    if (pos == -1) //QUER DIZER QUE ELE NÃO ACHOU O ELEMENTO
        return 0;

    while (LLS->A[pos - 1].cddata == ch && LLS->A[pos - 1].codigo >= 0) //COMO A busca binaria encontra apenas a posição de um elemento esse "while" garante que todos serão excluidos

    {

        pos--;
    }

    printf("TAREFAS:\n");
    for (i = pos; i < LLS->nmrElem && LLS->A[i].cddata == ch; i++)
    {
        printf("\nTarefa    %d    Status: %s\n\n", LLS->A[i].codigo, LLS->A[i].sts);
        printf("Titulo:     %s", LLS->A[i].nometrab);
        printf("Disciplina: %s", LLS->A[i].dpn);
        printf("Descricao:  %s", LLS->A[i].desc);
        printf("Data:       %i/%i/%i ", LLS->A[i].dd, LLS->A[i].mm, LLS->A[i].ano);
        printf("\n");
    }

    printf("\nDigite:\n -  O valor correspondente ao codigo da tarefa para marcala como entregue\n - '0' para Voltar\n: ");
    scanf("%d", &x);

    for (i = pos; i < LLS->nmrElem && LLS->A[i].cddata == ch; i++)
    {

        if (LLS->A[i].codigo == x)
        {

            LLS->A[i].sts = "Entregue";
            return 1;
        }
    }

    fflush(stdin);

    return 1;
}

int buscaLinear(LISTA *LLS)
{

    int i, j = 0;

    for (i = 0; i < LLS->nmrElem; i++)
    {

        if (LLS->A[i].sts == "Entregue")
        {
            excluirLinear(i, LLS);
            j++;
        }
    }
    if (j == 0)
    {
        printf("\nNENHUM ITEM FOI ENCONTRADO!");
        return 0;
    }
    return 1;
}

int excluirLinear(int ch, LISTA *LLS)
{
    int j;

    if (ch == -1)
        return 0;
    for (j = ch; j < LLS->nmrElem - 1; j++)
        LLS->A[j] = LLS->A[j + 1];
    LLS->nmrElem--;
    return 1;
}