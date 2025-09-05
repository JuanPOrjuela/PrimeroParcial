#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int edad:7;
    unsigned int id;
    char *nombre;
    char *apellido;
    float *notas;
    int numNotas;
} Estudiante;

Estudiante* crearEstudiante(char *nombre, char *apellido, int edad, int id, float *notas, int n) {
    Estudiante *e = (Estudiante*)malloc(sizeof(Estudiante));
    e->edad = edad;
    e->id = id;

    e->nombre = (char*)malloc(strlen(nombre)+1);
    strcpy(e->nombre, nombre);

    e->apellido = (char*)malloc(strlen(apellido)+1);
    strcpy(e->apellido, apellido);

    e->notas = (float*)malloc(n * sizeof(float));
    for(int i=0; i<n; i++) e->notas[i] = notas[i];
    e->numNotas = n;
    return e;
}

void liberarEstudiante(Estudiante *e) {
    free(e->nombre);
    free(e->apellido);
    free(e->notas);
    free(e);
}

void mostrarEstudiante(Estudiante *e) {
    printf("ID:%d | %s %s | Edad:%d | Notas:", e->id, e->nombre, e->apellido, e->edad);
    for(int i=0; i<e->numNotas; i++) printf(" %.1f", e->notas[i]);
    printf("\n");
}

void eliminarEstudiante(Estudiante **lista, int *n, int pos) {
    liberarEstudiante(lista[pos]);
    for(int i=pos; i<(*n)-1; i++) lista[i] = lista[i+1];
    (*n)--;
    *lista = (Estudiante*)realloc(*lista, (*n)*sizeof(Estudiante*));
}

int main() {
    int n = 0;
    Estudiante **lista = NULL;

    float notas1[] = {4.5, 3.8, 5.0};
    float notas2[] = {2.9, 3.1};

    lista = (Estudiante**)malloc(2 * sizeof(Estudiante*));
    lista[n++] = crearEstudiante("Juan","Perez",20,1001,notas1,3);
    lista[n++] = crearEstudiante("Ana","Lopez",22,1002,notas2,2);

    for(int i=0; i<n; i++) mostrarEstudiante(lista[i]);

    printf("\nEliminando a Ana...\n");
    eliminarEstudiante(lista,&n,1);

    for(int i=0; i<n; i++) mostrarEstudiante(lista[i]);

    for(int i=0; i<n; i++) liberarEstudiante(lista[i]);
    free(lista);
    return 0;
}

