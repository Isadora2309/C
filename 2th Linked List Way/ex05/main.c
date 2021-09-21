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

void inserirUltimo(int chave, int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->chave = chave;
   link->data = data;
   if(listaVazia()) {
      //O transforma no último link
      ultimoLink = link;
   } else {
      //O tranforma em um novo link antigo
      ultimoLink->proximo = link;     
      //Marca o último nó antigo como novo link anterior
      link->anterior = ultimoLink;
   }
   //Aponta o último para o 'novo último nó'
   ultimoLink = link;
}

struct node* deletarPrimeiro() {
   //Salvar referência para o primeiro Link
   struct node *tempLink = primeiroLink;
   //Se apenas um link for equivalente a nulo, este será igual ao último Link
   if(primeiroLink->proximo == NULL){
      ultimoLink = NULL;
   } else {
     //Se não, só passar para o próximo
      primeiroLink->proximo->anterior = NULL;
   }
   primeiroLink = primeiroLink->proximo;
   //Retorne e delete o último link
   return tempLink;
}

//Deletar link na última posição
struct node* deletarUltimo() {
   //Salvar a referência par ao próximo link
   struct node *tempLink = ultimoLink;
   //Se apenas um link for equivalente a nulo, este será igual ao último Link
   if(primeiroLink->proximo == NULL) {
      primeiroLink = NULL;
   } else {
      ultimoLink->anterior->proximo = NULL;
   }
   ultimoLink = ultimoLink->anterior;
   //Retorne o link deletado
   return tempLink;
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

   printf("\n Do primeiro elemento ao último elemento: ");  
   ordemCrescente();
	
   printf("\n");
   printf("\n Do último elemento ao primeiro elemento: "); 
   ordemDecrescente();

   printf("\n Após deletar o primeiro elemento: ");
   deletarPrimeiro();        
   ordemCrescente();

   printf("\n Após deletar o último elemento: ");  
   deletarUltimo();
   ordemCrescente();

   printf("\n Após inserir a chave 4: ");  
   inserirDepois(4,7, 13);
   ordemCrescente();

   printf("\n Após deletar a chave 4: ");  
   delete(4);
   ordemCrescente();
}