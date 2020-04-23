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

DList dlist_split(DList primero) {
    DList fast = primero;
    DList slow = primero;
    while (fast->sig && fast->sig->sig)
    {
        fast = fast->sig->sig;
        slow = slow->sig;
    }
    DList temp = slow->sig;
    slow->sig = NULL;
    temp->ant = NULL;
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
  if (lista1 == NULL) {
    return lista2;
  }
  if (lista2 == NULL) {
    return lista1;
  }
  DList aux, aux2, aux3, aux4;
  aux = lista1;
  aux2 = lista2;
  while(aux != NULL && aux2 != NULL){
    if(c(aux->dato, aux2->dato)){
      aux4 = aux;
      aux = aux->sig;
    } else {
      aux3 = aux2->sig;
      if(aux->ant != NULL)
        aux->ant->sig = aux2;
      aux2->ant = aux->ant;
      aux2->sig = aux;
      aux->ant = aux2;
      aux2 = aux3;
    }

  }
    if(aux2 == NULL){
      return lista1;
    } else{
    aux4->sig = aux2;
    }
    return lista1;



}




DList dlist_mergeSort(DList *lista, Comparacion c) {
    if ((*lista) == NULL || (*lista)->sig == NULL)
      return;

    DList segundo = dlist_split(*lista);

    dlist_mergeSort(lista, c);

    dlist_mergeSort(&segundo, c);

    lista = dlist_merge(lista, &segundo, c);

    return lista;

}


void dlist_split(DNodo* primero, DNodo splitInicio , DNodo splitMedio) {
    DNodo* slow = primero;
    DNodo* fast = primero->sig;

    while (fast!=NULL) {
        fast = fast->sig;
        if (fast!=NULL) {
          slow = slow->sig;
          fast = fast->sig;
        }
    }
    splitMedio = slow->sig;
    slow->sig = NULL;
    //splitMedio->ant = NULL; ???
}


DNodo* dlist_mergeSortAux(DNodo* splitInicio, DNodo* splitMedio, Compara c) {
  if (splitInicio == NULL) {
    return splitMedio;
  }
  if (splitMedio == NULL) {
    return splitInicio;
  }
  if (c(splitInicio->dato, splitMedio->dato) == 0) {
    splitInicio->sig = dlist_mergeSortAux(splitInicio->sig, splitMedio, c);
    splitInicio->sig->ant = splitInicio;
    splitInicio->ant = NULL;

    return splitInicio;
  } else {
    splitMedio->sig = dlist_mergeSortAux(splitInicio, splitMedio->sig, c);
    splitMedio->sig->ant = splitMedio;
    splitMedio->ant = NULL;

    return splitMedio;
  }
}

 // Merge puto
 // Ver por que mergeSortAux no devuelve en orden o algo por el estilo
void dlist_mergeSortCall(DNodo** primero, Compara c){
  if (primero==NULL || (primero)->sig == NULL)
    return;

  DNodo* splitInicio = *primero, splitMedio;
  dlist_split(primero, &splitInicio, &splitMedio);

  dlist_mergeSortCall(&splitInicio, c);
  dlist_mergeSortCall(&splitMedio, c);

  *primero = dlist_mergeSortAux(splitInicio, splitMedio, c);
}

void dlist_mergeSort(DList lista, Compara c) {
  dlist_mergeSortCall(&lista.primero, c);
}
