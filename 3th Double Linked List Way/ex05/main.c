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
    printf("\nInsira um elemento: ");
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
    printf("\nVocê quer inserir um novo elemento? Digite '1' para 'sim' e '0' para 'não': ");
    scanf("%d",&num);
  }
}

void display(){
  if(comeco == NULL){
    printf("\n Essa lista está vazia :v\n");
  } else {
    a = comeco;
    while(a != NULL){
      printf(" %d | ",a -> valor);
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
    printf("\n Elemento deletado! \n");
    }
}

void ordemCrescente(){
  struct node *b, *c;
  int d;
  for(b = comeco; b -> proximo != NULL; b = b -> proximo){
    for(c = b -> proximo; c != NULL; c = c -> proximo){
      if(b -> valor > c -> valor){
        d = c -> valor;
        c -> valor = b -> valor;
        b -> valor = d;
      }
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

int main (){
  int escolha =0;
  while(escolha != 5){
    printf("\n 1. Procurar um elemento dado seu valor; \n 2. Deletar um elmento dado seu valor;\n 3. Colocar em ordem crescente os elementos;\n 4. Colocar em ordem decrescente os elementos;\n 5. Bye-Bye;\n");
    printf("\nO que deseja fazer? ");
    scanf("%d",&escolha);
    switch(escolha){
      case 1:
      criarLista();
      display();
      procurar();
      break;
      case 2:
      criarLista();
      display();
      deletarValor();
      break;
      case 3:
      criarLista();
      display();
      ordemCrescente();
      break;
      case 4:
      criarLista();
      display();
      ordemDeCrescente();
      break;
      case 5:
      exit(0);
      break;
      default:
      printf("\nO que deseja fazer? ");
    }
  }
}