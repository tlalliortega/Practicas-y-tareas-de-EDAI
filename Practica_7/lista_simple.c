#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no localizado en la lista.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Valor %d eliminado.\n", valor);
}
void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    printf("Memoria liberada exitosamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int n, valor;
    printf("¿Cuantos valores quieres insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta el valor #%d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        printf("Lista actual: ");
        recorrer(cabeza);
    }
    printf("Lista completa: ");
    recorrer(cabeza);
    printf("¿Que valor quieres eliminar? ");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    printf("Lista despues de eliminar: ");
    recorrer(cabeza);
    liberar(cabeza);

    return 0;
}
//Preguntas
//1. ¿Por qué las listas enlazadas no requieren tamaño fijo como los arreglos?
//Las listas enlazadas se construyen usando memoria dinamica con malloc, lo que le permite crear nodos en tiempo de ejecucion. Los arreglos tienen un tamaño fijo desde su creación.

//2. ¿Qué diferencia hay entre mover la cabeza y modificar los punteros internos?
//Mover la cabeza afecta el punto de entrada de toda la lista. Modificar los punteros internos mantiene la cabeza intacta y solo ajusta conexiones dentro de la lista. 






