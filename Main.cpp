#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
struct policia
{
	int idade;
	char nome[100];
	policia *prox;
};


int main (){
    policia *lista = NULL;
    int op;
    do{

        printf("\n\n1 - viatura login");
        printf("                      2 - viatura em uso");
        printf("\n3 - COPOM");
        printf("\n4 - Policia Militar");
        printf("\n5 - Oficial");
        printf("\n6 - Comandante Geral");
        printf("\nOpcao: ");
        scanf("%d", &op);

        if(op == 1)
        {
          login_viatura();
        }
        /*
        else if(op == 2)
        {
          
        }
        else if(op == 3)
        {
       
        }
   
        }
    
        }
        */
    }while(op != 0);
    printf ("vasco");
}