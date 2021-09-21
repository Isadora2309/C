#include <stdio.h>
#define SIZE 100
/* outro facilitador de vida já que a programação em C não nos dá a liberdade de delimitar o tamanho de uma Array durante o programa, MAS, com esse 'truque' podemos fazer o usuário pensar que pode limitar a Array, mas apenas, dentro d eum tamanho já delimitado */

int main(){

  int i, tamanho, posicao;
  int lista[SIZE];

  printf("\n Qual será o tamanho da lista? %c", tamanho);
  scanf("%d", &tamanho);
  
  printf("\n Quais elementos terão dentro dele? ");
  for(i = 0; i < tamanho; i++){
    /* aqui ele vai analisar todos os inputs, alocar memória para cada dado e formar a lista dentro do tamanho definido */
    scanf("%d", &lista[i]);
  }

  printf("\n Informe a posição do elemento para o excluir da lista: ");
  scanf("%d", &posicao);

  /* Mas como saber que o input do usuário corresponde a uma posição válida dentro da lista? Simples, utilizando das condicionais ao comparar o tamanho da lista. Em C o conjunto dos símbolos && corresponde a "e", e || a "ou" */
  if (posicao < 0 || posicao > tamanho){
    printf("\n Posição inválida! Tentende novo com um número entre 1 e %d", tamanho);
  } else {
    /* Agora vamos fazer o caso para o qual o usuário dá uma entrada válida */
    for(i = posicao-1; i < tamanho-1; i++){
      /* Aqui estamos falando que nosso elemento de comparação será a posição menos 1, uma vez que a indexação de um Array começa do zero. Isso será comparado ao tamanho -1 (pelo mesmo motivo) da nossa Array */
      lista[i] = lista[i+1];
    }
    /* Um decremento básico para exclui o elemento cuja posição foi nos dada */
    tamanho--;
    /*Para confirmarmos que a operação ocorreu basta printar */
    printf("\n Sua lista ficou assim: ");
    for(i = 0; i<tamanho; i++){
      printf("%d", lista[i]);
    }
  }
  return 0;
}