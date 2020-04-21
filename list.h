#ifndef LIST_H_INLCUDED
#define LIST_H_INLCUDED

// Estructura que continene los datos de la persona.
 typedef struct _Persona {
  char* nombre;
  long edad;
  char* lugar;
} Persona;

// Estructura que representa un nodo en la lista enlazada,
// cuyo dato es una personta
typedef struct _DNodo {
  Persona* dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;

// Estructura que representa la lista, contiene el primer nodo.
typedef struct _DList{
  DNodo* primero;
} DList;

// Tipo de la funcion destruir, para cada tipo de dato sera distinta.
typedef void (*Destruir) (Persona*);

// Prototipos de funciones de manejo de la lista.

// dlist_crear devuleve la lista vacia.
DList dlist_crear();
// dlist_crear crea la estructura nodo, con los datos pasados en argumentos.
DNodo* dnodo_crear(Persona* , DNodo*, DNodo*);
// dnodo_crear agrega un nodo a la lista, con los datos determinados (persona).
void dnodo_agregar(DList*, Persona*);
// dnodo_agregar imprime los datos guardados en la lista.
void dlist_mostrar(DList);
// dlist_mostrar encargada de liberar la memoria reservada para la
// estructura Persona.
void persona_destruir(Persona *);
// dlist_destruir se encarga de liberar la memoria dedicada a la lista.
void dlist_destruir (DList, Destruir);
// dlist_intercambiar intercambia el dato de dos nodos de la estructura.
void dlist_intercambiar(DNodo*, DNodo*);
// dlist_leer_crear lee el archivo con las personas y devulve una lista con
// la informacion de las
DList dlist_leer_crear (const char *);
// persona_crear devulve una estructura Persona con los datos indicados.
Persona* persona_crear(char*, int, char*);

#endif
