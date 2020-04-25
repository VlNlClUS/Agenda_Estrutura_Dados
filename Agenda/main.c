#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
int main(){


    int x = 0;
   char opcao[20];
  

   
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
     
            if(opcao[1] != '\0' ) opcao[0]='V';
            else if(opcao[0] == 'i') opcao[0]='I';
             else if (opcao[0] == 'r') opcao[0]='R';
              else if (opcao[0] == 'c') opcao[0]='C';
               else if (opcao[0] == 'e') opcao[0]='E';
                else if (opcao[0] == 'f') opcao[0]='F';
                
                 getchar();  
        switch (opcao[0])
        
        
        {
        
        case 'I':
         printf("TESTE I");
         
            break;

        case 'R':
         printf("TESTE R");
       
            break;
        case 'C':
        printf("TESTE C");
     
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
             break;     }
    } while (x == 0);
}


