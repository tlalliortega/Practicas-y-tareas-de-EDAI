#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

int getRear(Deque *deque) {
    return (deque->front + deque->size - 1 + MAX) % MAX;
}

void inicializarDeque(Deque *deque) {
    deque->front = 0;
    deque->size = 0;
    printf("Deque inicializado.\n");
}

int isFull(Deque *deque) {
    return deque->size == MAX;
}

int isEmpty(Deque *deque) {
    return deque->size == 0;
}

void insert_front(Deque *deque, int valor) {
    if (isFull(deque)) {
        printf("Error: deque lleno.\n");
        return;
    }
    deque->front = (deque->front - 1 + MAX) % MAX;
    deque->datos[deque->front] = valor;
    deque->size++;
    printf("Insertando al frente: %d\n", valor);
}

void insert_rear(Deque *deque, int valor) {
    if (isFull(deque)) {
        printf("Error: deque lleno.\n");
        return;
    }
    int rear = getRear(deque);
    int nuevo_rear = (rear + 1) % MAX;
    deque->datos[nuevo_rear] = valor;
    deque->size++;
    printf("Insertando al final: %d\n", valor);
}

int delete_front(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Error: deque vacío.\n");
        return -1;
    }
    int valor = deque->datos[deque->front];
    deque->front = (deque->front + 1) % MAX;
    deque->size--;
    printf("Eliminando del frente: %d\n", valor);
    return valor;
}

int delete_rear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Error: deque vacío.\n");
        return -1;
    }
    int rear = getRear(deque);
    int valor = deque->datos[rear];
    deque->size--;
    printf("Eliminando del final: %d\n", valor);
    return valor;
}

int peek_front(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque vacío.\n");
        return -1;
    }
    return deque->datos[deque->front];
}

int peek_rear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Deque vacío.\n");
        return -1;
    }
    return deque->datos[getRear(deque)];
}

void printDeque(Deque *deque) {
    printf("Estado del deque: ");
    if (isEmpty(deque)) {
        printf("[vacío]\n");
        return;
    }
    int i = deque->front;
    for (int count = 0; count < deque->size; count++) {
        printf("%d ", deque->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\nÍndice front: %d, rear: %d\n", deque->front, getRear(deque));
}

int main() {
    Deque deque;
    inicializarDeque(&deque);

    insert_front(&deque, 10);
    insert_rear(&deque, 15);
    insert_rear(&deque, 20);
    insert_front(&deque, 30);
    insert_rear(&deque, 40);
    printDeque(&deque);

    delete_front(&deque);
    delete_rear(&deque);
    printDeque(&deque);

    insert_front(&deque, 50);
    insert_rear(&deque, 60);
    printDeque(&deque);

    return 0;
}