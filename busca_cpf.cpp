#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


pessoa *criar_pessoa(char *nome, char *cpf, char *cidade, int idade, int quant_pass, char *passagem, int num_inad, char *inad) {
    pessoa *p = (pessoa *) malloc(sizeof(pessoa)); // aloca memória para o pessoa
    if (p == NULL) { // verifica se a alocação foi bem sucedida
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(p->nome, nome); // copia o nome para o pessoa
    strcpy(p->cpf, cpf); // copia o cpf para o pessoa
    strcpy(p->cidade, cidade); // copia a cidade para o pessoa
    p->idade = idade; // atribui a idade ao pessoa
    p->quant_pass = quant_pass; // atribui a quantidade de passagens ao pessoa
    strcpy(p->passagens, passagem); // copia a patente para o pessoa
    p->num_inad = num_inad; // atribui o número de inadimplências ao pessoa
    strcpy(p->inad, inad);
    p->prox = NULL; // inicializa o ponteiro para o próximo pessoa como NULL
    return p; // retorna o pessoa criado
}

pessoa *l_arquivo(char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r"); // abre o arquivo para leitura
    if (arq == NULL) { // verifica se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    pessoa *lista = NULL; // inicializa a lista de policiais como NULL
    pessoa *ultimo = NULL; // inicializa o ponteiro para o último pessoa da lista como NULL
    char nome[50], cpf[50], passagens[50], cidade[20], inad[50], line[100], aux [100]; // variáveis para armazenar as informações lidas do arquivo
    int idade,quant_pass,num_inad; // variável para armazenar a idade lida do arquivo
    while (feof (arq) == 0) { // enquanto não chegar ao final do arquivo
        fscanf(arq,"%[^\n] ", nome); // lê o nome do pessoa até a quebra de linha
        fscanf(arq, "%s ", cpf); // lê o cpf do pessoa
        fscanf(arq, "%[^\n] ", cidade); // lê a cidade do pessoa
        fscanf(arq, "%d ", &idade); // lê a idade do pessoa
        fscanf(arq, "%d ", &quant_pass); // lê a quantidade de passagens do pessoa
        for (int i = 0; i < quant_pass; i++){
            fscanf(arq, "%[^\n] ", line);
            strcat(passagens, line);
            strcat(passagens, "\n");
           
        }
        fscanf(arq, "%d ", &num_inad);
        for (int i = 0; i < num_inad; i++){
            fscanf(arq, "%[^\n] ", aux);
            strcat(inad, aux);
            strcat(inad, "\n");
        }
        pessoa *p = criar_pessoa(nome, cpf, cidade, idade, quant_pass, passagens,num_inad,inad); // cria um novo pessoa com as informações lidas
        *passagens = NULL;
        *inad = NULL;
        if (lista == NULL) { // verifica se a lista está vazia
            lista = p; // faz a lista apontar para o novo pessoa
        } else {
            ultimo->prox = p; // faz o último pessoa da lista apontar para o novo pessoa
        }
        ultimo = p; // atualiza o ponteiro para o último pessoa da lista
    }
    fclose(arq); // fecha o arquivo
    return lista; // retorna a lista de policiais
}

void imp(pessoa *lst){
    pessoa *p;
    for(p = lst; p != NULL; p = p->prox){
        printf("%s\n", p->nome);
        printf("%s\n", p->cpf);
        printf("%s\n", p->cidade);
        printf("%d\n", p->idade);
        printf("%d\n", p->quant_pass);
        printf("%s\n", p->passagens);
        printf("%d\n", p->num_inad);
        printf("%s\n", p->inad);
        printf("\n");
    }
}
