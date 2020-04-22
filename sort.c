#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "comparacion.h"
#include "sort.h"


void dlist_selectionSort(DList lista, Compara c) {
  DNodo* nodo = lista;
  for (;nodo != NULL; nodo = nodo->sig) {
    DNodo* nodo2 = lista;
    for (;nodo2 != NULL; nodo2 = nodo2->sig) {
      if (c(nodo->dato, nodo2->dato) == 0) {
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

  for (nodo = lista->sig; nodo != NULL; nodo = nodo->sig) {
    datoG = nodo->dato;
    for (nodo2 = nodo->ant; nodo2 != NULL && (c(nodo2->dato, datoG) == 1); nodo2 = nodo2->ant) {
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

DNodo* dlist_mergeSortAux(DNodo* primero, DNodo* segundo, Compara c) {
  if (!primero) {
    return segundo;
  }
  if (!segundo) {
    return primero;
  }
  if (c(primero->dato, segundo->dato) == 0) {
    primero->sig = dlist_mergeSortAux(primero->sig, segundo, c);
    //primero->sig->ant = primero; //???????
    primero->ant = NULL;
    return primero;
  } else {
    segundo->sig = dlist_mergeSortAux(primero, segundo->sig, c);
    //segundo->sig->ant = segundo; //???????x2
    segundo->ant = NULL;
    return segundo;
  }
}
 // Merge puto
 // Ver por que mergeSortAux no devuelve en orden o algo por el estilo
void dlist_mergeSortCall(DNodo* primero, Compara c){
  if (primero && primero->sig) {
    //printf("Primero en esta iteracion: ");
    //DList hola;
    //hola.primero = primero;
    //dlist_recorrer(hola, persona_mostrar, NULL);
    DNodo* segundo = dlist_split(primero);
    //printf("Segundo en esta iteracion: ");
    //DList hola2;
    //hola2.primero = segundo;
    //dlist_recorrer(hola2, persona_mostrar, NULL);
    //printf("Fin de esta iteracion \n");
    dlist_mergeSortCall(primero, c);
    //printf("Aca comienza la recursion sobre la segunda");
    dlist_mergeSortCall(segundo, c);
    primero = dlist_mergeSortAux(primero, segundo, c);
    DList hola;
    //hola.primero = primero;
    printf("Comienza del print de la lista actual\n");
    dlist_recorrer(hola, persona_mostrar, NULL);
    printf("Fin del print de la lista actual\n");
  }
}

void dlist_mergeSort(DList lista, Compara c) {
 // dlist_mergeSortCall(lista.primero, c);
}
