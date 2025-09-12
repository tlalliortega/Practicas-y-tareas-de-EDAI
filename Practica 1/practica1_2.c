#include <stdio.h>

void leerVector(int vector[], int n);
int calcularSuma(int vector[], int n);
int calcularResta(int vector[], int n);
float calcularPromedio(int suma, int n);
void encontrarMinMax(int vector[], int n, int *min, int *max, int *idx_min, int *idx_max);

int main() {
    int n;

    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &n);

    int vector[n];

    leerVector(vector, n);

    int suma = calcularSuma(vector, n);
    int resta = calcularResta(vector, n);
    float promedio = calcularPromedio(suma, n);

    int min, max, idx_min, idx_max;
    encontrarMinMax(vector, n, &min, &max, &idx_min, &idx_max);

    printf("\n Resultados:\n");
    printf("Suma: %d\n", suma);
    printf("Resta acumulada: %d\n", resta);
    printf("Promedio: %.2f\n", promedio);
    printf("Mínimo: %d en la posición %d\n", min, idx_min);
    printf("Máximo: %d en la posición %d\n", max, idx_max);

    return 0;
}
