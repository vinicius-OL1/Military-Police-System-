#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char criptografar(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {

    c = c + 3;
    // Se o resultado ultrapassar o limite das letras, voltar ao início
    if (c > 'Z' && c < 'a') {
      c = c - 26;
    }
    if (c > 'z') {
      c = c - 26;
    }
  }
  return c;
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
                printf("O nome %s foi encontrado no arquivo.\n", aux);
                return 1;
            }
        }
    token = strtok (NULL, " ,\n");
    
// retorna o resultado
}
}


int login_PM (policial *lst){
    char arq[20] = "policiais.txt";
    policial *lista_policial = ler_arquivo(arq);
    printf("Digite o nome de guerra: ");
    char nome_de_guerra[50];
    scanf("%s", nome_de_guerra);

        if (confere(lista_policial, nome_de_guerra) == 1){
            printf("O nome %s foi encontrado no arquivo.\n", nome_de_guerra);
            printf ("Digite a senha: ");
            char senha[20];
            scanf("%s", senha);
           /* for (int i = 0; i < strlen(senha); i++) {
                senha[i] = criptografar(senha[i]);
            }*/
            printf("%s\n", senha);
            if (confere_senha(lista_policial,senha,nome_de_guerra) == 1){
                printf("A senha %s foi encontrada no arquivo.\n", senha);
                return 1;
            }
            else {
                printf("A senha %s não foi encontrada no arquivo.\n", senha);
                return 0;
            }
            return 1;
        }
        else {
            printf("O nome %s não foi encontrado no arquivo.\n", nome_de_guerra);
            return 0;
        }
    }
