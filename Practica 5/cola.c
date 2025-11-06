#include <stdio.h>
#define MAX 5 

//definicion de la estructura de la COla
typedef struct {
    int datos[MAX]; 
    int frente; 
    int final; 
} Cola;

// Inicia la cola vacia
void inicializarCola(Cola *c){
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacia.\n");
}

// verifica si la cola esta llena
int estaLlena(Cola *c){
    return c->final == MAX - 1;
}

// verifica si la cola esta vacia 
int estaVacia(Cola *c){
    return c->frente > c->final;
}

//inserta un elemento a la cola 
void enqueue(Cola *c, int valor){
    if (estaLlena(c)){
        printf("La cola esta llena. No se puede insertar %d.\n", valor);
        return;
    }
    c->final++;
    c->datos[c->final] = valor;
    printf("Elemento %d encolado.\n", valor);
}

// extraer un elemento de la cola
int dequeue(Cola *c){
    if (estaVacia(c)){
        printf("La cola esta vacia. No se puede desencolar.\n ");
        return -1;
    }
    int valor = c->datos[c->frente];
    c->frente++;
    return valor;
}

// Mostrar el estado actual de la cola
void mostrarCola(Cola *c){
    if (estaVacia(c)){
        printf("Cola vacia.\n");
        return;
    }
    printf("Estado actual de la cola: ");
    for (int i = c->frente; i <= c->final; i++){
        printf("%d", c->datos[i]);
    }
    printf("\n");
}
int main(){
    Cola miCola;
    inicializarCola(&miCola);
    int n, valor;

    //Insertar elementos
    printf("¿Cuantos elementos quiere encolar? (maximo %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    for (int i = 0; i < n; i++){
        printf("Introduce el elemento #%d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&miCola, valor);
        mostrarCola(&miCola);
    }

    //Extraer elementos
    printf("¿cuantos elementos quieres desencolar?: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        valor = dequeue(&miCola);
        if (valor !=-1){
            printf("Elemento %d desendolado .\n", valor);
            mostrarCola(&miCola);
        }
    }
    return 0;
}