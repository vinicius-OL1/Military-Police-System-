/*colocar as funcoes*/
#define Max 30
struct policia{
	char nome[Max+1];
	policia *prox;
};

int login_viatura (policia *&lista);

int lerviatura(int num);

void inserir(char *nome, policia *&L);

void imprimir(policia *lst);