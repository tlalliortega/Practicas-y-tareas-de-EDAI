#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int valor;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};
void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->valor = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;
    if (*inicio != NULL){
        (*inicio)->anterior = nuevo;
    }
    *inicio = nuevo;
}
void insertarFinal(struct Nodo **inicio, int valor){
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    if (*inicio == NULL){
        nuevo->anterior = NULL;
        *inicio = nuevo;
        return;
    }
    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL){
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
    temp->anterior = temp;
}
void recorrerAdelante(struct Nodo *inicio){
    struct Nodo *temp = inicio;
    printf("Recorrido hacia adelnate: ");
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->siguiente;
    }
    printf("\n");
}
void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;
    while (temp != NULL && temp->valor != valor) {
        temp = temp->siguiente;
    }
    if (temp == NULL){
        printf("Valor %d no encontrado en la lista.\n", valor);
        return;
    }
    if (temp->anterior == NULL){
        *inicio = temp->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    }
    else if (temp->siguiente == NULL) {
        temp->anterior->siguiente = NULL;
    }
    else{
        temp->anterior->siguiente = temp->siguiente;
        temp->siguiente->anterior = temp->anterior;
    }
    free(temp);
    printf("Nodo con valor %d elimindo.\n", valor);
}
void liberar(struct Nodo *inicio){
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
    printf("Memoria liberda correctamente. \n");
}
int main() {
    struct Nodo *inicio = NULL;
    int n, valor, i; 
    printf("¿Cuantos valores deseas insertar al incio? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }
    recorrerAdelante(inicio);
    printf("¿Cuantos valores deseas insertar al final? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }
    recorrerAdelante(inicio);
    recorrerAdelante(inicio);
    recorrerAdelante(inicio);
    printf("Ingresa el valor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);
    recorrerAdelante(inicio);
    liberar(inicio);
    return 0;
}

