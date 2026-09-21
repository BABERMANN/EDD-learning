#include <stdio.h>
#include <stdlib.h>

typedef struct _node // nome intermediario pra referenciar a si mesma
{
    int item;
    struct _node *next;
} t_node;

typedef struct
{
    t_node *head;
    t_node *tail;
    int size;
} t_list;

t_list *create_list()
{
    t_list *lista = malloc(sizeof(t_list));

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    return lista;
}

int is_empty(t_list *lista)
{
    return lista->size == 0;
}

int append(t_list *lista, int element)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->item = element; // conteudo guardado
    new_node->next = NULL;    // feito sempre no principio, pois cada nó novo nao sabe o proximo elemento

    if (is_empty(lista))
    {
        lista->head = new_node; // primeiro elemento sempre vai ser definido como head
    }
    else
    {
        lista->tail->next = new_node;
    }
    lista->tail = new_node;
    lista->size++;

    return 1;
}

void print_list(t_list *lista)
{
    t_node *aux = lista->head;
    while (aux != NULL)
    {
        printf("%d", aux->item);
        aux = aux->next;
    }
}

int remove_item(t_list *lista, t_node *node_to_remove)
{
    if (is_empty(lista))
        return 0;

    if (lista->size == 1 && lista->head == node_to_remove)
    {
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
        free(node_to_remove);
        return 1;
    }

    if (lista->head == node_to_remove)
    {
        lista->head = lista->head->next;
        free(node_to_remove);
        lista->size--;
        return 1;
    }

    t_node *aux = lista->head;
    while (aux->next != NULL)
    {
        if (node_to_remove == lista->tail && aux->next == node_to_remove)
        {
            lista->tail = aux;
            aux->next = NULL;
            break;
        }

        if (aux->next == node_to_remove)
        {
            aux->next = aux->next->next;
            break;
        }

        aux = aux->next;
    }
    free(node_to_remove);
    lista->size--;
    return 1;
}

t_node * get_node_item(t_list * lista, int element){
    if(is_empty(lista)) return NULL;

    t_node * aux = lista->head;

    while(aux != NULL && aux->item != element){
        aux = aux->next;
    }

    return aux;
}