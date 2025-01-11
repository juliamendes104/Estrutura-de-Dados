//Amanda Mendes e Júlia Mendes
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void) {
  no *root = NULL;
  root = busca_insere(root, 2);
  root = busca_insere(root, 1);
  root = busca_insere(root, 7);
  root = busca_insere(root, 4);
  root = busca_insere(root, 5);
  root = busca_insere(root, 3);
  root = busca_insere(root, 8);
  inOrder(root);
  Imprime_arvore(root,1,'/');

  root = remove_avl(root, 2);
  root = remove_avl(root, 1);
  root = remove_avl(root, 3);

  Imprime_arvore(root,1,'/');
}
