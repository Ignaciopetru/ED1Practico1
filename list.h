#ifndef LIST_H_INLCUDED
#define LIST_H_INLCUDED

// Estructura que continene los datos de la persona.
 /*typedef struct _Persona {
  char* nombre;
  long edad;
  char* lugar;
} Persona;*/

// Estructura que representa un nodo en la lista enlazada,
// cuyo dato es una personta
typedef struct _DNodo {
  void* dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;

// Estructura que representa la lista, contiene el primer nodo.
typedef struct _DList{
  DNodo* primero;
} DList;

// Tipo de la funcion destruir, para cada tipo de dato sera distinta.
typedef void (*Visitante) (void *, void*);
//typedef void (*VisitanteImprimirArchivo) (FILE*, void *);

// Prototipos de funciones de manejo de la lista.

// dlist_crear devuleve la lista vacia.
DList dlist_crear();
// dlist_crear crea la estructura nodo, con los datos pasados en argumentos.
DNodo* dnodo_crear(void* , DNodo*, DNodo*);
// dnodo_crear agrega un nodo a la lista, con los datos determinados (persona).
void dnodo_agregar_inicio(DList*, void*);
// dnodo_agregar imprime los datos guardados en la lista.
void dlist_recorrer(DList, Visitante, void*);
// dlist_mostrar encargada de liberar la memoria reservada para la
// estructura Persona.
// dlist_destruir se encarga de liberar la memoria dedicada a la lista.
void dlist_destruir (DList, Visitante);
// dlist_intercambiar intercambia el dato de dos nodos de la estructura.
void dlist_intercambiar(DNodo*, DNodo*);
// dlist_split separa la lista doblemente enlazada en dos, devolviendo un
// puntero DNodo, el cual es el comienzo de la segunda.

/*
DNodo* dlist_split(DNodo*);
// dlist_merge une dos listas doblemente enlazadas
DNodo* dlist_merge(DNodo*, DNodo*);*/ // Merge no deberia tomar la funcion de comparacion


#endif
