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
    printf("Insira um valor: \n");
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
    printf("Você quer inserir um novo valor? Digite '1' para 'sim' e '0' para 'não':\n");
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

void deletarValor() {
  struct node *temp1;
  int num;
  printf("\nInsira o valor do elemento que deseja excluir: \n");
  scanf("%d",&num);

  if(comeco == NULL) {
    printf("\n Está vazio :v \n");
  } else {
    a = comeco;
    while(a -> valor != num) {
      temp1 = a;
      a = a -> proximo;
    }
    temp1 -> proximo = a -> proximo;
    a -> proximo = NULL;
    free(a);
    }
}

int main(){
     criarLista();
     display();
     deletarValor();
     printf("\n");
     display();
    return 0;
}