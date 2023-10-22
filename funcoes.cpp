#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login_viatura (){
    int opt , qpm,cod;
    char iden[50], codv[50];
    printf ("qual seu modelo de viatura? ");
    printf ("\nPolicia Regular - 1");
    printf ("\nPolicia Especializada - 2\n");
    scanf ("%d", &opt);

    if (opt == 1){
        printf("Informe o codigo da viatura: ");
        scanf (" %d", &cod);
        lerviatura(cod);
        printf ("\nInforme a quantidade de PMs:");
        scanf ("%d", &qpm);
        if (qpm < 2 && qpm < 4){
            printf("autorizacao de embarque negada:");
            }
        printf("informe a indentidade dos PMs: ");
        scanf (" %c", iden);
        
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