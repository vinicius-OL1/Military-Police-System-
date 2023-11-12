#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void criar_oficio(char *tip_poli, char *descri, char *loca, char *polici,char*presos) {
  // Abrir o arquivo em modo de escrita
  FILE *arquivo = fopen("oficio_ocorrencia.txt", "w");
  // Verificar se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }
  // Escrever o conteúdo das variáveis no arquivo
  fprintf(arquivo, "%s%s%s%s%s\n", tip_poli, descri, loca, polici,presos);
  // Fechar o arquivo
  fclose(arquivo);
}
