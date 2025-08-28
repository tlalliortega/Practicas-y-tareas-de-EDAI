#include <stdio.h>

int main(void) {
    int n;
    int a[50];

    printf("Ingresa una cantidad (máximo 50): ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Error: la cantidad debe estar entre 1 y 50.\n");
        return 1;
    }

    printf("Ingrese %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nLos elementos del array son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}

