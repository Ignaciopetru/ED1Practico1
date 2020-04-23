#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct _DNodo {
  void* dato;
  struct _DNodo* sig, * ant;
};

DList dlist_crear() {
  return NULL;
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

DList dnodo_agregar_inicio(DList lista, void* dato) {
  if(lista == NULL) {
    // Caso lista vacia.
    DNodo* nuevo = dnodo_crear(dato, NULL, NULL);
    return nuevo;
  } else {
    // Caso lista con elementos.
    DNodo* nuevo = dnodo_crear(dato, NULL, lista);
    lista->ant = nuevo;
    return nuevo;
  }
}

// Agregado aux, para dar mas posibilidades a la funcion visitante
// (ejemplo: contar cantidad, imprimir en un archivo).
void dlist_recorrer(DList lista, Visitante visitante, void * aux) {
  DNodo* Nsig = lista;
  for (;Nsig != NULL; Nsig = Nsig->sig) {
    visitante(Nsig->dato, aux);
  }
}

void dlist_destruir (DList lista, Visitante liberar) {
  DNodo* proximo = lista;
  DNodo* actual;
  for (; proximo != NULL ; ) {
    actual = proximo;
    proximo = proximo->sig;
    liberar(actual->dato, NULL);
    free(actual);
  }
}

void dlist_intercambiar(DNodo* nodoA, DNodo* nodoB) {
  void* nodoC = nodoB->dato;
  nodoB->dato = nodoA->dato;
  nodoA->dato = nodoC;
}

DNodo* dlist_split(DNodo* primero) {
    DNodo* fast = primero;
    DNodo* slow = primero;
    while (fast->sig && fast->sig->sig)
    {
        fast = fast->sig->sig;
        slow = slow->sig;
    }
    DNodo* temp = slow->sig;
    slow->sig = NULL;
    return temp;
}

void dlist_selectionSort(DList lista, Comparacion c) {
  DNodo* nodo = lista;
  for (;nodo != NULL; nodo = nodo->sig) {
    DNodo* nodo2 = lista;
    for (;nodo2 != NULL; nodo2 = nodo2->sig) {
      if (c(nodo->dato, nodo2->dato)) {
        dlist_intercambiar(nodo, nodo2);
      }
    }
  }
}

void dlist_insertionSort(DList lista, Comparacion c) {
  DNodo* nodo, * nodo2, * aux;

  void* datoG;
  int entro = 0;

  for (nodo = lista->sig; nodo != NULL; nodo = nodo->sig) {
    datoG = nodo->dato;
    for (nodo2 = nodo->ant; nodo2 != NULL && !(c(nodo2->dato, datoG)); nodo2 = nodo2->ant) {
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


DList dlist_merge(DList lista1, DList lista2, Comparacion c){
  if (!lista1) {
    return lista2;
  }
  if (!lista2) {
    return lista1;
  }
  DList aux, aux2, aux3, aux4;
  aux = lista1;
  aux2 = lista2;
  while(aux->sig != NULL && aux2 != NULL){
    if(c(aux->dato, aux2->dato)){
      aux = aux->sig;
    } else {
      aux3 = aux2->sig;
      aux->ant->sig = aux2;
      aux2->ant = aux->ant;
      aux2->sig = aux;
      aux->ant = aux2;

      aux2 = aux3;

    }
  }
  if(aux2 == NULL){
    return lista1;
  } else {
    // Para no tener que buscar otra vez el final de lista1

    if(c(aux->dato, aux2->dato)){
      aux = aux->sig;
    } else {
      aux3 = aux2->sig;
      aux->ant->sig = aux2;
      aux2->ant = aux->ant;
      aux2->sig = aux;
      aux->ant = aux2;

      aux2 = aux3;

    }
    aux->sig = aux2;
    return lista1;
  }


}


void dlist_mergeSort(DList lista, Comparacion c){
  if(lista == NULL)
    return;


}

/*
DNodo* dlist_mergeSortAux(DNodo* primero, DNodo* segundo, Comparacion c) {
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
void dlist_mergeSortCall(DNodo* primero, Comparacion c){
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
    //dlist_recorrer(hola, persona_mostrar, NULL);
    printf("Fin del print de la lista actual\n");
  }
}

void dlist_mergeSort(DList lista, Comparacion c) {
 // dlist_mergeSortCall(lista.primero, c);
}*/

