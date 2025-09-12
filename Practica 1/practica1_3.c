#include <stdio.h>


void leerVector(int vector[], int n);
void mostrarVector(int vector[], int n, const char *mensaje);
void invertirVector(int vector[], int n);

int main() {
    int n;

    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);

    int vector[n]; 

    leerVector(vector, n);

    
    mostrarVector(vector, n, "\n🔹 Vector original:");

   
    invertirVector(vector, n);

    
    mostrarVector(vector, n, "\n Vector invertido:");

    return 0;
}


void leerVector(int vector[], int n) {
    printf("Ingrese los %d elementos del vector:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vector[i]);
    }
}


void mostrarVector(int vector[], int n, const char *mensaje) {
    printf("%s\n", mensaje);
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}


void invertirVector(int vector[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = vector[i];
        vector[i] = vector[n - 1 - i];
        vector[n - 1 - i] = temp;
    }
}