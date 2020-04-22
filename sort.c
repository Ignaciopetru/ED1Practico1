#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "comparacion.h"
#include "sort.h"


void dlist_selectionSort(DList lista, Compara c) {
  DNodo* nodo = lista.primero;
  for (;nodo != NULL; nodo = nodo->sig) {
    DNodo* nodo2 = lista.primero;
    for (;nodo2 != NULL; nodo2 = nodo2->sig) {
      if (c(nodo->dato, nodo2->dato) == 1) {
        dlist_intercambiar(nodo, nodo2);
      }
    }
  }
}

void dlist_insertionSort(DList lista, Compara c) {
  DNodo* nodo;
  DNodo* nodo2;
  DNodo* aux;
  Persona* datoG;
  int entro = 0;

  for (nodo = lista.primero->sig; nodo != NULL; nodo = nodo->sig) {
    datoG = nodo->dato;
    for (nodo2 = nodo->ant; nodo2 != NULL && (c(nodo2->dato, datoG) == 0); nodo2 = nodo2->ant) {
      nodo2->sig->dato = nodo2->dato;
      aux = nodo2;
      entro = 1;
    }
    if (entro == 1) {
      aux->dato = datoG;
      entro = 0;
    } else
      nodo2->sig->dato = datoG;
  }
}

void dlist_mergeSort(DList lista, Compara c) {
  DNodo* primera = lista.primero;
  if (primera && primera->sig) {
    DNodo* segunda = dlist_split(lista.primero);
    dlist_mergeSort(primera); // Tengo que ver como hacer para hacer
    dlist_mergeSort(segunda); // funcionar esto con nodos
    lista.primero = dlist_merge(primera, segunda)
  }
  
}
// Cambios:
  // Creo dlist_split y dlist_merge, hay que ver si
  // hay que hacerlas void o dejarlas como estan 


