//Amanda Mendes e Júlia Mendes
typedef struct no{
int info;
struct no *esq;
struct no *dir;
int FB;
}no;

no* criar_no(int c, no *esq, no *dir);

int altura(no *t);

no* busca_insere(no *t, int elemento);

void inOrder(no *t);

no* rotacao_esquerda(no *p);

no* rotacao_direita(no* p);

no* rotacao_duplaEsq(no* p);

no* rotacao_duplaDir(no* p);

void Imprime_arvore(no* raiz, int nivel, char tipo_conexao);

int fator_balanceamento(no* t);

no *busca(no *raiz, int elemento);

no* remove_avl(no *t,int elemento);

no* substituir_menor_direita(no *p);
