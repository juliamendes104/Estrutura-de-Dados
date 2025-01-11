//Amanda Mendes e Julia Mendes
#define MAX 50
//tamanho da lista
#define TRUE 1
#define FALSE 0
#define boolean int

//Tipo chave
typedef int tipo_chave; 

//Tipo registro
typedef struct
{
   char nome[30];
   int idade;
   char sexo;
} tipo_dado;

//Tipo elemento
typedef struct
{
   tipo_chave chave;
   tipo_dado info;
} tipo_elem;

//Tipo lista
typedef struct
{
   int nelem; //numero de elementos
   tipo_elem A[MAX+1];
} lista;

//Funcoes Exportadas
//Prototipos

boolean Vazia(lista *L);//Se vazia retorna true, se não retorna false

boolean Cheia(lista *L);//Se cheia retorna true, se não retorna false

void Definir(lista *L);//Cria uma lista

void Apagar(lista *L);//Apaga "logicamente" uma lista

boolean Inserir_posic(tipo_elem x, int p, lista *L);
/*insere elemento x na posicao p da lista
se inserir retorna true, se nao, nao tem posicao ou lista esta cheia, retorna false*/

boolean Buscar(tipo_chave x, lista *L, int *p);
//se x esta na posicao p retorna true, se não retorna false

void Remover_posic(int *p, lista *L);
//remove o elemento pela posicao p obtida atraves da busca

void Impr_elem(tipo_elem t);

void Imprimir(lista *L);//imprime os elementos ordenados

int Tamanho(lista *L);//Retorna o tamanho da lista

boolean Inserir_ord(tipo_elem x, lista *L);/*Insere novo elemento em ordem crescente. Devolve true (se sucesso), false (c.c.)*/

boolean Busca_bin(tipo_chave x, lista *L, int *p);
//retorna true se encontra o elemento x, se nao retorna false

boolean Remover_ch(tipo_chave x, lista *L);
//remocao pela chave, retorna true, se removeu, se nao retorna false
