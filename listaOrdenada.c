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

 int append(t_list * lista, int element){
    if(is_full(lista)) return 0;

    lista->list[lista->tamanho] = element;
    lista->tamanho++;
    return 1;
 }

 int inserir_element(t_list * lista,int index, int element){
    if(is_full(lista) || index < 0) return 0;

    if(index >= lista->tamanho + 1) return 0;

    for(int i = lista->tamanho; i > index; i--){
        lista->list[i] = lista->list[i - 1];
    }
    lista->list[index] = element;
    lista->tamanho++;
    return 1;
 }


int remove_by_index(t_list * lista,int index){
    if(is_empty(lista) || index < 0 || index >= lista->tamanho) return 0;

    for(int i = index; i < lista->tamanho - 1; i++){
        lista->list[i] = lista->list[i + 1];
    }

    lista->tamanho--;
    return 1;

}

int index_of(t_list * lista, int element){
    for(int i = 0; i < lista->tamanho; i++){
        if(lista->list[i] == element) return i;
    }
    return -1;
}

int update(t_list * lista, int index, int element){
    if (index < 0 || index >= lista->tamanho) return 0;

    lista->list[index] = element;
    return 1;
}

int get_index(t_list * lista, int index){
    if (index < 0 || index >= lista->tamanho) return -1;

    return lista->list[index];
}

int remove_by_element(t_list * lista, int element){
    for(int i = 0; i < lista->tamanho; i++){
        if(lista->list[i] == element){
            for(int j = i; j < lista->tamanho - 1; j++){
                lista->list[j] = lista->list[j + 1];
            }
            lista->tamanho--;
            return 1;
        }
    }
    return 0;
}


int remove_by_element_short(t_list * lista, int element){
    int pos = index_of(lista,element);
    if(pos == -1) return 0;
    remove_by_index(lista,pos);
    return 1;
}

