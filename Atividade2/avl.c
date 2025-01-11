//Amanda Mendes e Júlia Mendes
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

no* criar_no(int c, no *esq, no *dir){
  no* raiz = malloc(sizeof(no));
  raiz->info = c;
  raiz->esq = esq;
  raiz->dir = dir;
  raiz->FB = 0;
  return raiz;
}

int altura(no *t){
  if(t==NULL){
    return 0;
  }
  int altE = altura(t->esq);
  int altD = altura(t->dir);
  if(altE>altD){
    return (altE+1);
  }
  return (altD+1);
}

no *busca(no *raiz, int elemento){
  if(raiz == NULL){
    return NULL;
  }
  if(raiz->info == elemento){
    return raiz;
  }
  else if(raiz->info > elemento){
    return busca(raiz->esq,elemento);
  }
  else{
    return busca(raiz->dir,elemento);
  }
}

no* busca_insere(no *t, int elemento){
  if(t == NULL){
    printf("Inserindo valor %d na raiz\n", elemento);
    t = criar_no(elemento, NULL, NULL);
    return t;
  }

  if(elemento < t->info){
    t->esq = busca_insere(t->esq, elemento);
  } else if(elemento > t->info){
    t->dir = busca_insere(t->dir, elemento);
  }
  else{
    return t;
  }

  //após inserir, calcula o FB de cada nó
  t->FB = fator_balanceamento(t);

  //se o nó estiver desbalanceado, verifica qual tipo de rotação realizará
  if(t->FB > 1){
    if(t->dir->FB < 0){
      printf("Realizando rotação dupla Esquerda no nó %d\n", t->info);
      t = rotacao_duplaEsq(t);
    }
    else{
      printf("Realizando rotação Esquerda no nó %d\n", t->info);
      t = rotacao_esquerda(t);
    }
  } else if(t->FB < -1){
    if(t->esq->FB > 0){
      printf("Realizando rotação dupla Direita no nó %d\n", t->info);
      t = rotacao_duplaDir(t);
    }
    else{
      printf("Realizando rotação Direita no nó %d\n", t->info);
      t = rotacao_direita(t);
    }
  }

  return t;
}

//função que retorna o calculo do FB
int fator_balanceamento(no *t){
  return (altura(t->dir) - altura(t->esq));
}

void inOrder(no *t){
  if(t==NULL){
    return;
  }
  inOrder(t->esq);
  printf("%d\n",t->info);
  inOrder(t->dir);
}

no* rotacao_esquerda(no *p){
  no *q = p->dir;
  p->dir = q->esq;
  q->esq = p;
  p->FB = fator_balanceamento(p);
  q->FB = fator_balanceamento(q);
  return q;
}

no* rotacao_direita(no* p){
  no *q = p->esq;
  p->esq = q->dir;
  q->dir = p;
  p->FB = fator_balanceamento(p);
  q->FB = fator_balanceamento(q);
  return q;
}

no* rotacao_duplaEsq(no* p){
  p-> dir = rotacao_direita(p->dir);
  no *raiz = rotacao_esquerda(p);
  return raiz;
}

no* rotacao_duplaDir(no* p){
  p->esq = rotacao_esquerda(p->esq);
  no *raiz = rotacao_direita(p);
  return raiz;
}

void Imprime_arvore(no* raiz, int nivel, char tipo_conexao){
  int i;
	if (raiz != NULL) {
    Imprime_arvore(raiz->dir, nivel + 1, '/');
        
	for (i = 1; i < nivel; i++) 
		printf("   ");
        
	printf("%c-%d\n", tipo_conexao, raiz->info);
	Imprime_arvore(raiz->esq, nivel + 1, '\\');
  }
}

no* remove_avl(no *t, int elemento){
  no* q;
  if(t==NULL){
    return t;
  }
  if(t->info > elemento){
    t->esq = remove_avl(t->esq,elemento);
  }
  else if(t->info < elemento){
    t->dir = remove_avl(t->dir,elemento);
  }
    //se o nó for folha, remove ele, ou se só tem um filho, substitui por ele
  else{
    if(t->esq==NULL){
      q = t;
      t = t->dir;
      free(q);
    }
    else if(t->dir==NULL){
      q = t;
      t = t->esq;
      free(q);
    }
    else{
      //se remover um nó que tem dois filhos, substitui pelo menor filho à sua direita
      q = substituir_menor_direita(t->dir);
      t->info = q->info;
      t->dir = remove_avl(t->dir, q->info);
    }
  }
  if(t==NULL){
    return t;
  }

  //calcula o FB de cada nó após a remoção
  t->FB = fator_balanceamento(t);

  //se o nó estiver desbalanceado, faz a devida rotação
  if(t->FB > 1){
    if(t->dir->FB < 0){
      printf("Realizando rotação dupla Esquerda no nó %d\n", t->info);
      t = rotacao_duplaEsq(t);
    }
    else{
      printf("Realizando rotação Esquerda no nó %d\n", t->info);
      t = rotacao_esquerda(t);
    }
  } else if(t->FB < -1){
    if(t->esq->FB > 0){
      printf("Realizando rotação dupla Direita no nó %d\n", t->info);
      t = rotacao_duplaDir(t);
    }
    else{
      printf("Realizando rotação Direita no nó %d\n", t->info);
      t = rotacao_direita(t);
    }
  }
  return t;
}

//função que retorna o menor filho à direita de um nó
no* substituir_menor_direita(no *p){
  no *q = p;
  while(q->esq!=NULL){
    q = q->esq;
  }
  return q;
}
