#include<stdio.h>
#include<stdlib.h>

typedef struct _node { // nome intermediario pra referenciar a si mesma
    int item;
    struct _node *next;
} t_node;

typedef struct{
    t_node * head;
    t_node * tail;
    int size;
}t_list;


