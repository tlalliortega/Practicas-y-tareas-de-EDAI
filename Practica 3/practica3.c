#include <stdio.h>
#include <string.h>

#define TAM 5       
#define NUM_DIR 2   

struct pelicula {
    char nombre[30];
    char genero[20];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][30];
};

int validarVideoteca(struct pelicula videoteca[], int total) {
    if (total <= 0) {
        printf(" Error: número inválido de películas.\n");
        return 0;
    }
    for (int i = 0; i < total; i++) {
        if (videoteca[i].numDirectores <= 0) {
            printf(" Error: la película '%s' no tiene directores válidos.\n", videoteca[i].nombre);
            return 0;
        }
    }
    return 1;
}

void imprimirInverso(struct pelicula videoteca[], int total) {
    printf("\n Videoteca en orden inverso:\n");
    for (int i = total - 1; i >= 0; i--) {
        printf("Pelicula: %s\n", videoteca[i].nombre);
        printf("Genero: %s\n", videoteca[i].genero);
        printf("Anio: %d\n", videoteca[i].anio);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
        printf("\n");
    }
}

void buscarPorNombre(struct pelicula videoteca[], int total, const char *nombre) {
    printf("\n Buscando por nombre: %s\n", nombre);
    for (int i = 0; i < total; i++) {
        if (strcmp(videoteca[i].nombre, nombre) == 0) {
            printf("Encontrada: %s (%d) - %s\n", videoteca[i].nombre, videoteca[i].anio, videoteca[i].genero);
        }
    }
}

void buscarPorAnio(struct pelicula videoteca[], int total, int anio) {
    printf("\n Buscando por año: %d\n", anio);
    for (int i = 0; i < total; i++) {
        if (videoteca[i].anio == anio) {
            printf("Encontrada: %s (%d) - %s\n", videoteca[i].nombre, videoteca[i].anio, videoteca[i].genero);
        }
    }
}

void buscarPorDirector(struct pelicula videoteca[], int total, const char *director) {
    printf("\n Buscando por director: %s\n", director);
    for (int i = 0; i < total; i++) {
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            if (strcmp(videoteca[i].directores[j], director) == 0) {
                printf("Encontrada: %s (%d) - %s\n", videoteca[i].nombre, videoteca[i].anio, videoteca[i].genero);
            }
        }
    }
}

void contarPorGenero(struct pelicula videoteca[], int total) {
    printf("\n Conteo por género:\n");
    for (int i = 0; i < total; i++) {
        int contador = 1;
        for (int j = i + 1; j < total; j++) {
            if (strcmp(videoteca[i].genero, videoteca[j].genero) == 0) {
                contador++;
            }
        }
        int yaContado = 0;
        for (int k = 0; k < i; k++) {
            if (strcmp(videoteca[i].genero, videoteca[k].genero) == 0) {
                yaContado = 1;
                break;
            }
        }
        if (!yaContado) {
            printf("%s: %d película(s)\n", videoteca[i].genero, contador);
        }
    }
}

int main(void) {
    struct pelicula videoteca[TAM];
    int total;

    printf(" ¿Cuántas películas desea ingresar? (máx %d): ", TAM);
    scanf("%d", &total);
    getchar(); // limpiar buffer

    for (int i = 0; i < total; i++) {
        printf("\n Película #%d\n", i + 1);
        printf("Nombre: ");
        fgets(videoteca[i].nombre, 30, stdin);
        videoteca[i].nombre[strcspn(videoteca[i].nombre, "\n")] = 0;

        printf("Género: ");
        fgets(videoteca[i].genero, 20, stdin);
        videoteca[i].genero[strcspn(videoteca[i].genero, "\n")] = 0;

        printf("Año: ");
        scanf("%d", &videoteca[i].anio);
        getchar();

        printf("Número de directores (máx %d): ", NUM_DIR);
        scanf("%d", &videoteca[i].numDirectores);
        getchar();

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  Director #%d: ", j + 1);
            fgets(videoteca[i].directores[j], 30, stdin);
            videoteca[i].directores[j][strcspn(videoteca[i].directores[j], "\n")] = 0;
        }
    }

    if (!validarVideoteca(videoteca, total)) return 1;

    imprimirInverso(videoteca, total);
    contarPorGenero(videoteca, total);

    char criterio[30];
    printf("\n ¿Desea buscar por nombre, año o director? ");
    fgets(criterio, 30, stdin);
    criterio[strcspn(criterio, "\n")] = 0;

    if (strcmp(criterio, "nombre") == 0) {
        char nombre[30];
        printf("Ingrese el nombre: ");
        fgets(nombre, 30, stdin);
        nombre[strcspn(nombre, "\n")] = 0;
        buscarPorNombre(videoteca, total, nombre);
    } else if (strcmp(criterio, "año") == 0) {
        int anio;
        printf("Ingrese el año: ");
        scanf("%d", &anio);
        buscarPorAnio(videoteca, total, anio);
    } else if (strcmp(criterio, "director") == 0) {
        char director[30];
        getchar();
        printf("Ingrese el nombre del director: ");
        fgets(director, 30, stdin);
        director[strcspn(director, "\n")] = 0;
        buscarPorDirector(videoteca, total, director);
    }

    return 0;
}