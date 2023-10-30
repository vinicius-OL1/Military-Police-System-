/*colocar as funcoes*/
#define Max 100
#define MAX_NAME_LENGTH 50
#define MAX_NAMES 10
struct policia{
    int n_v;
    char nome[Max+1];
    char estado[Max+1];
	policia *prox;
};

int login_viatura (policia *&lista,int codi);

int lerviatura(int num);

void inserir(int n_v,char *nome, policia *&L);

void imprimir(policia *lst);

int viatura_em_uso(policia *lista, int codi);

int busca_nome(policia *lista, char *nome);