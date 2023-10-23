#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login_viatura (){
    int opt , qpm, cod, aut;
    char iden[100], codv[50];
    printf ("\nPolicia Regular - 1");
    printf ("\nPolicia Especializada - 2\n");
    printf ("\nqual seu modelo de viatura? ");
    scanf ("%d", &opt);
    if (opt == 1){
        printf("Informe o codigo da viatura: ");
        scanf (" %d", &cod);
        if(lerviatura(cod) == 1){
            printf("\nautorizacao de embarque concedida");
            printf ("\nInforme a quantidade de PMs:");
        scanf ("%d", &qpm);
        if (qpm < 2 && qpm < 4){
            printf("\nautorizacao de embarque negada:");
            return 0;
            }
        else{
        printf("\ninforme a indentidade dos PMs: ");
        scanf (" %c", iden);
        printf("\n1-Apto para ocorrencia ");
        printf("\n2-cancelar embarcaçao\n");
        scanf (" %d", &aut);
        if (opt == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
        
     }
        }
        else{
            printf("autorizacao de embarque negada");
        }

       
   
}
int lerviatura(int num) {
    FILE *fp;
    char str[100];
    int found = 0;

    fp = fopen("viaturas.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    while (fgets(str, 100, fp) != NULL) {
        if (num == atoi(str)) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("O número %d foi encontrado no arquivo.\n", num);
        return 1;
    } else {
        printf("O número %d não foi encontrado no arquivo.\n", num);
        return 0;
    }
}