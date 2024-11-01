#include <stdio.h>
#include <stdlib.h>

struct nodeTree {
  int data;
  struct nodeTree *left;
  struct nodeTree *right;
};

typedef struct nodeTree Tree;  // renomeando

// metodos para implementar
void printInOrder (Tree* a);
Tree* insert(Tree* a, int data);
Tree* removeElement(Tree* r, int data);

// Ordenando
void printInOrder (Tree* a) {
  if (a != NULL) {
    printInOrder(a->left);  // recursão
    printf("[%d] ", a->data);
    printInOrder(a->right);  // recursão
  }
}

// Inserindo
Tree* insert(Tree* a, int data) {
  if (a == NULL) {     // Se for nulo, não tem elemento
    a = (Tree*)malloc(sizeof(Tree));   // aloca um espaço para um novo nó
    a->data = data;  // atribui o valor como nó raiz da árvore
    a->left = a->right = NULL; //define o nó da esquerda e direita como nulo
  } else if (data < a->data) {  // se a árvore não for vazia e o valor for menor que o nó pai
    a->left = insert(a->left, data); // açao recursiva para que insira o valor no subárvore da esquerda
  } else if (data > a->data) {   // se for maior que o nó pai 
    a->right = insert(a->right, data); // ação recursiva o nó é adicionado na subárvore da direita
  }

  return a;
}

// Removendo
Tree* removeElement(Tree* r, int data) {
  if (r == NULL) {  
    return NULL;   // árvore não existindo, retorna nulo
  } else if (data < r->data) {  // se o valor for menor que o valor do nó corrente
    r->left = removeElement(r->left, data);   // exclui o nó da esquerda
  } else if (data > r->data) { // se o valor for maior que o valor do nó corrente
    r->right = removeElement(r->right, data); // exclui o nó da direita
  } else {
    if (r->left == NULL && r->right == NULL) { // elemento a ser removido não tem filhos
      free(r); // libera o espaço do nó
      r = NULL; // remove o nó
    } else if (r->left == NULL) {  // quando tiver apenas filho na direita
      Tree* aux = r;  
      printf("\nValue of R: %i", r->data);
      printf("\nValue of AUX: %i", aux->data);
      printf("\nValue of Right Children: %i", r->right->data);
      r = r->right;  // o nó aux passa a receber o valor da direita
      printf("\nValue of new R: %i", r->data);
      free(aux);  // libera o espaço do nó
    } else if (r->right == NULL) {  // quando tiver apenas filho na esquerda
      Tree* aux = r; 
      r = r->left;
      free(aux);
    } else { // nó com dois filhos
      Tree* aux = r->right;
      while (aux->left != NULL) aux = aux->left;
      r->data = aux->data;
      r->right = removeElement(r->right, aux->data);
    }
  }
  return r;
}


void main () {
  Tree* a = NULL;

  a = insert(a, 19);
  a = insert(a, 8);
  a = insert(a, 27);
  a = insert(a, 4);
  a = insert(a, 15);
  a = insert(a, 25);
  a = insert(a, 32);
  a = insert(a, -9);
  a = insert(a, 14);
  a = insert(a, 17);

 /*       
          19
        /   \
       8      27
      / \    /  \
     4  15  25  32
    /   / \
  -9   14  17

 */

  printf("Output: \n");
  printInOrder(a);

  a = removeElement(a, 8);

  printf("\n\n After to remove the 8: \n");
  printInOrder(a);

/*         
          19
        /   \
      14      27
     / \     / \
    4   15  25  32
   /      \
 -9        17

*/

}