#include <stdio.h>
#include <stdlib.h>

// FUNÇÕES
// GLOBAIS---------------------------------------------------------------------

// Criando a estrutura do no
struct NoOrdem {
  int valor;
  struct NoOrdem *esquerda;
  struct NoOrdem *direita;
};

//  Função para criar um novo nó da árvore binária ordenada
struct NoOrdem *inserir(struct NoOrdem *raizO, int x) {
  if (raizO == NULL) {
    raizO = malloc(sizeof(struct NoOrdem));
    raizO->valor = x;
    raizO->esquerda = raizO->direita = NULL;
  } else if (x < raizO->valor)
    raizO->esquerda = inserir(raizO->esquerda, x);
  else if (x > raizO->valor)
    raizO->direita = inserir(raizO->direita, x);
  return raizO;
}

struct NoOrdem *arvore() {
  struct NoOrdem *raizO;

  raizO = NULL;
  raizO = inserir(raizO, 10);
  raizO = inserir(raizO, 5);
  raizO = inserir(raizO, 15);
  raizO = inserir(raizO, 3);
  raizO = inserir(raizO, 7);

  return raizO;
}

// Fazer a identação seguindo os níveis
void imprimirIdentacao(int numeroTabs) {
  for (int i = 0; i < numeroTabs; i++) {
    printf("\t");
  }
}

// Imprimir os valores da árvore, seguindo pré-ordem (raíz, esquerda, direita)
void imprimirNos(struct NoOrdem *raizO, int nivel) {
  if (raizO == NULL) {
    imprimirIdentacao(nivel);
    printf("vazio\n");
    return;
  }
  imprimirIdentacao(nivel);
  printf("valor = %d\n", raizO->valor);
  imprimirIdentacao(nivel);
  printf("esquerda\n");
  imprimirNos(raizO->esquerda, nivel + 1);
  imprimirIdentacao(nivel);
  printf("direita\n");
  imprimirNos(raizO->direita, nivel + 1);
  imprimirIdentacao(nivel);
  printf("fim\n");
}

// Imprime a árvore toda
void imprimirArvore(struct NoOrdem *raizO) {
  printf("Árvore:\n");
  imprimirNos(raizO, 0);
  printf("\n");
}

// LETRA A---------------------------------------------------------------------

// Função para contar o número de nós em uma árvore
int contagem_Nos(struct NoOrdem *raizO) {
  if (raizO == NULL)
    return 0;
  else
    return 1 + contagem_Nos(raizO->esquerda) + contagem_Nos(raizO->direita);
}

int letraA() {
  struct NoOrdem *raizO;

  raizO = arvore();

  // Chamando a função para contar os nós
  int contagem_nos = contagem_Nos(raizO);

  // Retornando o resultado para o usuário
  printf("Numero de nos na arvore: %d\n", contagem_nos);

  return 0;
}

// LETRA
// B----------------------------------------------------------------------------

// declaração
int contagem = 0;

// Função para contar o número de nós não folhas em uma árvore
int nosNaoFolhas(struct NoOrdem *raizO) {

  if (raizO != NULL) {
    nosNaoFolhas(raizO->esquerda);
    nosNaoFolhas(raizO->direita);

    if ((raizO->esquerda != NULL) || (raizO->direita != NULL)) {
      contagem++;
    }
  }
  return contagem;
}

int letraB() {
  // Gerando a árvore
  struct NoOrdem *raizO;
  raizO = arvore();

  // Chamando a função para contar os nós não folhas
  printf("Numero de nós não folhas na arvore: %d\n", nosNaoFolhas(raizO));

  return 0;
}

// LETRA
// C----------------------------------------------------------------------------

// Localizar o nó pedido pelo valor
struct NoOrdem *localizar(struct NoOrdem *raizO, int x) {
  if (raizO == NULL)
    printf("Valor não encontrado\n");
  else if (x < raizO->valor)
    return localizar(raizO->esquerda, x);
  else if (x > raizO->valor)
    return localizar(raizO->direita, x);
  else
    printf("O valor %d foi encontrado\n", raizO->valor);
  return raizO;
}

// Função que printa todos os nós em ORDEM, utilizar para fazer as letras a e b:

int letraC() {
  struct NoOrdem *raizO;

  raizO = arvore();
  printf("Escolha um valor para localizar: ");
  int x;
  scanf("%d", &x);
  localizar(raizO, x);

  return 0;
}

// LETRA
// D----------------------------------------------------------------------------

// Localiza o menor valor na subárvore
struct NoOrdem *noMin(struct NoOrdem *raizO) {
  if (raizO == NULL)
    return NULL;
  else if (raizO->esquerda == NULL)
    return raizO;
  else
    return noMin(raizO->esquerda);
}

// Exclui nó
struct NoOrdem *excluir(struct NoOrdem *raizO, int x) {
  struct NoOrdem *temp;
  if (raizO == NULL)
    printf("Valor não encontrado\n");
  else if (x < raizO->valor)
    raizO->esquerda = excluir(raizO->esquerda, x);
  else if (x > raizO->valor)
    raizO->direita = excluir(raizO->direita, x);
  else if (raizO->esquerda && raizO->direita) {
    temp = noMin(raizO->direita);
    raizO->valor = temp->valor;
    raizO->direita = excluir(raizO->direita, raizO->valor);
  } else {
    temp = raizO;
    if (raizO->esquerda == NULL)
      raizO = raizO->direita;
    else if (raizO->direita == NULL)
      raizO = raizO->esquerda;
    free(temp);
  }
  return raizO;
}

int letraD() {
  struct NoOrdem *raizO;

  raizO = arvore();

  printf("Escolha um valor para excluir: ");
  int x;
  scanf("%d", &x);
  excluir(raizO, x);

  imprimirArvore(raizO);
  printf("\n");
  return 0;
}

int main() {
  char letra[0];
  int continuar = 1;
  struct NoOrdem *raizO;
  raizO = arvore();
  imprimirArvore(raizO);
  while (continuar == 1) {
    printf(" a) Contar o número de nós de uma árvore:\n b) Contar o número de "
           "nós de NÃO folhas uma árvore:\n c) Localizar um valor em uma "
           "árvore binária ordenada:\n d) Excluir um valor em uma árvore "
           "binária ordenada. A mesma deve continuar ordenada após remoção.\n");
    printf("Insira a letra da questão que você deseja\n");
    scanf("%s", letra);
    printf("A letra escolhida foi %s\n", letra);

    if (letra[0] == 'a' || letra[0] == 'A') {
      letraA();
      printf("Digite 1 para continuar ou 0 para sair\n");
      scanf("%i", &continuar);
    }

    else if (letra[0] == 'b' || letra[0] == 'B') {
      letraB();
      printf("Digite 1 para continuar ou 0 para sair\n");
      scanf("%i", &continuar);
    }

    else if (letra[0] == 'c' || letra[0] == 'C') {
      letraC();
      printf("Digite 1 para continuar ou 0 para sair\n");
      scanf("%i", &continuar);
    }

    else if (letra[0] == 'd' || letra[0] == 'D') {
      letraD();
      printf("Digite 1 para continuar ou 0 para sair\n");
      scanf("%i", &continuar);
    }

    else {
      printf("Letra inválida\n");
    }
  }
  return 0;
}
