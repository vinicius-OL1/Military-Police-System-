#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int verifica(char *descricao) {

  const char *itens[] = {"Violencia domestica", "tentativa de homicidio", "roubo em ocorrencia", "homicidio"};
  int n = sizeof(itens) / sizeof(itens[0]); // Obtém o número de itens
  for (int i = 0; i < n; i++) {
    if (strcmp(descricao, itens[i]) == 0) {
      return 1; 
    }
  }
  return 0; 
}

void inserir_caso_norm(caso_norm *&l_n_i,caso_norm *&l_n_f,char *descricao, char *local){
    caso_norm *novo;
    novo = (caso_norm*) malloc(sizeof(caso_norm));
    strcpy(novo->descricao, descricao);
    strcpy(novo->local, local); 
    // if (verifica(descricao) == 1){
    //     if (l_n_i == NULL){
    //         l_n_i = l_n_f = novo;
    //     }
    //     else {
    //         novo->prox = l_n_i;
    //         l_n_i = novo;
    //     } 
    // }
    // else{
        if (l_n_i == NULL)
        l_n_i = l_n_f = novo;
    else {
        l_n_f->prox = novo;
        l_n_f = novo;
    }
    }
    

void inserir_caso_esp(caso_esp *&l_n_i,caso_esp *&l_n_f,char *descricao, char *local){
    caso_esp *novo;
    novo = (caso_esp*) malloc(sizeof(caso_esp));
    strcpy(novo->descricao, descricao);
    strcpy(novo->local, local);
    if (l_n_i == NULL)
        l_n_i = l_n_f = novo;
    else {
        l_n_f->prox = novo;
        l_n_f = novo;
    }
}
void imprimir_lista(caso_norm *L){
    caso_norm *p;
    for(p = L; p != NULL; p = p->prox){
        printf("%s\n", p->descricao);
        printf("%s\n", p->local);
    }
}

int criar_chamada(policial *&lst,caso_norm *&lista_norm_i,caso_norm *&lista_norm_f, caso_esp *&lista_esp_i, caso_esp *&lista_esp_f){
    int tip;
    char descricao[100], local[50];
    printf ("1 - Policia Normal     2 - Policia Especializada\n");
    scanf ("%d", &tip);
    printf ("Descricao da ocorrencia: ");
    scanf (" %[^\n]", descricao);   
    printf("Localizacao: ");
    scanf (" %[^\n]", local);
    if (tip == 1){
        inserir_caso_norm(lista_norm_i,lista_norm_f,descricao,local);
        imprimir_lista(lista_norm_i);
        return 1;
    }
    else if (tip == 2){
        inserir_caso_esp(lista_esp_i,lista_esp_f,descricao,local);
        //imprimir_lista(lista_norm_i,lista_norm_f);
        return 1;
    }
    else{
        printf ("tipo invalido");
        return 0;
    }
}
   