#include <stdio.h>
#include <stdlib.h>  // Biblioteca para malloc(), realloc() y free()

//Inicio del programa con la funcion main y declaracion de variables 

int main() { //Funcion principal y ejecucion del programa 
    int n, nuevo_tamano;  // int n almacena cuantos estudiantes se van a registrar inicialmente. int nuevo_tamaño se usara para agregar a mas estudiantes 
    float *calificaciones = NULL; //Es un puntero a float que luego apuntara a un arreglo dinamico 
    float suma = 0.0; //Acumula la suma de todas las calificaciones 

    // Pregunta al usuario cuantos estudiantes desea registrar 
    printf("¿Cuántos estudiantes deseas registrar? "); //Se mostrara en la pantalla el mensaje 
    scanf("%d", &n);//Guarda ese numero en la variable n 

    // Reserva memoria dinámica con malloc() y muestra un mensaje de error al proporcionar un dato erroneo
    calificaciones = (float *)malloc(n * sizeof(float)); //Se usa malloc para reservar el espacio en memoria para n calificacions tipo float 
    if (calificaciones == NULL) { //Si malloc falla por falta de memoria o error en el sistema devuelve NULL
        printf("Error: no se pudo asignar memoria.\n"); //En este caso se muestra un mensaje de error y el programa termina con return 1 
        return 1;
    }

    // Captura calificaciones y calcula la suma
    for (int i = 0; i < n; i++) { //Se usa el bloque for para pedir la calificacion de cada estudiante
        printf("Calificación del estudiante %d: ", i + 1); // i+1 muestra el numero del estudiante empezando desde 1 
        scanf("%f", &calificaciones[i]); //Cada calificacion se guarda en el arreglo calificaciones[i]
        suma += calificaciones[i]; //Se acumula en suma para calcular el promedio mas adelante. 
    }

    //  Calcula y muestra el promedio inicial
    printf("Promedio inicial: %.2f\n", suma / n); //Se divide la suma total entre el numero de estudiantes n 

    // Pregunta si se desea agregar más estudiantes 
    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): "); //Significa que no va a agregar a mas estudiantes y el arreglo no se modifica
    scanf("%d", &nuevo_tamano);

    if (nuevo_tamano > 0) {    //El usuario pidio agregar a mas estudiantes. 
        //  Amplia el arreglo con realloc()
        float *temp = realloc(calificaciones, (n + nuevo_tamano) * sizeof(float));
        if (temp == NULL) {    //Verifica si realloc () fallo. Si falla devuelve NULL y se libera la memoria previamente asignada con free(calificaciones)
            printf("Error: no se pudo reasignar memoria.\n");
            free(calificaciones);
            return 1; // termina el programa indicando error
        }
        calificaciones = temp; //Si realloc() fue exitoso, se actualiza el puntero de calificaciones para que apunte a la nueva memoria

        // Captura las nuevas calificaciones
        for (int i = n; i < n + nuevo_tamano; i++) { //El bloque for captura las calificacions PARA los nuevos estudiantes
            //El indice comienza en n (tamaño original) y termina en n+nuevo_tamaño
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i]; //Cada calificacion se guarda en el arreglo y se suma a la variable suma para actualizar el promedio
        }

        // Actualiza el tamaño total
        n += nuevo_tamano;  //Se actualiza la variable n para reflejar el numero total de estudiantes registrados. 
    }

    //  Muestra todas las calificaciones y promedio final
    printf("Calificaciones registradas \n"); 
    for (int i = 0; i < n; i++) {  //El bucle for recorre el arreglo calificaciones desde el indice 0 hasta n-1
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);//%.2f imprime la calificacion con dos decimales
    }
    printf("Promedio general: %.2f\n", suma / n); //Calcula el promedio total dividiendo la suma total de calificaciones entre el numero de estudiantes n 

    // Libera la memoria que fue asignada con malloc o realloc para evitar memory leaks 
    free(calificaciones);  // Despues de esta linea el puntero calificaciones ya no apunta a memoria valida 
    return 0;
}