#include <stdio.h>

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

void ordemDeCrescente(){
  struct node *b, *c;
  int d;
  for(b = comeco; b -> proximo != NULL; b = b -> proximo){
    for(c = b -> proximo; c != NULL; c = c -> proximo){
      //Aqui que ocorre a mudança!
      if(c -> valor > b -> valor){
        d = c -> valor;
        c -> valor = b -> valor;
        b -> valor = d;
      }
    }
  }
}

int main(){
  criarLista();
  printf("\n A lista em ordem decrescente:\n");
  ordemDeCrescente();
  display();
  return 0;
}