#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int valor;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};
void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->valor = valor;
    if (*inicio == NULL){
        nuevo ->siguiente = nuevo; 
        nuevo->anterior = nuevo;
        *inicio = nuevo;
    } else {
        struct Nodo *ultimo = (*inicio)->anterior;
        nuevo->siguiente = *inicio;
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        (*inicio)->anterior = nuevo;  
    }
}
void recorrerCircular(struct Nodo *inicio){
    if (inicio == NULL){
        printf("La lista esta vacia.\n");
        return;
    }
    struct Nodo *temp = inicio;
    printf("Recorrido circular: ");
    do{
        printf("%d", temp->valor);
        temp = temp->siguiente;
    } while (temp != inicio);
    printf("\n"); 
}
void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    struct Nodo *temp = *inicio;
    struct Nodo *previo = NULL;
    do{
        if (temp->valor == valor) break;
        temp = temp->siguiente;
    } while (temp != *inicio);
    if (temp->valor != valor){
        printf("valor %d no encontrado.\n", valor);
        return;
    }
    if (temp->siguiente == temp && temp->anterior == temp) {
        free(temp);
        *inicio = NULL;
        printf("nodo con valor %d eliminado. La lista quedo vacia.\n", valor);
        return;
    }
    if (temp == *inicio) {
        *inicio = temp->siguiente;
    }
    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;

    free(temp);
    printf("nodo con valor %d eliminado.\n", valor);
}
void liberarCircular(struct Nodo **inicio) {
    if (*inicio == NULL){
        printf("La lista ya esta vacia.\n");
        return;
    }
    struct Nodo *temp = *inicio;
    struct Nodo *siguiente;
    do{
        siguiente = temp->siguiente;
        free(temp);
        temp = siguiente;
    } while (temp != *inicio);
    *inicio = NULL;
    printf("Memoria liberada correctamente.\n");
}
int main (){
    struct Nodo *inicio = NULL;
    int n, valor, i;
    printf("¿cuantos valores deseas insertar en la lista circular? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("valor %d: ", i+1);
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
    }
    recorrerCircular(inicio);
    printf("Ingresa el valor a eliminar: ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);
    recorrerCircular(inicio);
    liberarCircular(&inicio);
    return 0;
}





