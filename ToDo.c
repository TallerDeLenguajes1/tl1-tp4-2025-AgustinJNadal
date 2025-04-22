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

int main() {
    Nodo * TareasPendientes = CrearListaVacia();
    Nodo * TareasRealizadas = CrearListaVacia();
    return 0;
}

Nodo * CrearListaVacia(){
    return NULL;
}