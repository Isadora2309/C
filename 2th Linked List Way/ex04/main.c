#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int chave;
	
   struct node *proximo;
   struct node *anterior;
};

struct node *primeiroLink = NULL;
 
struct node *ultimoLink = NULL;

struct node *atualLink = NULL;

bool listaVazia() {
   return primeiroLink == NULL;
}

int comprimento() {
   int comprimento = 0;
   struct node *atualLink;
   for(atualLink = primeiroLink; atualLink != NULL; atualLink = atualLink->proximo){
      comprimento++;
   }
   return comprimento;
}

void ordemDecrescente() {
   struct node *ptr = primeiroLink;
   printf("\n[ ");
   while(ptr != NULL) {        
      printf("(%d,%d) ",ptr->chave,ptr->data);
      ptr = ptr->proximo;
   }
   printf(" ]");
}

void inserirPrimeiro(int chave, int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->chave = chave;
   link->data = data;
   if(listaVazia()) {
      //O transforma no último link
      ultimoLink = link;
   } else {
      //Atualiza o primeiro link anterior
      primeiroLink->anterior = link;
   }
   //Aponta-o para o primeiro link antigo
   link->proximo = primeiroLink;
   //Aponta para o primeiro 'novo primeiro link'
   primeiroLink = link;
}

int main() {
   inserirPrimeiro(1,15);
   inserirPrimeiro(2,25);
   inserirPrimeiro(3,35);
   inserirPrimeiro(4,10);
   inserirPrimeiro(5,65);
   inserirPrimeiro(6,75);;
	
   printf("\n");
   printf("\n Do último elemento ao primeiro elemento: "); 
   ordemDecrescente();

}