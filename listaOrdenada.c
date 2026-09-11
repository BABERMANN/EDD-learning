#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int max;
    int tamanho;
    int *list;
}t_list;

t_list * cria_list(int max){
    t_list * lista = malloc(sizeof(t_list));
    lista->max = max;
    lista->tamanho = 0;
    lista->list = malloc(sizeof(int) * max);
    return lista;
}

void print_list(t_list * lista){
    for(int i = 0; i <= lista->tamanho - 1; i++){
        printf("%d",lista->list[i]);
    }
}

int is_empty(t_list * lista){
    return lista->tamanho == 0;
}

int is_full(t_list * lista){
    return lista->tamanho == lista->max;
}