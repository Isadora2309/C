
#include <stdio.h>

int buscaChave(int *listaBusca, int a, int n){
  int i;
  for (i=0; i< n; i++){
    if(listaBusca[i]==a){
      return 1;
    }
  }
  return 0;
}

int main(){
  int n = 8;
  int listaBusca[8] = {100,20,6,40,8,60,10,80};
  int a;
  printf("Busque um número de 1 a 10: %c", a);
  /* o scanf() verifica a entrada que corresponde aos especificadores de formato, ou seja, ele vai verificar se você realmente deu input em uma
  Integer */
  scanf("%d", &a);
  /* esse & é um operador de endereço. Ele fornece o enedereço ou o local
  na memória de uma variável, e aqui começa a Estrutura de Dados */
  if(buscaChave(listaBusca,n, a))
  printf("Elemento encontrado!");
  else
  printf("Elemento não encontrado :c");
}

