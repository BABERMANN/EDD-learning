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

int enqueue(t_fila * fila, int element){
    if(is_full(fila)) return 0;
    fila->list[fila->fim] = element;
    fila->fim = (fila->fim + 1) % fila->max;
    fila->qtd++;
    return 1;
}

int dequeue(t_fila * fila, int * element){
    if(is_empty(fila)) return 0;
    *element = fila->list[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->max;
    fila->qtd--;
    return 1;
}

void print_fila(t_fila* fila){
    if(is_empty(fila)) printf("tem nada");
    else{
        for(int i = 0; i < fila->qtd; i++){
            int valor = (fila->inicio + i) % fila->max;
            printf("%d",fila->list[valor]);
        }
    }
}