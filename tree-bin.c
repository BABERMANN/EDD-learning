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