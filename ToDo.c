#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void MostrarTareas(Tnodo * Pendientes);
Tnodo * QuitarTarea(Tnodo ** Pendientes);
void BuscarTareas(Tnodo * Pendientes, Tnodo * Realizadas);
void LiberarTarea(Tnodo * Pendientes);

int main() {
    int id = 1000;
    Tnodo * TareasPendientes = CrearListaVacia();
    Tnodo * TareasRealizadas = CrearListaVacia();
    int opcion; 

    do
    {
        puts("--- MENU ---");
        puts("1 - Agregar tarea pendiente");
        puts("2 - Marcar tarea como realizada");
        puts("3 - Mostrar tareas");
        puts("4 - Buscar tarea por ID o palabra clave");
        puts("0 - Salir");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
        {
        case 1:{
            Tnodo * NuevaTarea = CrearNodo(&id);
            InsertarTarea(&TareasPendientes, NuevaTarea);
            break;
        }
        case 2:{
            Tnodo * TareaMover = QuitarTarea(&TareasPendientes);
            if (TareaMover)
            {
                InsertarTarea(&TareasRealizadas, TareaMover);
                puts("Tarea movida con exito");
            }
            else
            {
                puts("Tarea no encontrada");
            }
            break;
        }        
        case 3:
            puts("--------Tareas Pendientes--------");
            MostrarTareas(TareasPendientes);
            puts("--------Tareas Realizadas--------");
            MostrarTareas(TareasRealizadas);
            break;       
        case 4:
            BuscarTareas(TareasPendientes, TareasRealizadas);
            break;      
        case 0:
            LiberarTarea(TareasPendientes);
            LiberarTarea(TareasRealizadas);
            puts("Fin");
            break;      
        default:
            puts("Opcion invalida");
            break;
        }
    } while (opcion != 0);

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

void MostrarTareas(Tnodo * Pendientes){
    Tnodo * Aux = Pendientes;
    while (Aux)
    {
        printf("ID: %d | Descripcion: %s | Duracion: %d\n", Aux->Tarea.TareaID, Aux->Tarea.Descripcion, Aux->Tarea.Duracion);
        Aux = Aux->Siguiente;
    }
}


Tnodo * QuitarTarea(Tnodo ** Pendientes){
    int idBuscar;
    printf("Ingrese ID de la tarea realizada: ");
    scanf("%d", &idBuscar);
    fflush(stdin);

    Tnodo * aux = *Pendientes;
    Tnodo * anterior = NULL;

    while (aux && aux->Tarea.TareaID != idBuscar) {
        anterior = aux;
        aux = aux->Siguiente;
    }
    if (anterior == NULL)
    {
        *Pendientes = aux->Siguiente;
    }
    else
    {
        anterior->Siguiente = aux->Siguiente;
    }
    aux->Siguiente = NULL;
    return aux;
}

void BuscarTareas(Tnodo * Pendientes, Tnodo * Realizadas){
    char palabra[15];
    printf("Ingrese ID o palabra a buscar: ");
    scanf("%s", palabra);

    int idBuscado = atoi(palabra);
    int bandera = 0;

    while (Pendientes) {
        if (Pendientes->Tarea.TareaID == idBuscado || strstr(Pendientes->Tarea.Descripcion, palabra)) {
            printf("PENDIENTE -> ID: %d | Duracion: %d | Descripcion: %s\n",
                Pendientes->Tarea.TareaID, Pendientes->Tarea.Duracion, Pendientes->Tarea.Descripcion);
                bandera = 1;
            }
        Pendientes = Pendientes->Siguiente;
    }
    while (Realizadas)
    {
        if (Realizadas->Tarea.TareaID == idBuscado || strstr(Realizadas->Tarea.Descripcion, palabra))
        {
            printf("REALIZADA -> ID: %d | Duracion: %d | Descripcion: %s\n",
                Realizadas->Tarea.TareaID, Realizadas->Tarea.Duracion, Realizadas->Tarea.Descripcion);
                bandera = 1;
            }
        Realizadas = Realizadas->Siguiente;
    }
    if (bandera == 0) {
        printf("No se encontraron tareas que coincidan.\n");
    }
}

void LiberarTarea(Tnodo * Pendientes){
    while (Pendientes)
    {
        Tnodo * aux = Pendientes;
        Pendientes = Pendientes->Siguiente;
        free(aux->Tarea.Descripcion);
        free(aux);
    }
}