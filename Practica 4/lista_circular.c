#include <stdio.h>
#include <stdlib.h>

int main (){
    int n, m, i;
    int *arr, *arr2; 

    // Reservar memoria con malloc
    printf("¿Cuantos enteros deseas almacenar?");
    scanf("%d", &n); 
    arr = (int *)malloc(n * sizeof(int)); 
    if (arr == NULL){
        printf("error al reservar memoria con malloc.\n");
        return 1;
    }
    printf("\nValores iniciales con malloc (basura):\n");
    for (i = 0; i < n; i++){
        printf("arr2[%d] = %d\n, i, arr[i]");
    }

    //reservar memoria con calloc
    arr2 = (int *)calloc(n, sizeof(int)); 
    if (arr2 == NULL){
        printf("error al reservar memoria con calloc.\n ");
        free(arr);
        return 1;
    }
    printf("\nValores iniciales con calloc (ceros):\n");
    for (i = 0; i < n; i++){
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // llenado del arreglo arr2
    printf("\nIngresa %d valores para arr2: \n", n);
    for (i = 0; i < n; i++){
        printf("arr2[%d] = ", i); 
        scanf("%d", &arr2[i]); 
    }

    //redimensionar con realloc 
    printf("\n¿Nuevo tamaño para el arreglo arr2?"); 
    scanf ("%d", &m); 
    int *temp = (int*)realloc(arr2, m * sizeof(int)); 
    if (temp == NULL){
        printf("error al redimencionar con realloc.\n");
        free(arr); 
        free(arr2);
        return 1; 
    }
    arr2 = temp; 

    // si el nuevo tamaño es mayor, añadir los valores restantes
    if (m > n){
        printf ("\nIngresa los %d valores adicionales: \n", m - n); 
        for (i = n; i < m; i++){
            printf("arr2[%d] = ", i);
            scanf("%d", &arr2[i]); 
        }
    }
    // imprimir los nuevos valores 
    printf("\nValores finales en arr2:\n");
    for (i = 0; i < m; i++){
        printf ("arr2[%d] = %d\n", i, arr2[i]);
    }

    //liberacion de memoria
    free (arr);
    free(arr2);
    printf("\nMemoria liberada exitosamente.\n");

    return 0; 
}