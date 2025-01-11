//Amanda Mendes e Julia Mendes
#include <stdlib.h> //Para usar malloc, free, exit ...
#include <stdio.h>  //Para usar printf ,... 
#include "lista.h"  //Carrega o arquivo .h criado

#define MAX 50
//estimativa do tamanho maximo da lista
#define TRUE 1     //define tipo boleano, nao existe em C
#define FALSE 0
#define boolean int

//Implementacao: lista seq.

//Operacoes
//-------------------------------------------
boolean Vazia(lista *L)
{
   return (L->nelem == 0);
}

boolean Cheia(lista *L)
{
   return (L->nelem == MAX);
}

void Definir(lista *L)
{
   L = malloc(sizeof(lista));
   L->nelem = 0;
   L->A[0].chave = 0;
}

void Apagar(lista *L){
   L->nelem = 0;
}

boolean Inserir_posic(tipo_elem x, int p, lista *L)
{
   
   int q;

   if (Cheia(L) || p > L->nelem+1 || p < 1)
   {
     //Lista cheia ou posicao nao existe
      return FALSE;
   } 
   else 
   {
      for(q = L->nelem; q>=p; q--) //Copia vizinho p/ direita
	     L->A[q+1] = L->A[q];
      
	  L->A[p] = x;
      L->nelem++;
      
	  return TRUE; //Insercao feita com sucesso
   }
}

boolean Buscar(tipo_chave x, lista *L, int *p)
{   
   if (!Vazia(L))
   {
      int i = 1;
      while (i <= L->nelem)
         if (L->A[i].chave == x)
		 {
             *p = i;
             return TRUE;
         } 
		 else
             i++;
   }
   return FALSE; //Retorna false se nao encontrou
}

void Remover_posic(int *p, lista *L)
{
   
   int i;
   
   for (i = *p+1; i <= L->nelem; i++)
      L->A[i-1] = L->A[i];
   
   L->nelem--;
}

void Impr_elem(tipo_elem t)
{
   printf("\nChave: %d\n", t.chave);
   printf("Nome: %s\n", t.info.nome);
   printf("Idade: %d\n", t.info.idade);
   printf("Sexo: %c\n", t.info.sexo);
}

void Imprimir(lista *L)
{
   
   int i;
   
   if (!Vazia(L))
      for (i = 1; i <= L->nelem; i++)
         Impr_elem(L->A[i]);
}


int Tamanho(lista *L)
{
   
   return L->nelem;
}


//Implementacoes para listas ordenadas
//-------------------------------------------
boolean Inserir_ord(tipo_elem x, lista *L)
{
  int i, j, aux;
  int posicao;
  
  if(Cheia(L)){
    return FALSE;
  }
  else{
    for(i=1; i<=L->nelem; i++){//loop para percorrer a lista
      if(L->A[i].chave > x.chave){//se a chave do elemento da lista for maior que a chave do elemento que queremos inserir
        posicao = i;
        aux = Inserir_posic(x,posicao,L);//chama a funcao para inserir o elemento na posicao que encontramos em ordem crescente
        if(aux){
          return TRUE;
        }
      }
    }
    aux = Inserir_posic(x,L->nelem+1,L);//caso a chave do elemento que queremos inserir seja maior que todas as outras chaves, chamamos a funcao para inserir na ultima posicao
    if(aux){
      return TRUE;
    }
    return FALSE;
  }

}

boolean Busca_bin(tipo_chave x, lista *L, int *p)
{
   
   //Implementacao de busca binaria
   int inf = 1;
   int sup = L->nelem;
   int meio;
   
   while (!(sup < inf))
   {
      meio = (inf + sup)/2;
      if (L->A[meio].chave == x)
	  {
         *p = meio; //Sai da busca
          return TRUE;
      } 
	  else 
	  {
         if (L->A[meio].chave < x)
            inf = meio+1;
         else
            sup = meio-1;
      }
   }
   return FALSE;
}

boolean Remover_ch(tipo_chave x, lista *L)
{
   
   int *p = malloc(sizeof(int));
   boolean removeu = FALSE;
   
   if (Busca_bin(x, L, p)) //Procura via busca binaria
   {        
       Remover_posic(p, L);
       removeu = TRUE;
   }
   
   return removeu;
}
//-------------------------------------------
