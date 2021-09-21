#include <stdio.h>

int main(void) {
  int tamanho, i, a, b;
  int array[20];
  printf("Qual será o tamanho da nossa lista?\n");
  scanf("%d", &tamanho);
  printf("Insira %d os números inteiros da nossa lista: \n", tamanho);
  /* Até aqui nada mudou dos primeiros exercícios anteriores, executaremos um laço de repetição para coletar os números da lista até o limite informado anteriormente */
  for (i = 0; i < tamanho; i++)
  scanf("%d", &array[i]);
  /* Agora começa a partediferente! Neste laço de repetição restrito ao tamanho decrescido de 1 (porque na indexação de uma lista o primeiro elemento corresponde a`posição zero), iremos dar inicío a outro laço de repetição */
  for (i = 0 ; i < tamanho - 1; i++){
  /* No segundo laço de repetição, utilizares outro valor para comparação em cada elemento dentro do tamanho da lista, ele irá um por um comparar os elementos encontrando assim o menor deles */
    for (a = 0 ; a < tamanho - i - 1; a++){
    /* Para que a ordenação se estabeleça em ordem crescente (do menor para o mair) é necessária uma condição, onde se o elemento 'a' de valor inicial zero for maior que qualquer elemento em uma posição maior que a do início, então ele será jogado para a direita */
      if (array[a] > array[a+1]){
        b = array[a];
        array[a] = array[a+1];
        array[a+1] = b;
      }
    }
  }

  printf("A lista em ordem crescente é:\n");
  for (i = 0; i < tamanho; i++)
  printf("%d\n", array[i]);
  return 0;
}