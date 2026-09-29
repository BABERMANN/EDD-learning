#include <stdlib.h>
#include <stdio.h>

typedef struct _node{
    char letra;
    struct _node *dir;
    struct _node *esq;
}t_node;

typedef struct{
    struct _node *root;
    int qtd_nos;
}t_tree;

t_tree * create_tree(){
    t_tree * tree = malloc(sizeof(t_tree));

    if(tree == NULL) exit(1); // verifica se o malloc conseguiu alocar, caso nao, exit(1)

    tree->root = NULL;
    tree->qtd_nos = 0;

    return tree;
}