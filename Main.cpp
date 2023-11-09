#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#define Max 100
#define MAX_NAME_LENGTH 50
#define MAX_NAMES 10

int main (){
    policia *lista = NULL;
    policial *lst = NULL;
    int op,cod = 0;
    do{
        printf("\n\n1 - viatura login");
        printf("                      2 - viatura em uso");
        printf("\n3 - COPOM");
        printf("\n4 - Policia Militar");
        printf("\n5 - Oficial");
        printf("\n6 - Comandante Geral");
        printf("\n7 - imprimir lista de PMs");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if(op == 1){
          login_viatura(lst,lista,cod);
        }
        else if(op == 2){
          viatura_em_uso(lista,cod);
        }
        
        else if(op == 7)
        {
            imprimir(lista);
        }
        /*
   
        }
    
        }
        */
    }while(op != 0);
    printf ("vasco");
}