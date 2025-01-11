#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define tam_fila 100

typedef struct{
int A[tam_fila];
int inicio, fim;
}Fila;

typedef struct{
int nNo;
int **adj;
}Grafo;

//cria o grafo
Grafo *Cria(){
  Grafo *g = malloc(sizeof(Grafo));
  g->nNo = 0;
  g->adj = NULL;
  return g;
}

//aloca o espaço para a matriz e inicializa todos os campos com 0
int **zeros(int lin, int col){
  int **g = malloc(lin * sizeof(int*));
  int i, j;
  for(i=0;i<lin;i++){
    g[i] = malloc(col * sizeof(int));
    for(j=0;j<col;j++){
      g[i][j] = 0;
    }
  }
  return g;
}

//imprime o grafo
void imprimir_grafo(Grafo *g){
  int i, j;
  printf("\nMatriz Adjacência\n\n");
  for(i=0;i<g->nNo;i++){
    for(j=0;j<g->nNo;j++){
      printf("%d ", g->adj[i][j]);
    }
    printf("\n");
  }
}

//insere o valor na posição fornecida pelos parâmetros
void setVal(int **matriz, int lin, int col, int valor){
  matriz[lin][col] = valor;
}

//lê o arquivo com o número de nós e os vértices adjacentes
void readGraph(Grafo *g, const char *filename){
  FILE *fp;
  int bsize = 20;
  int i, b, a, v;
  char buffer[bsize];

  fp = fopen(filename, "r");

  //Primeira linha do arquivo: indica o numero de nós
  fgets(buffer, bsize, fp);
  sscanf(buffer, "%d", &g->nNo);
  g->adj = zeros(g->nNo, g->nNo);

  //Percorre o arquivo
  while(!feof(fp)){
    fgets(buffer, bsize, fp);
    sscanf(buffer, "%d %d %d", &b, &a, &v);
    printf("%d %d %d\n", b, a, v);
    setVal(g->adj,b,a,v);
  }

  fclose(fp);
  return;
}

void definir(Fila *f){
  f->inicio = 0;
  f->fim = 0;
}

//retorna true se a lista estiver vazia
bool Vazia(Fila *f) {
	if (f->inicio == f->fim){
    return true;
  }
  return false;
}

//retorna true se a lista estiver cheia
bool Cheia(Fila *f) {
	if (f->inicio == ((f->fim + 1) % tam_fila)){
    return true;
  }
	return false;
  //os dois ponteiros diferem de uma posição
}

//insere o elemento na posição fim da lista
bool inserir(Fila *f, int elem){
  if(Cheia(f)){
    return false;
  }
  f->fim = ((f->fim + 1) % tam_fila);
  f->A[f->fim] = elem;
  return true;
}

//remove o elemento na posicao inicio da lista
bool remover(Fila *f, int *elem){
  if(Vazia(f)){
    return false;
  }
  f->inicio = (f->inicio + 1) % tam_fila;
  *elem = f->A[f->inicio];
  return true;
}

int main(void) {
  Grafo *g = Cria();
  readGraph(g,"digrafo.txt");
  imprimir_grafo(g);

  int dist[g->nNo];
	int i, j, u;
	Fila *f = malloc(sizeof(Fila));

  //fixa um nó
  printf("Digite o nó fixado u (0 a %d): ", g->nNo-1);
  scanf("%d", &u);
  //seta cada elemento do vetor dist como infinito 
  for(j=0;j<g->nNo;j++){
    dist[j] = INT_MAX;
  }
  
  dist[u] = 0;
  definir(f);
  inserir(f,u);

  //em cada iteração, um nó i é removido da fila e seus vizinhos j são examinados.
  while(!Vazia(f)){
    remover(f,&i);

    for(j=0;j<g->nNo;j++){
      //entra na condição se i tiver conexão com j e j ainda não foi checado ou tem um caminho maior
      if(g->adj[i][j] > 0 && dist[j] > dist[i] + g->adj[i][j]){
        dist[j] = dist[i] + g->adj[i][j];
        inserir(f,j);
      }
    }
  }

  printf("\nCaminhos mínimos:\n");
  for(i=0;i<g->nNo;i++){
    if(dist[i]==INT_MAX){
      printf("[%d] = Sem caminho\n", i);
    }
    else{
      printf("[%d] = %d\n", i, dist[i]);
    }
  }
  return 0;
}
