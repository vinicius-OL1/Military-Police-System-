#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME_LENGTH 50
#define MAX_NAMES 10


policial *criar_policial(char *nome, char *cpf, char *nome_de_guerra, char *cidade, int idade, char *patente, char *senha) {
    policial *p = (policial *) malloc(sizeof(policial)); // aloca memória para o policial
    if (p == NULL) { // verifica se a alocação foi bem sucedida
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(p->nome, nome); // copia o nome para o policial
    strcpy(p->cpf, cpf); // copia o cpf para o policial
    strcpy(p->nome_de_guerra, nome_de_guerra); // copia o nome de guerra para o policial
    strcpy(p->cidade, cidade); // copia a cidade para o policial
    p->idade = idade; // atribui a idade ao policial
    strcpy(p->patente, patente); // copia a patente para o policial
    strcpy(p->senha, senha); // copia a senha para o policial
    p->prox = NULL; // inicializa o ponteiro para o próximo policial como NULL
    return p; // retorna o policial criado
}

policial *ler_arquivo(char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "r"); // abre o arquivo para leitura
    if (arq == NULL) { // verifica se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    policial *lista = NULL; // inicializa a lista de policiais como NULL
    policial *ultimo = NULL; // inicializa o ponteiro para o último policial da lista como NULL
    char nome[50], cpf[50], nome_de_guerra[10], cidade[20], patente[20], senha[20]; // variáveis para armazenar as informações lidas do arquivo
    int idade; // variável para armazenar a idade lida do arquivo
    while (feof (arq) == 0) { // enquanto não chegar ao final do arquivo
        fscanf(arq,"%[^\n] ", nome); // lê o nome do policial até a quebra de linha
        fscanf(arq, "%s ", cpf); // lê o cpf do policial
        fscanf(arq, "%s ", nome_de_guerra); // lê o nome de guerra do policial
        fscanf(arq, "%s ", cidade); // lê a cidade do policial
        fscanf(arq, "%d ", &idade); // lê a idade do policial
        fscanf(arq, "%[^\n] ", patente); // lê a patente do policial
        fscanf(arq, "%s  ", senha); // lê a senha do policial
        policial *p = criar_policial(nome, cpf, nome_de_guerra, cidade, idade, patente, senha); // cria um novo policial com as informações lidas

        if (lista == NULL) { // verifica se a lista está vazia
            lista = p; // faz a lista apontar para o novo policial
        } else {
            ultimo->prox = p; // faz o último policial da lista apontar para o novo policial
        }
        ultimo = p; // atualiza o ponteiro para o último policial da lista
    }
    fclose(arq); // fecha o arquivo
    return lista; // retorna a lista de policiais
}

int login_viatura (policial *&lst,policia *&lista,int codi){
    char arq[20] = "policiais.txt";
    printf("arquivo: %s\n", arq);
    policial *lista_policial = ler_arquivo(arq);
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
                busca_nome(lista_policial,iden);
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
int busca_nome(policial *lista, char *nome){
policial *p;
int found = 0; // variável para armazenar o resultado
char *token = strtok(nome, " "); // primeiro token
while (token != NULL) { // loop para percorrer todos os tokens
    for(p = lista; p != NULL; p = p->prox){
        if (strcmp(p->nome_de_guerra, token) == 0){
            printf("O nome %s foi encontrado no arquivo.\n", token);
            found = 1; // atualiza o resultado
            break; // sai do loop interno
        }
    }
    token = strtok(NULL, " "); // próximo token
}
if (found == 0) { // se nenhum nome foi encontrado
    printf("O nome %s não foi encontrado no arquivo.\n", nome);
}
return found; // retorna o resultado

}


// Função que lê um arquivo txt e guarda as informações dos policiais em uma lista encadeada


