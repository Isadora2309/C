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

void ordemCrescente() {
   struct node *ptr = ultimoLink;
   printf("\n[ ");
   while(ptr != NULL) {    
      printf("(%d,%d) ",ptr->chave,ptr->data);
      ptr = ptr ->anterior;
   }
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

struct node* delete(int chave) {
   //Começar pelo primeiro link
   struct node* atualLink = primeiroLink;
   struct node* anterior = NULL;
   //Analisar se a lista está vazia
   if(primeiroLink == NULL) {
      return NULL;
   }
   //Navegar pela lista
   while(atualLink->chave != chave) {
      //Analisar se for o último nó
      if(atualLink->proximo == NULL) {
         return NULL;
      } else {
         //Referenciar para o link atual
         anterior = atualLink;
         //Mover para o próximo link
         atualLink = atualLink->proximo;             
      }
   }
   //Encontrada a correpondente chave, atualizar o link
   if(atualLink == primeiroLink) {
      //Mudar o primeiro ponteiro para o próximo link
      primeiroLink = primeiroLink->proximo;
   } else {
      //Ignorar o link atual
      atualLink->anterior->proximo = atualLink->proximo;
   }    
   if(atualLink == ultimoLink) {
      ultimoLink = atualLink->anterior;
   } else {
      atualLink->proximo->anterior = atualLink->anterior;
   }
   return atualLink;
}

int main() {
   inserirPrimeiro(1,10);
   inserirPrimeiro(2,20);
   inserirPrimeiro(3,30);
   inserirPrimeiro(4,1);
   inserirPrimeiro(5,40);
   inserirPrimeiro(6,56);

   printf("\n Após deletar a chave 4: ");  
   delete(4);
   ordemCrescente();
}