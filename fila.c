#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int max;
    int qtd;
    int * list;
    int inicio;
    int fim;
}t_fila;


t_fila * cria_fila(int tamanho){
    t_fila * fila = malloc(sizeof(t_fila));
    fila->max = tamanho;
    fila->qtd = 0;
    fila->inicio = 0;
    fila->fim = 0;
    fila->list = malloc(sizeof(int) * tamanho);
    
    return fila;
}

int is_empty(t_fila * fila){
    return fila->qtd == 0;
}

int is_full(t_fila * fila){
    return fila->qtd == fila->max;
}