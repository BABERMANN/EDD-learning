#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int max;
    int * pilha;
    int top_index;
}t_pilha;

t_pilha * create_pilha(int maximo){
    t_pilha * pilha = malloc(sizeof(t_pilha));
    pilha->max = maximo;
    pilha->pilha = malloc(sizeof(int) * pilha->max);
    pilha->top_index = -1;
    return pilha;
}

int is_full(t_pilha * pilha){
    return pilha->max == pilha->top_index + 1;
}

int is_empty(t_pilha * pilha){
    return pilha->top_index == -1;
}

int push(t_pilha * pilha, int element){
    if (is_full(pilha)) return 0;
    pilha->top_index++;
    pilha->pilha[pilha->top_index] = element;
    return 1;
}

int pop(t_pilha * pilha, int * removed_element){
    if(is_empty(pilha)) return 0;
    *removed_element = pilha->pilha[pilha->top_index];
    pilha->top_index--;
    return 1;
}

int peek(t_pilha * pilha, int * topo){
    if(is_empty(pilha)) return 0;
    *topo = pilha->pilha[pilha->top_index];
    return 1;
}