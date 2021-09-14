<h1>** Lista Duplamente Ligada** </h1>
<h2> O que é? </h2>
<p> Ou *Doubly Linked List* é uma variação de lista ligada ("linkada") na qual a navegação é possível de ambas as maneiras, tanto para frente quanto para trás facilmente em comparação com a *Single Linked List*. 

Consiste em um nó (*node*) que tem um ponteiro apontando para o nó anterior (*previous node*) e o próximo nó (*next node*) aponta para o nó anterior na matriz definida. A lista duplamente ligada é considerada uma das estruturas de dados complexas de uma forma que funciona com muitos ponteiros e gerenciamento de endereços dentro da lista implementada.

⚠️*** Ele não contém um ponteiro nulo na lista definida*** ⚠️</p>
<h2> Sintaxe </h2>
<p> Não tem nada muito pomposo, mas, é preciso realizar algumas etapas iniciais quanto a criação da estrutura de dados e, uma vez criada, muitas operações podem ser realizadas nessa lista vinculada de acordo com o que é representado abaixo:
</p>

    struct node {
       int data;
       int chave;
    	
       struct node *proximo;
       struct node *anterior;
    };

<h2> Organizando os ponteiros </h2>
<p> Este ponteiro irá sempre apontar para o primeiro link </p>

    struct node *primeiroLink = NULL;

<p> Este ponteiro irá sempre apontar para o ultimo link </p>

    struct node *ultimoLink = NULL;

<p> E este ponteiro irá sempre apontar para o link atual </p>

    struct node *atualLink = NULL;

<h2> O que é "bool"? </h2>
<p> Em C, é um tipo de dado, que pode ser utilizado quando implementado o cabeçalho `stdbool.h`. Ele evita a quebra de código quando utilizado como um identificador. 

No nossocódigo ele aparece quando vamos instaurar um booleano para verificar se a lista está vazia.</p>

    bool listaVazia() {
       return primeiroLink == NULL;
    }

<h2> O que é essa setinha? </h2>
<p> É equivalente a `(*p).a`. Explicando melhor, em C, um ponteiro pode muitas vezes apontar para uma instância de uma estrutura, já que `p` é um ponteiro (ou uma entidade semelhante a um ponteiro, como um iterador). Essa setinha `->` fora apenas adicionada para economizar tempo para esta operação de desreferência e acesso de ponteiro. 

No nosso código, ela aparece na função que construímos para analisar o comprimento da lista, sempre partindo do princípio de que seu comprimento inicial é equivalente a zero.</p>

    int comprimento() {
       int comprimento = 0;
       struct node *atualLink;
       for(atualLink = primeiroLink; atualLink != NULL; atualLink = atualLink->proximo){
          comprimento++;
       }
       return comprimento;
    }

<h2> Do primeiro elemento ao último elemento </h2>
<p> Por menos intuitivo que seja, para trocarmos a ordem de uma lista, primeiro temos que organizá-la em forma crescente para depois torná-la decrescente. </p>

        void ordemCrescente() {
       struct node *ptr = ultimoLink;
       printf("\n[ ");
       while(ptr != NULL) {    
          printf("(%d,%d) ",ptr->chave,ptr->data);
          ptr = ptr ->anterior;
       }
    }

<p> Esse `ptr` é apenas um parâmetro de comparação entre os elementos da lista, que quando finalizado a operação passa para o próximo elemento, reordenando. </p>

<h2> Do último elemento ao primeiro elemento </h2>
<p> Agora, vamos inverter a lista, deixando-a em ordem decrescente! </p>

	    void ordemDecrescente() {
       struct node *ptr = primeiroLink;
       printf("\n[ ");
       while(ptr != NULL) {        
          printf("(%d,%d) ",ptr->chave,ptr->data);
          ptr = ptr->proximo;
       }
       printf(" ]");
    }

<p> Percebam que a única mudança na estrutura é na linha 6, em que mudamos o parâmetro para ser comparado do próximo para o elemento anterior. </p>

