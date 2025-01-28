# Implementação de Árvores Binárias em C

Este repositório contém um projeto que desenvolvi durante a disciplina de **Estrutura de Dados** no segundo período do curso de **Análise e Desenvolvimento de Sistemas (ADS)**. O objetivo principal foi aprender a implementar e manipular árvores binárias, explorando sua eficiência para organização e busca de dados.

## 🔧 Tecnologias Utilizadas

- Linguagem de programação **C**

## ✨ Funcionalidades

Este projeto apresenta as seguintes funcionalidades:

1. **Inserção de Elementos**: Adiciona valores à árvore binária de maneira recursiva, organizando-os de forma que os elementos menores fiquem à esquerda e os maiores à direita.
2. **Remoção de Elementos**: Remove um nó da árvore, ajustando sua estrutura de acordo com as três situações possíveis:
   - Nó sem filhos.
   - Nó com apenas um filho.
   - Nó com dois filhos.
3. **Impressão em Ordem**: Exibe os elementos da árvore em ordem crescente.

## 🗋 Estruturas e Conceitos Utilizados

### Estrutura `Tree`

Cada nó da árvore possui os seguintes atributos:

```c
struct nodeTree {
  int data;                // Valor armazenado no nó
  struct nodeTree *left;   // Ponteiro para o nó à esquerda
  struct nodeTree *right;  // Ponteiro para o nó à direita
};

typedef struct nodeTree Tree;  // Renomeando para simplificar o uso
```

### Funções Implementadas

#### Inserir Elementos

Adiciona valores à árvore:

```c
Tree* insert(Tree* a, int data) {
  if (a == NULL) {
    a = (Tree*)malloc(sizeof(Tree));
    a->data = data;
    a->left = a->right = NULL;
  } else if (data < a->data) {
    a->left = insert(a->left, data);
  } else if (data > a->data) {
    a->right = insert(a->right, data);
  }
  return a;
}
```

#### Remover Elementos

Remove um elemento e ajusta a estrutura da árvore:

```c
Tree* removeElement(Tree* r, int data) {
  if (r == NULL) {
    return NULL;
  } else if (data < r->data) {
    r->left = removeElement(r->left, data);
  } else if (data > r->data) {
    r->right = removeElement(r->right, data);
  } else {
    if (r->left == NULL && r->right == NULL) {
      free(r);
      r = NULL;
    } else if (r->left == NULL) {
      Tree* aux = r;
      r = r->right;
      free(aux);
    } else if (r->right == NULL) {
      Tree* aux = r;
      r = r->left;
      free(aux);
    } else {
      Tree* aux = r->right;
      while (aux->left != NULL) aux = aux->left;
      r->data = aux->data;
      r->right = removeElement(r->right, aux->data);
    }
  }
  return r;
}
```

#### Impressão em Ordem

Exibe os elementos em ordem crescente:

```c
void printInOrder(Tree* a) {
  if (a != NULL) {
    printInOrder(a->left);
    printf("[%d] ", a->data);
    printInOrder(a->right);
  }
}
```

### Exemplo de Uso

Abaixo está o exemplo de execução do programa:

```c
void main() {
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

  printf("\n\n\u00c1rvore em ordem crescente: \n");
  printInOrder(a);

  a = removeElement(a, 8);

  printf("\n\n\u00c1rvore após a remoção do valor 8: \n");
  printInOrder(a);
}
```

### Saída Esperada

Após executar o programa, temos:

1. **Antes de remover o elemento 8:**

```plaintext
[-9] [4] [8] [14] [15] [17] [19] [25] [27] [32]
```

2. **Depois de remover o elemento 8:**

```plaintext
[-9] [4] [14] [15] [17] [19] [25] [27] [32]
```

## 🔑 Compilando e Executando

1. Salve o código em um arquivo chamado `arvore.c`.
2. Compile utilizando o GCC:

   ```bash
   gcc arvore.c -o arvore
   ```

3. Execute o programa:

   ```bash
   ./arvore
   ```

## 🙌 Considerações Finais

Este exercício foi fundamental para entender os conceitos de árvores binárias, incluindo sua eficiência em operações de busca, inserção e remoção. Também proporcionou uma melhor compreensão de estruturas recursivas e da importaância de uma organização eficiente para manipulação de dados.

