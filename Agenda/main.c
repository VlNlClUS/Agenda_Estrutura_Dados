#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
int main(){


    int x = 0;
   char opcao;
  

   
    do
    {
        system("@cls||clear");
        
        printf("\nEntre com a opcao:\n");
        printf(" 'I' - inserir um trabalho na agenda\n");
        printf(" 'R' - Remover trabalho da agenda\n");
        printf(" 'C' - Consultar os trabalhos na agenda\n");
        printf(" 'E' - Exibir os trabalhos da agenda por data\n");
        printf(" 'F' - Sair\n");
        scanf("%c", &opcao);
     
            if(opcao == 'i') opcao='I';
             else if (opcao == 'r') opcao='R';
              else if (opcao == 'c') opcao='C';
               else if (opcao == 'e') opcao='E';
                else if (opcao == 'f') opcao='F';
                
                 getchar();  
        switch (opcao)
        
        
        {
        
        case 'I':
         printf("TESTE I");
         
            break;

        case 'R':
         printf("TESTE R");
         fflush(stdin);
            break;
        case 'C':
        printf("TESTE C");
        fflush(stdin);
            break;
        case 'E':
          printf("TESTE E");
          fflush(stdin);
            break;
       
        case 'F':
            printf("\nSolicitou a opcao - sair!\n");
            exit(0);
            break;
        default:
            printf("ATENCAO - Opcao invalida!Digite: \n");
             fflush(stdin);
             break;     }
    } while (x == 0);
}


