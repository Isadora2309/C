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

bool inserirDepois(int chave, int novaChave, int data) {
   //Começar pelo primeiro link
   struct node *atualLink = primeiroLink; 
   //Checar se a lista está vazia
   if(primeiroLink == NULL) {
      return false;
   }
   //Navegar pela lista
   while(atualLink->chave != chave) {
      //Checar se é o último nó
      if(atualLink->proximo == NULL) {
         return false;
      } else {           
         //Passar para o próximo link
         atualLink = atualLink->proximo;
      }
   }
   //Criar um link
   struct node *novoLink = (struct node*) malloc(sizeof(struct node));
   novoLink->chave = novaChave;
   novoLink->data = data;
   if(atualLink == ultimoLink) {
      novoLink->proximo = NULL; 
      ultimoLink = novoLink; 
   } else {
      novoLink->proximo = atualLink->proximo;         
      atualLink->proximo->anterior = novoLink;
   }
   novoLink->anterior = atualLink; 
   atualLink->proximo = novoLink; 
   return true; 
}

int main() {
   inserirPrimeiro(1,10);
   inserirPrimeiro(2,20);
   inserirPrimeiro(3,30);
   inserirPrimeiro(4,1);
   inserirPrimeiro(5,40);
   inserirPrimeiro(6,56);

   printf("\n Após inserir a chave 4: ");  
   inserirDepois(4,7, 13);
   ordemCrescente();
   
}