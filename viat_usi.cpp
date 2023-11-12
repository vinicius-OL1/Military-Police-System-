#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void busca(pessoa *lst, char *cpf){
    pessoa *p;
    for (p = lst; p != NULL; p = p->prox){ 
    if (strcmp(p->cpf, cpf) == 0){
        printf("nome: %s\n", p->nome);
        printf("cpf: %s\n", p->cpf);
        printf("cidade: %s\n", p->cidade);
        printf("idade: %d\n", p->idade);
        printf("quantidade de passagens: %d\n", p->quant_pass);
        printf("passagens: %s\n", p->passagens);
        printf("numero de inadimplencias: %d\n", p->num_inad);
        printf("inadimplencias: %s\n", p->inad);
        int parar;
        printf("1 - encerrar visualizacao\n");
        scanf(" %d", &parar);
        printf("\n");
        if (parar == 1){
            break;
        }
    }
    else{
        printf("cpf nao encontrado");
    }
    }

}

int viatura_em_uso(policia *&lst,caso_norm *&f, caso_esp *&g, char *&poli, char *&tip, char *&presos, char *&descricao, char *&local){
    int vias;
    policia *p;
    printf("identificador da viatura: ");
    scanf("%d", &vias);
    if (lst == NULL){
        printf(" sem viaturas");
        return 0;
    }
    for (p = lst; p != NULL; p = p->prox){ 
        printf("%d\n", p->n_v);
    if (p->n_v == vias){
        break;
    }
    }
    if (p == NULL){
        printf("viatura nao encontrada");
        return 0;
    }   
    if (strcmp(p->estado, "livre") == 0){
        alt_estado(p,f,g,poli,tip,presos,descricao,local);
    }
    else {
        printf("viatura em uso");
        return 1;
    }
}

int alt_estado(policia *&l, caso_norm *&f, caso_esp *&g, char *&poli, char *&tip, char *&presos, char *&descricao, char *&local) {
    // Percorre a lista até encontrar um elemento com estado NULL
    int quant = 0;
    char cpfs[100];
    int scoimp = 0;
    if (l-> tip == 1){
            if (f != NULL) {
                char estado [20] = "chamada atribuida";
                // Imprime a descrição e o local do primeiro elemento da fila
                printf("Descricao: %s\n", f->descricao);
                printf("Local: %s\n", f->local);
                int esc = 0;
                while (esc != 1 && esc != 2){
                    printf("1 - confirmar acao policial  2 - acao policial dispensada\n");
                    scanf("%d", &esc);
                }
                    caso_norm *aux = f;
                    f = f->prox;
                    free(aux);
                    if (esc == 2){
                    printf("acao policial dispensada\n");
                    
                    return 2;
                }
                if (esc == 1){
                    printf("acao policial confirmada\n");
                 //   strcpy(local, f->local);
                //    strcpy(descricao, f->descricao);
                 //   strcpy(poli, l->nome);
                  //  strcpy(tip, "normal");
                  //  strcpy(presos, "nenhum");
                  //  criar_oficio(tip, descricao, local, poli, presos);
                  int esc2 = 0;
                    while (esc2 != 4){
                        printf("1 - pesquisa por cpf\n");
                        printf("2 - solicitar reforco\n");
                        printf("3 - prisao em andamento\n");
                        printf("4 - encerrar ocorencia\n");
                        scanf(" %d", &esc2);
                    
                    if (esc2 == 1){
                        char arq[20] = "pessoas.txt";
                        pessoa *lista_pess = l_arquivo(arq);
                        char cpf[50];
                        printf("cpf: ");
                        scanf(" %s", cpf);
                        busca(lista_pess, cpf);
                    }
                    else if (esc2 == 3){
                        char estado2 [20] = "indisponivel";
                        strcpy(l->estado, estado2);
                        printf("individuos conduzidos para a DP:");
                        scanf (" %d", &quant);
                        printf("cpfs: ");
                        scanf(" %[^\n]", cpfs);
                        printf ("1 - para retorno para DP\n2 - voltar para o menu principal\n ");
                        scanf (" %d", &scoimp);

                        
                    }
                    }
                return 1;
                }
            }
            else {
                printf("sem casos no momento.\n");
                
        }
            
    }
    else if (l-> tip == 2){
       if (g != NULL) {
                char estado [20] = "chamada atribuida";
                // Imprime a descrição e o local do primeiro elemento da fila
                printf("Descricao: %s\n", g->descricao);
                printf("Local: %s\n", g->local);
                int esc = 0;
                while (esc != 1 && esc != 2){
                    printf("1 - confirmar acao policial  2 - acao policial dispensada\n");
                    scanf("%d", &esc);
                }
                    caso_esp *aux = g;
                    g = g->prox;
                    free(aux);
                if (esc == 2){
                    printf("acao policial dispensada\n");
                    
                    return 2;
                }
                if (esc == 1){
                    printf("acao policial confirmada\n");
                  //  strcpy(local, g->local);
                  //  strcpy(descricao, g->descricao);
                  //  strcpy(poli, l->nome);
                  // strcpy(tip, "especializada");
                  //  strcpy(presos, "nenhum");
                  //  criar_oficio(tip, descricao, local, poli, presos);
                    int esc2 = 0;
                    while (esc2 != 4){
                        printf("1 - pesquisa por cpf\n");
                        printf("2 - solicitar reforco\n");
                        printf("3 - prisao em andamento\n");
                        printf("4 - encerrar ocorencia\n");
                        scanf(" %d", &esc2);
                    
                    if (esc2 == 1){
                        char arq[20] = "pessoas.txt";
                        pessoa *lista_pess = l_arquivo(arq);
                        char cpf[50];
                        printf("cpf: ");
                        scanf(" %s", cpf);
                        busca(lista_pess, cpf);
                    }
                    else if (esc2 == 3){
                        char estado2 [20] = "indisponivel";
                        strcpy(l->estado, estado2);
                        printf("individuos conduzidos para a DP:");
                        scanf (" %d", &quant);
                        printf("cpfs: ");
                        scanf(" %[^\n]", cpfs);
                        printf ("1 - para retorno para DP\n2 - voltar para o menu principal\n ");
                        scanf (" %d", &scoimp);

                        
                    }
                    }
                return 1;
                }
            }
            else {
                printf("sem casos no momento.\n");
                
        }
            
    }

}