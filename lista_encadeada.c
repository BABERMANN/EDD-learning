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

t_list * create_list(){
    t_list * lista = malloc(sizeof(t_list));
    
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int is_empty(t_list * lista){
    return lista->size == 0;
}

int append(t_list * lista, int element){
    t_node * new_node = malloc(sizeof(t_node));
    new_node->item = element; // conteudo guardado
    new_node->next = NULL; // feito sempre no principio, pois cada nó novo nao sabe o proximo elemento

    if(is_empty(lista)){
        lista->head = new_node; // primeiro elemento sempre vai ser definido como head
    }else{
        lista->tail->next = new_node;    
    }
    lista->tail = new_node;
    lista->size++;

    return 1;
}

