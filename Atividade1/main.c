//Amanda Mendes e Julia Mendes
//Atividade 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define N 3

int main(int argc, char *argv[]) {
  lista *L = malloc(sizeof(lista));
  tipo_elem elemento[N];
  int i;
  int teste = 2;
  int *p = malloc(sizeof(int));

  //Cria uma lista
  Definir(L);

  //Cria os elementos
  elemento[0].chave = 123;
  strcpy(elemento[0].info.nome,"Alexandre");
  elemento[0].info.idade = 49;
  elemento[0].info.sexo = 'M';
  
  elemento[1].chave = 23;
  strcpy(elemento[1].info.nome,"Caique");
  elemento[1].info.idade = 26;
  elemento[1].info.sexo = 'M';
  
  elemento[2].chave = 98;
  strcpy(elemento[2].info.nome,"Mariana");
  elemento[2].info.idade = 19;
  elemento[2].info.sexo = 'F';
  
  //Insere valores na lista
  for(i=0;i<N;i++){
    if(Inserir_ord(elemento[i],L)){
      printf("%s Inserido com sucesso\n", elemento[i].info.nome);
    }
  }

  printf("\nTamanho: %d\n", Tamanho(L));

  printf("\nImprimir lista ------------------------");
  Imprimir(L);
  printf("---------------------------------------");
  
  Remover_posic(&teste,L);
  printf("\nPosição %d Removido com sucesso\n", teste);

  if(Remover_ch(elemento[1].chave, L)){
    printf("\n%s Removido com sucesso.\n", elemento[1].info.nome);
  }

  printf("\nTamanho: %d\n", Tamanho(L));
  
  for(i=0;i<N;i++){
    if(Busca_bin(elemento[i].chave, L, p)){
      printf("\nBusca: %s encontrado.\n", elemento[i].info.nome);
    }
    else{
      printf("\nBusca: %s não encontrado.\n", elemento[i].info.nome);
    }
  }

  
  printf("\nImprimir lista ------------------------");
  Imprimir(L);
  printf("---------------------------------------");

  Apagar(L);

  if(Vazia(L)){
    printf("\nLista apagada\n");
  }
  
  
  return 0;
}
