#include <stdio.h>
#include <stdlib.h>

#include "lectura.h"
#include "list.h"

// Listas doblemente enlazadas


DList crearDList() {
  DList nueva;
  nueva.primero = NULL;
  return nueva;
}

DNodo* crearNodo(Persona* persona, DNodo*ant, DNodo*sig) {
  DNodo* nuevo = malloc(sizeof(DNodo));
  nuevo->ant = ant;
  nuevo->sig = sig;
  nuevo->dato = persona;
  return nuevo;
}

void agregarDNodo(DList* lista, Persona* persona) {

  if(lista->primero == NULL) {
    // Caso lista vacia.
    DNodo* nuevo = crearNodo(persona, NULL, NULL);
    lista->primero = nuevo;
  } else {
    // Caso lista con elementos.
    DNodo* nuevo = crearNodo(persona, NULL, lista->primero);
    lista->primero->ant = nuevo;
    lista->primero = nuevo;
  }

}

void mostrarDList(DList lista) {
  DNodo* Nsig = lista.primero;

  for(;Nsig != NULL; Nsig = Nsig->sig) {

    printf("%d\n", Nsig->dato->nombre);

  }
}

void destruirDList (DList lista){
  DNodo* proximo = lista.primero;
  DNodo* actual;
  for (; proximo != NULL ; ){
    actual = proximo;
    proximo = proximo->sig;
    //Antes de liberar el puntero al nodo, liberar el contenido del nodo, con funcion typedef void (* Destruir ) ( void * dato ) ;
    free (actual);
  }
}

void intercambiarDList(DNodo* a, DNodo* b){
  int c = b->dato;
  b->dato = a->dato;
  a->dato = c;
}
