
#define DIM 30

typedef struct
{
    int mm, dd, ano, cddata, teste,codigo;
    char dpn[20], desc[200],  nometrab[20];
    char *sts;
                 //OS registro, no  caso são as informações que serão armazenadas
} REGISTRO;

typedef struct
{
    REGISTRO A[DIM]; //A lista é um Aranjo de Registros
    int nmrElem;
   int nmrElemMAX;
} LISTA;

void inicalizarLLS(LISTA *LLS);
void mostraLLS(LISTA *LLS);
int inserirElemPosicaoLLS_Ord(LISTA *LLS, REGISTRO valor);
int buscaBinariaLLS(LISTA *LLS, int ch);
int excluirElemLLS(int ch, LISTA *LLS);
int buscaElemDAt (int ch, LISTA *LLS);
int buscaLinear(LISTA *LLS);
int excluirLinear(int ch, LISTA *LLS);