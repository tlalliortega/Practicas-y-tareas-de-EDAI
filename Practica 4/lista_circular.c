#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

int main() {
    int n, m, i, valor;
    Nodo *inicio = NULL, *actual = NULL, *temp = NULL;

    // reservar memoria con malloc
    printf("¿Cuántos enteros quieres almacenar en la lista circular? ");
    scanf("%d", &n);

    printf("\nCreando lista circular con malloc (valores basura):\n");
    for (i = 0; i < n; i++) {
        temp = (Nodo *)malloc(sizeof(Nodo));
        if (temp == NULL) {
            printf("Error al reservar memoria.\n");
            return 1;
        }
        temp->dato = rand(); // basura simulada
        temp->siguiente = NULL;

        if (inicio == NULL) {
            inicio = temp;
            actual = temp;
        } else {
            actual->siguiente = temp;
            actual = temp;
        }
    }
    actual->siguiente = inicio; // cerrar el ciclo

    // mostrar valores basura
    temp = inicio;
    for (i = 0; i < n; i++) {
        printf("Nodo %d: %d\n", i, temp->dato);
        temp = temp->siguiente;
    }

    // crear nueva lista con calloc
    Nodo *inicio2 = NULL, *actual2 = NULL;
    printf("\nCreando nueva lista circular con calloc (valores en 0):\n");
    for (i = 0; i < n; i++) {
        temp = (Nodo *)calloc(1, sizeof(Nodo));
        if (temp == NULL) {
            printf("Error al reservar memoria.\n");
            return 1;
        }

        if (inicio2 == NULL) {
            inicio2 = temp;
            actual2 = temp;
        } else {
            actual2->siguiente = temp;
            actual2 = temp;
        }
    }
    actual2->siguiente = inicio2;

    // mostrar valores iniciales
    temp = inicio2;
    for (i = 0; i < n; i++) {
        printf("Nodo %d: %d\n", i, temp->dato);
        temp = temp->siguiente;
    }

    // llenar la lista
    printf("\nIngresa %d valores para la lista:\n", n);
    temp = inicio2;
    for (i = 0; i < n; i++) {
        printf("Nodo %d: ", i);
        scanf("%d", &temp->dato);
        temp = temp->siguiente;
    }

    // redimensionar la lista
    printf("\n¿Nuevo tamaño de la lista? ");
    scanf("%d", &m);

    if (m > n) {
        for (i = n; i < m; i++) {
            temp = (Nodo *)malloc(sizeof(Nodo));
            if (temp == NULL) {
                printf("Error al reservar memoria.\n");
                return 1;
            }
            printf("Nodo %d: ", i);
            scanf("%d", &temp->dato);
            temp->siguiente = inicio2;
            actual2->siguiente = temp;
            actual2 = temp;
        }
    }

    // mostrar todos los valores
    printf("\nValores finales en la lista circular:\n");
    temp = inicio2;
    for (i = 0; i < m; i++) {
        printf("Nodo %d: %d\n", i, temp->dato);
        temp = temp->siguiente;
    }

    // liberar memoria
    temp = inicio;
    for (i = 0; i < n; i++) {
        Nodo *sig = temp->siguiente;
        free(temp);
        temp = sig;
    }

    temp = inicio2;
    for (i = 0; i < m; i++) {
        Nodo *sig = temp->siguiente;
        free(temp);
        temp = sig;
    }

    printf("\nMemoria liberada correctamente.\n");
    return 0;
}



// ACTIVIDAD

// 1. ¿Qué diferencia observaron entre los valores iniciales con malloc y calloc?
// Con malloc los valores iniciales eran basura, porque la memoria se reservo pero no se limpio. Con calloc los valores inciales fueron 0 porque calloc limpio la memoria.

// 2. ¿Qué sucede si en realloc piden un tamaño más grande que el original? ¿y más
//pequeño?
//Si el tamaño es más grande el programa le solicitara al usuario añadir el valor restante.
//En cambio, si es pequeño los valores se reducen y los elementos que exceden el nuevo tamaño se pierden y la memoria liberada se devuelve al sistema.  

//3. ¿Qué pasa si olvidan llamar a free?
// La memoria no se libera incluso si el programa termina, provocando una memory leak lo que provoca que el sistema tenga fallas. 

