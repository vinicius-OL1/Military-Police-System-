#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criptografarSenha(char *senha) {
     int comprimento = strlen(senha);

    for (int i = 0; i < comprimento; i++) {
        if ((senha[i] >= 'a' && senha[i] <= 'z') || (senha[i] >= 'A' && senha[i] <= 'Z')) {
            // Adiciona 3 unidades ao valor ASCII de cada letra
            senha[i] = senha[i] + 3;

            // Se a letra ultrapassar 'z' ou 'Z' após a adição, subtrai 26 para voltar ao alfabeto
            if ((senha[i] > 'z' && senha[i] <= 'z' + 3) || (senha[i] > 'Z' && senha[i] <= 'Z' + 3)) {
                senha[i] -= 26;
            }
        }
    }

    // Inverte a senha
    for (int i = 0; i < comprimento / 2; i++) {
        char temp = senha[i];
        senha[i] = senha[comprimento - i - 1];
        senha[comprimento - i - 1] = temp;
    }
}

int confere(policial *lista, char *nome){ 
    policial *l;
    printf("%s\n", nome);
    char buffer [100];
    int found = 0; // variável para armazenar o resultado
    strcpy(buffer, nome);
    char *token = strtok(buffer, " ,\n"); // primeiro token
    while (token != NULL) {
        printf ("%s\n", token);
        char *aux = token;
        
       for(l = lista; l != NULL; l = l->prox){
            if (strcmp(l->nome_de_guerra, aux) == 0){
                printf("O nome %s foi encontrado no arquivo.\n", aux);
                return 1;
            }
            else {
                printf("O nome %s não foi encontrado no arquivo.\n", aux);
                return 0;
            }
            
    token = strtok (NULL, " ,\n");
    
// retorna o resultado
}
}
}

int confere_senha(policial *lista, char *nome,char *senha){ 
    policial *l;
    printf("%s\n", nome);
    char buffer [100];
    char buffer2 [100];
    int found = 0; // variável para armazenar o resultado
    strcpy(buffer, nome);
    strcpy(buffer2, senha);
    char *token = strtok(buffer, " ,\n");
    char *token2 = strtok(buffer2, " ,\n"); // primeiro token
    while (token != NULL && token2 != NULL) {
        printf ("%s\n", token);
        char *aux = token;
        char *aux2 = token2;
       for(l = lista; l != NULL; l = l->prox){
            if (strcmp(l->senha, aux)==0 && strcmp(l->nome_de_guerra, aux2 ) == 0){
                return 1;
            }
        }
    token = strtok (NULL, " ,\n");
    
// retorna o resultado
}
}


int login_PM (policial *lst){
    char arq[20] = "policiais.txt";
    char senha[20];
    policial *lista_policial = ler_arquivo(arq);
    policial *p;
    printf("Digite o nome de guerra: ");
    char nome_de_guerra[50];
    scanf("%s", nome_de_guerra);

        if (confere(lista_policial, nome_de_guerra) == 1){
            printf ("Digite a senha: ");
            scanf("%s", senha);
            criptografarSenha(senha);
            if (confere_senha(lista_policial,senha,nome_de_guerra) == 1){
                printf("A senha %s foi encontrada no arquivo.\n", senha);
                
                return 1;
            }
            else {
                printf("A senha %s não foi encontrada no arquivo.\n", senha);
                return 0;
            }
            }
        else {
            printf("O nome %s não foi encontrado no arquivo.\n", nome_de_guerra);
            return 0;
        }
    }
