#include <stdio.h>
#include <stdlib.h>
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

srand(NULL);
Nodo * CrearTareas(Tarea Tarea) {
    Nodo * NodoTarea = (Nodo *)malloc(sizeof(Nodo));
    NodoTarea->Tarea.TareaID = ;
    char Descripcion[30];
    NodoTarea->Tarea.Descripcion = ;
    NodoTarea->Tarea.Duracion = 10 + rand() * 100 - 10 + 1;
    NodoTarea->Siguiente = NULL;
}


int main() {
    

    return 0;
}