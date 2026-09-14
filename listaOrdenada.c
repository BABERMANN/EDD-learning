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


int main() {
    t_list *lista = cria_list(5);

    printf("Lista vazia? %d\n", is_empty(lista)); 

    append(lista, 3);
    append(lista, 7);
    append(lista, 1);
    append(lista, 5);
    printf("Depois dos appends: ");
    print_list(lista); 

    printf("Lista cheia? %d\n", is_full(lista)); 

    inserir_element(lista, 1, 10);
    printf("Depois do insert(1, 10): ");
    print_list(lista); 

    printf("Lista cheia agora? %d\n", is_full(lista)); 

    int falhou = append(lista, 99);
    printf("Tentei append numa lista cheia, retornou: %d\n", falhou); 

    printf("index_of(7) = %d\n", index_of(lista, 7)); 
    printf("index_of(999) = %d\n", index_of(lista, 999)); 

    update(lista, 0, 30);
    printf("Depois do update(0, 30): ");
    print_list(lista); 

    printf("get_index(2) = %d\n", get_index(lista, 2)); 
    printf("get_index(99) = %d\n", get_index(lista, 99)); 

    remove_by_index(lista, 1);
    printf("Depois do remove_by_index(1): ");
    print_list(lista); 

    remove_by_element_short(lista, 1);
    printf("Depois do remove_by_element_short(1): ");
    print_list(lista); 

    int nao_achou = remove_by_element_short(lista, 999);
    printf("Tentei remover 999 (nao existe), retornou: %d\n", nao_achou); 

    return 0;
}