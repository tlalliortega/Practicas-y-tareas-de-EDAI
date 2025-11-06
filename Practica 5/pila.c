#include <stdio.h>
#define MAX 5


typedef struct {
    int datos[MAX];
    int tope;
} Pila;


void inicializarPila(Pila *p){
    p->tope= -1;
    printf("Pila incializada vacia.\n");
}

int estaLlena(Pila *p){
    return p->tope == MAX -1;
}

int estaVacia(Pila *p){
    return p->tope == -1;
}

void push(Pila *p, int valor){
    if (estaLlena(p)){
        printf("La pila esta llena. No se puede insertar %d.\n", valor);
        return;
    }
    p->tope++;
    p->datos[p->tope] = valor; 
    printf("Elemento %d apilado .\n", valor);
}

int pop(Pila *p){
    if (estaVacia(p)){
        printf("La pila esta vacia. No se puede desapilar.\n");
        return -1;
    }
    int valor = p->datos[p->tope];
    p->tope--;
    return valor;
}
 
void mostrarPila(Pila *p){
    if (estaVacia(p)){
        printf("Pila vacia.\n");
        return;
    }
    printf("Estado actual de la pila: ");
    for (int i = p->tope; i >= 0; i--){
        printf("%d", p->datos[i]);
    }
    printf("\n");
}

int main() {
    Pila miPila;
    inicializarPila(&miPila);

    int n, valor;

    
    printf("¿Cuántos elementos quieres apilar? (máximo %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        printf("Introduce el elemento #%d: ", i + 1);
        scanf("%d", &valor);
        push(&miPila, valor);
        mostrarPila(&miPila);
    }

    
    printf("¿Cuántos elementos quieres desapilar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        valor = pop(&miPila);
        if (valor != -1) {
            printf("Elemento %d desapilado.\n", valor);
            mostrarPila(&miPila);
        }
    }

    return 0;
}
