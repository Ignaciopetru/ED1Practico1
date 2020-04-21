#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "comparacion.h"
#include "sort.h"


DList selectionSortDList(DList lista, Compara c){
  DNodo* nodo = lista.primero;
  for(;nodo != NULL; nodo = nodo->sig){
    DNodo* nodo2 = lista.primero;
    for(;nodo2 != NULL; nodo2 = nodo2->sig){
      if(c(&nodo->dato, &nodo2->dato) == 1){
        intercambiarDList(nodo, nodo2);
      }
    }
  }
}

DList insertionSortDList(DList lista, Compara c){
  DNodo* nodo;
  DNodo* nodo2;
  DNodo* aux;
  int datoG, entro = 0;

  for(nodo = lista.primero->sig;nodo != NULL; nodo = nodo->sig){
    datoG = nodo->dato;
    for(nodo2 = nodo->ant; nodo2 != NULL && (c(&nodo2->dato, &datoG)==0); nodo2 = nodo2->ant){
      nodo2->sig->dato = nodo2->dato;
      aux = nodo2;
      entro = 1;
    }if(entro == 1){
      aux->dato = datoG;
      entro = 0;
    }
    else
      nodo2->sig->dato = datoG;
  }
}

// Falta mergeSortDlist


