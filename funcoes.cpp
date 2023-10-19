#include "lista.h"
#include <stdio.h>

int login_viatura (){
    int opt, cod , qpm;
    char iden[50];
    printf ("qual seu modelo de viatura? ");
    printf ("\nPolicia Regular - 1");
    printf ("\nPolicia Especializada - 2\n");
    scanf ("%d", &opt);
    FILE *farq;

    farq = fopen("viaturas.txt", "r");

    if (farq == NULL) 
    {
        printf("Problemas na CRIACAO do arquivo\n");
    } 

    if (opt == 1){
        printf("Informe o codigo da viatura: ");
        scanf ("%d", &cod);
        if (cod == fgetc(farq)){
            printf ("achou...");
        }
        printf ("\nInforme a quantidade de PMs:");
        scanf ("%d", &qpm);
        if (qpm < 2 && qpm < 4){
            printf("autorizacao de embarque negada:");
            return(0);
            }
        printf("informe a indentidade dos PMs: ");
        scanf (" %c", iden);
        

    }
    return (0);
}