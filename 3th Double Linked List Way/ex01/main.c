#include <stdio.h>
#include <stdlib.h>

struct node {
    int valor;
    struct node *proximo;
    struct node *anterior;
};

struct node *novoNo, *comeco = NULL, *a;

void criarLista() {
  int num = 1;
  while(num != 0 && num == 1){
    novoNo = (struct node*)malloc(sizeof(struct node));
    printf("Insira um elemento: \n");
    scanf("%d", &novoNo -> valor);
    novoNo -> proximo = NULL;
    novoNo -> anterior = NULL;

    if(comeco == NULL){
      comeco = novoNo;
    } else {
      a = comeco;
      while(a -> proximo != NULL){
        a = a -> proximo;
      }
      a-> proximo = novoNo;
    }
    printf("Você quer inserir um novo elemento? Digite '1' para 'sim' e '0' para 'não':\n");
    scanf("%d",&num);
  }
}

void display(){
  if(comeco == NULL){
    printf("Essa lista está vazia :v\n");
  } else {
    a = comeco;
    while(a != NULL){
      printf("%d | ",a -> valor);
      a = a -> proximo;
    }
  }
}

void procurar() {
  struct node *e;
  int item, i = 0, flag;
  e = comeco;
  if(comeco == NULL){
    printf("\nLista vazia! \n");
  } else {
    printf("\nInsira o elemente que deseja procurar: ");
    scanf("%d", &item);
    while(e != NULL){
      if(e -> valor == item){
        printf("\n Elemento encontrado! Ele está localizado em: %d", i+1);
        flag = 0;
        break;
      } else {
        // Essa bandeira significa que o item não foi encontrado
        flag = 1;
      }
      i++;
      e = e -> proximo;
    }
    if(flag == 1){
      printf("\n Elemento não encontrado :c \n");
    }
  }
}

int main(void) {
  criarLista();
  procurar();
}