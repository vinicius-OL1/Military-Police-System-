/*colocar as funcoes*/
#define Max 100
#define MAX_NAME_LENGTH 50
#define MAX_NAMES 10
struct policia{
    int n_v;
    char nome[Max+1];
    char estado[Max+1];
    int tip;
	policia *prox;
};
struct policial {
    char nome[50];
    char cpf[50];
    char nome_de_guerra[10];
    char cidade[20];
    int idade;
    char patente[20];
    char senha[20];
    policial *prox; 
} ;
struct caso_esp{
    char descricao[100];
    char local[50];
    caso_esp *prox;
};
struct caso_norm{
    char descricao[100];
    char local[50];
    caso_norm *prox;
};

int criar_viatura (policial *&lst,policia *&lista,int codi);

int lerviatura(int num);

void inserir(int n_v,char *nome, policia *&L, int opt);

void imprimir(policia *lst);

int viatura_em_uso(policia *lst,caso_norm *f, caso_esp *g);

int busca_nome(int qpm,policial *lista, char *nome);

int criar_chamada(policial *&lst,caso_norm *&lista_norm_i,caso_norm *&lista_norm_f, caso_esp *&lista_esp_i, caso_esp *&lista_esp_f);

void imprimir_lista(caso_norm *L);

void desalocarF(caso_norm*&L);

void alt_estado(policia *l, caso_norm *f);

int login_PM (policial *lst);

policial *criar_policial(char *nome, char *cpf, char *nome_de_guerra, char *cidade, int idade, char *patente, char *senha);

policial *ler_arquivo(char *nome_arquivo);

int confere(policial *lista, char *nome);

int confere_senha(policial *lista, char *nome,char *senha);