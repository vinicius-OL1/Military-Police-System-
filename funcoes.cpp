#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 50
#define MAX_NAMES 10

int login_viatura (policia *&lista,int codi){
    int opt , qpm, cod, aut;
    char iden[100], codv[50];
    printf ("\nPolicia Regular - 1");
    printf ("\nPolicia Especializada - 2\n");
    printf ("\nqual seu modelo de viatura? ");
    scanf ("%d", &opt);
    if (opt == 1){
        printf("Informe o codigo da viatura: ");
        scanf ("%d", &cod);
        if(lerviatura(cod) == 1){
            printf("\nautorizacao de embarque concedida");
            printf ("\nInforme a quantidade de PMs:");
        scanf ("%d", &qpm);
        if (qpm < 2 && qpm < 4){
            printf("\nautorizacao de embarque negada:");
            return 0;
            }
        else{
        printf("\ninforme a indentidade do PMs: ");
        scanf (" %s", iden);
        inserir(cod,iden, lista);
        imprimir(lista);
        printf("\n1-Apto para ocorrencia ");
        printf("\n2-cancelar embarcaçao\n");
        scanf (" %d", &aut);
        if (aut == 1){
            printf("viatura direcionada para rondas, no aguardo de chamadas policiais\n");
            printf(">1 - voltar ao menu principal\n");
            scanf (" %d", &aut);
            if (aut == 1){
                codi = cod;
                return 1;
            }
        }   
        else{
            return 0;
        }
    }
     }
        }
        else if (opt == 2){
            printf("Informe o codigo da viatura: ");
            scanf ("%d", &cod);
            if(lerviatura(cod) == 1){
                printf("\nautorizacao de embarque concedida");
                printf ("\nInforme a quantidade de PMs:");
                scanf ("%d", &qpm);
                printf("\nautorizacao de embarque concedida");
                printf ("\nInforme a quantidade de PMs:");
                scanf ("%d", &qpm);
                if (qpm != 4){
                    printf("\nautorizacao de embarque negada:");
                    return 0;
                    }
        else{
        printf("\ninforme a indentidade do PMs: ");
        scanf (" %s", iden);
        inserir(cod,iden, lista);
        imprimir(lista);
        printf("\n1-Apto para ocorrencia ");
        printf("\n2-cancelar embarcaçao\n");
        scanf (" %d", &aut);
         if (aut == 1){
            return 1;
        }
        else{
            return 0;
        }
            }
        }
    }
}  
int lerviatura(int num){
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

void inserir(int n_v,char *nome, policia *&L){
	policia *novo;
	novo = (policia*) malloc(sizeof(policia));
    novo->n_v = n_v;
	strcpy(novo->nome, nome);
	novo->prox = L;
	L = novo;
}

void imprimir(policia *lst){
    policia *p;
    for(p = lst; p != NULL; p = p->prox){
        printf("%d ", p->n_v);
        printf("%s ", p->nome);
    }
        


}
int viatura_em_uso(policia *lista, int codi){
    int vias;
    printf ("%d", codi);
    printf("identificador da viatura: ");
    scanf("%d", &vias);
    if (vias == codi){
        printf("viatura em uso");
        return 1;
    }
    else{
        printf("viatura nao em uso");
        return 0;
    }
}