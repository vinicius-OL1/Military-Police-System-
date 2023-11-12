#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void desalocar_lista1(policia *lista) {

    policia *aux = lista;
    policia *prox;
    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;

  }
}
void desalocar_lista2(policial *lista){
    policial *aux = lista;
    policial *prox;
    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}

void desalocar_lista3(caso_esp *lista){
    caso_esp *aux = lista;
    caso_esp *prox;
    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}

void desalocar_lista4(caso_norm *lista){
    caso_norm *aux = lista;
    caso_norm *prox;
    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}
