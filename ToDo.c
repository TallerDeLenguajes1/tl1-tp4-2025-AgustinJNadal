#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct {
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
}typedef Tarea;

struct {
    Tarea Tarea;
    Nodo *Siguiente;
}typedef Nodo;

Nodo * CrearListaVacia();
Nodo * CrearNodo(int *id);


int main() {
    int id = 1000;
    Nodo * TareasPendientes = CrearListaVacia();
    Nodo * TareasRealizadas = CrearListaVacia();

    Nodo * NuevaTarea = CrearNodo(&id);

    return 0;
}

Nodo * CrearListaVacia(){
    return NULL;
}

Nodo * CrearNodo(int *id){
    Nodo * NuevaTarea = (Nodo *) malloc(sizeof(Nodo));
    
    NuevaTarea->Tarea.TareaID = (*id)++;

    char desc[100];
    printf("Ingrese descripcion: ");
    fflush(stdin);
    fgets(desc, 100, stdin);
    desc[strcspn(desc, "\n")] = 0;
    NuevaTarea->Tarea.Descripcion = (char *) malloc(strlen(desc) + 1);
    strcpy(NuevaTarea->Tarea.Descripcion, desc);

    do {
        printf("Ingrese la duracion (entre 10 y 100): ");
        scanf("%d", &NuevaTarea->Tarea.Duracion);
    } while (NuevaTarea->Tarea.Duracion < 10 || NuevaTarea->Tarea.Duracion > 100);

    
    NuevaTarea->Siguiente = NULL;
    
    return NuevaTarea;
}