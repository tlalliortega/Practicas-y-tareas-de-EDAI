#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};
void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
       
        nuevo->siguiente = nuevo;
        *cabeza = nuevo;
        *ultimo = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }
}

void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(cabeza)\n");
}


void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacia. No se puede eliminar.\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;
    int encontrado = 0;

    do {
        if (actual->dato == valor) {
            encontrado = 1;
            if (actual == *cabeza) {
                if (*cabeza == *ultimo) {
                    
                    free(actual);
                    *cabeza = NULL;
                    *ultimo = NULL;
                } else {
                    *cabeza = actual->siguiente;
                    (*ultimo)->siguiente = *cabeza;
                    free(actual);
                }
            } else {
                anterior->siguiente = actual->siguiente;
                if (actual == *ultimo) {
                    *ultimo = anterior;
                }
                free(actual);
            }
            printf("Valor %d eliminado.\n", valor);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Valor %d no encontrado en la lista.\n", valor);
    }
}


void liberarCircular(struct Nodo **cabeza, struct Nodo **ultimo) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *temp;

    do {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    } while (actual != *cabeza);

    *cabeza = NULL;
    *ultimo = NULL;
    printf("Memoria liberada correctamente.\n");
}


int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor;

    
    printf("¿Cuantos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta el valor #%d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        printf("Lista actual: ");
        recorrerCircular(cabeza);
    }

    
    printf("Lista completa: ");
    recorrerCircular(cabeza);

   
    printf("¿Que valor deseas eliminar? ");
    scanf("%d", &valor);
    eliminarCircular(&cabeza, &ultimo, valor);

    printf("Lista despues de eliminar: ");
    recorrerCircular(cabeza);

    
    liberarCircular(&cabeza, &ultimo);

    return 0;
}
//Preguntas
//1. ¿Qué ventaja tiene la lista circular frente a la simple?
//Podemos recorrer todos los elementos sin que lleguen a NULL, lo que es util para estructuras con ciclos repetitivos.

//2. ¿Qué error puede causar un bucle infinito en una lista circular?
//Si olvidamos verificar que el nodo actual ha regresado a la cabeza, el ciclo while y do-while nunca termina. Tambien actualizar los enlaces al eliminar o insertar.

//3. ¿Qué estructuras o programas del mundo real se basan en listas circulares?
//1.- Sistemas operativos 2.-Juegos de mesa o turnos 3.-Buffers circulares(audio,video o redes) 4.-Relojes analogicos. 
