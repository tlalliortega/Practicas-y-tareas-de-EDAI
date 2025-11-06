#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente; 
    int final; 
    int size;
} ColaCircular;
void inicializarCola(ColaCircular *cola){
    cola->frente = 0,
    cola->final = 0;
    cola->size = 0;
    printf("Cola circular inicializada.\n");
}
int isEmpty(ColaCircular *cola){
    return cola->size == 0;
}
int isFull(ColaCircular *cola){
    return cola->size == MAX;
}
void enqueue(ColaCircular *cola, int valor){
    if (isFull(cola)){
        printf("Error: la cola esta llena.\n");
        return;
    }
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % MAX;
    cola->size++;
    printf("Encolado: %d\n", valor);
}
int dequeue(ColaCircular *cola){
    if (isEmpty(cola)){
        printf("Error: la cola esta vacia.\n");
        return -1;
    }
    int valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % MAX;
    cola->size--;
    printf("Desencolado: %d\n, valor");
    return valor;
}
int peek(ColaCircular *cola){
    if (isEmpty(cola)){
        printf("La cola esta vacia.\n");
        return -1;
    }
    return cola->datos[cola->frente];
}
void printQueue(ColaCircular *cola){
    printf("Estado de la cola: ");
    if (isEmpty(cola)){
        printf("[vacia]\n");
        return;
    }
    int i = cola->frente;
    for(int count = 0; count < cola->size; count++){
        printf("%d", cola->datos[i]);
        i = (i + 1) & MAX;
    }
    printf("\n");
}
int main(){
    ColaCircular cola;
    inicializarCola(&cola);
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);
    dequeue(&cola);
    printQueue(&cola);
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);
    printf("Elemento en el frente: %d\n", peek(&cola));
    return 0;
}

//Preguntas (A)
//1. ¿Por qué en la cola circular no se desperdician posiciones como en la cola lineal?
// Porque los indices frente y final se van actualizando nuevo indice=(indice actual +1)%MAX permitiendo que el indice de la vuelta al llegar al final del arreglo, y reutiliza los espacios vacios al principio sin desperdiciar memoria.}

//2. ¿Qué pasa cuando el índice final llega al final del arreglo?
// Gracias a la formula circular, el indice final regresa al incio del arreglo.

//3. ¿Qué sucede si intentas encolar cuando la cola está llena?
//La condicion de la cola es size==MAX si realizamos un enqueue en ese estado el programa rechaza la operacion y muestra un mensaje de error.
