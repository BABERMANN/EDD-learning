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
