#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    char letra;
    struct _node *dir;
    struct _node *esq;
} t_node;

typedef struct
{
    struct _node *root;
    int qtd_nos;
} t_tree;

t_tree *create_tree()
{
    t_tree *tree = malloc(sizeof(t_tree));
    if (tree == NULL)
        exit(1); // verifica se o malloc conseguiu alocar, caso nao, exit(1)

    tree->root = NULL;
    tree->qtd_nos = 0;

    return tree;
}

int is_empty(t_tree *tree)
{
    return tree->root == NULL;
}

t_node *create_node(char letra)
{
    t_node *node = malloc(sizeof(t_node));
    if (node == NULL)
        return NULL; // caso nao consiga alocar retorna null

    node->letra = letra;
    node->dir = NULL;
    node->esq = NULL;

    return node;
}

int insert_root(t_tree *tree, char letra)
{
    if (tree == NULL)
        return 0;

    if (!is_empty(tree))
        return 0;

    t_node *node = create_node(letra);

    if(node == NULL) return 0;

    tree->root = node;
    tree->qtd_nos++;

    return 1;
}

