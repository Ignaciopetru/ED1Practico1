#include <stdio.h>
#include <stdlib.h>

#include "list.h"

DList dlist_crear() {
  DList nueva;
  nueva.primero = NULL;
  return nueva;
}

DNodo* dnodo_crear(void* dato, DNodo*ant, DNodo*sig) {
  // se pide memoria para la estructura nodo.
  DNodo* nuevo = malloc(sizeof(DNodo));
  // se establecen las variables.
  nuevo->ant = ant;
  nuevo->sig = sig;
  nuevo->dato = dato;
  return nuevo;
}

void dnodo_agregar_inicio(DList* lista, void* dato) {
  if(lista->primero == NULL) {
    // Caso lista vacia.
    DNodo* nuevo = dnodo_crear(dato, NULL, NULL);
    lista->primero = nuevo;
  } else {
    // Caso lista con elementos.
    DNodo* nuevo = dnodo_crear(dato, NULL, lista->primero);
    lista->primero->ant = nuevo;
    lista->primero = nuevo;
  }
}

// Agregado aux, para dar mas posibilidades a la funcion visitante
// (ejemplo: contar cantidad, imprimir en un archivo).
void dlist_recorrer(DList lista, Visitante visitante, void * aux) {
  DNodo* Nsig = lista.primero;
  for (;Nsig != NULL; Nsig = Nsig->sig) {
    visitante(Nsig->dato, aux);
  }
}

void dlist_destruir (DList lista, Visitante liberar) {
  DNodo* proximo = lista.primero;
  DNodo* actual;
  for (; proximo != NULL ; ) {
    actual = proximo;
    proximo = proximo->sig;
    liberar(actual->dato, NULL);
    free(actual);
  }
}

// Ver si esta es la forma correcta!
void dlist_intercambiar(DNodo* a, DNodo* b) {
  void* c = b->dato;
  b->dato = a->dato;
  a->dato = c;
}