<h2> Inserir Link no Primeiro Lugar </h2>
<p> Vamos criar um link, em que a expressão `malloc` vai alocar uma porção da memória para receber a nossa lista, após criarmos, vamos atualizar o link com a posição de cada elemento novo que criarmos. </p>

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

<p> Ficou um pouco repetitivo, mas deu para entender (espero eu). </p>

<h2>  Inserir link no último local </h2>
<p> Na mesma lógica do anterior, temos: </p>

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

<p>  Percebam que a diferença é evidente a partir da linha 9, onde não ocorre a atualização do link como no anterior, mas sim a transformação dele em um link antigo, marcando o nó antigo como um 'novo lin anterior'. </p>

<h2> Deletar primeiro item </h2>
<p> Aqui iremos salvar a refere^ncia para o primeiro link, e analisar se ele for equivalente a nulo, corresponderá ao último link. Caso contrário, passara para o próximo elemento.</p>

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

<p> Por fim, ele retorna deletando o último link - já que é nulo. </p>
<h2>  Deletar último link </h2>
<p> Aqui iremos salvar a referência para o próximo link e avaliar, se caso ele for nulo, será igual ao último link, caso contrário, passará para o **ANTERIOR**. </p>

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

<h2>  Deletar link, dada a chave </h2>
<p> Aqui iremos começar pelo primeiro link da lista, analisar se ela está vazia, navegar por ela, caso não estiver e então analisar se é o último nó. Se não for nulo, iremos referenciá-la para o link atual e passar para o próximo. </p>

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

<p> Então, iremos procurar pela chave. Quando encontrada o link irá se atualizar e mudar o ponteiro para o próximo, ignorando o link atual e apontando para o último link. </p>

       //Encontrada a correpondente chave, atualizar o link
       if(atualLink == primeiroLink) {
          //Mudar o primeiro ponteiro para o próximo link
          primeiroLink = primeiroLink->proximo;
       } else {
          //Ignorar o link atual
          atualLink->anterior->proximo = atualLink->proximo;
       }    
       if(atualLink == ultimoLink) {
          //Mudar o ponteiro para o último link
          ultimoLink = atualLink->anterior;
       } else {
          atualLink->proximo->anterior = atualLink->anterior;
       }
       return atualLink;
    }

<p> Por fim, retorna-se o link atual. </p>
<h2> Inserir Depois </h2>
<p> Prometo que estamos acabando! Mas, novamente, vamos começar pelo primeiro link e checar se a lista está vazia. Se ela não estiver vamos navegar por ela e então checar se o link atual está no último nó.</p>

    bool inserirDepois(int chave, int novaChave, int data) {
       //Começar pelo primeiro link
       struct node *atualLink = primeiroLink; 
       //Checar se a lista está vazia
       if(primeiroLink == NULL) {
          return false;
       }
       //Navegar pela lista
       while(atualLink->chave != chave) {

<p> Se ele estiver, retornaremos ao nosso dado boolean, falso. Caso contrário, iremos para o próximo link.</p>

          //Checar se é o último nó
          if(atualLink->proximo == NULL) {
             return false;
          } else {           
             //Passar para o próximo link
             atualLink = atualLink->proximo;
          }
       }

<p> Feito isso, vamos criar um novo link e checar se o link atual corresponde ao último link, se sim, o próximo será nulo, e o ultimo será o novo link. </p>

       //Criar um link
       struct node *novoLink = (struct node*) malloc(sizeof(struct node));
       novoLink->chave = novaChave;
       novoLink->data = data;
       if(atualLink == ultimoLink) {
          novoLink->proximo = NULL; 
          ultimoLink = novoLink; 

<p> Caso contrário: </p>

       } else {
          novoLink->proximo = atualLink->proximo;         
          atualLink->proximo->anterior = novoLink;
       }
       novoLink->anterior = atualLink; 
       atualLink->proximo = novoLink; 
       return true; 
    }

<h2> 🥳 FIM! 🎉 </h2>
<p> Vamos definir alguns números para nossa lista e chamar cada uma das funções:</p>

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

<p> Output </p>

![](https://i.pinimg.com/564x/dc/44/4a/dc444aa2d01d773879036ae1249445f3.jpg)
