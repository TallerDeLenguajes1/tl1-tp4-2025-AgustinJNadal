#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct {
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
}typedef Tarea;

typedef struct Tnodo{
    Tarea Tarea;
    struct Tnodo *Siguiente;
}Tnodo;

Tnodo * CrearListaVacia();
Tnodo * CrearNodo(int *id);
void InsertarTarea(Tnodo ** Pendientes, Tnodo * NuevaTarea);
void MostrarTareas(Tnodo * pendientes);


int main() {
    int id = 1000;
    Tnodo * TareasPendientes = CrearListaVacia();
    Tnodo * TareasRealizadas = CrearListaVacia();

    Tnodo * NuevaTarea = CrearNodo(&id);
    InsertarTarea(&TareasPendientes, NuevaTarea);
    MostrarTareas(TareasPendientes);
    MostrarTareas(TareasRealizadas);

    return 0;
}

Tnodo * CrearListaVacia(){
    return NULL;
}

Tnodo * CrearNodo(int *id){
    Tnodo * NuevaTarea = (Tnodo *) malloc(sizeof(Tnodo));
    
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

void InsertarTarea(Tnodo ** Pendientes, Tnodo * NuevaTarea){
    NuevaTarea->Siguiente = *Pendientes;
    *Pendientes = NuevaTarea;
}

void MostrarTareas(Tnodo * pendientes){
    Tnodo * Aux = pendientes;
    while (Aux)
    {
        puts("-------------------------");
        printf("ID: %d | Descripcion: %s | Duracion: %d\n", Aux->Tarea.TareaID, Aux->Tarea.Descripcion, Aux->Tarea.Duracion);
        Aux = Aux->Siguiente;
    }
}