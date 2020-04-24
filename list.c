#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

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



  void a1(int * h, void * a){
  printf("%d", *h);
}

void contar_largo(DList lista, int * largo) {
  (*largo)++;
}

DList dlist_merge(DList lista1, DList lista2, Comparacion c){
  if (lista1 == NULL) {
    return lista2;
  }
  if (lista2 == NULL) {
    return lista1;
  }
  DList punteroAlInicio = lista1, lista2Aux, lista1Aux;
  lista1Aux = lista1;
  while (lista1 != NULL && lista2 != NULL) {
    if (c(lista1->dato, lista2->dato)) {
      lista1 = lista1->sig;
    } else {
      lista2Aux = lista2->sig;
      if (lista1->ant == NULL)
        punteroAlInicio = lista2;
      lista2->ant = lista1->ant;
      lista2->sig = lista1;
      if (lista1->ant != NULL)
        lista1->ant->sig = lista2;
      lista1->ant = lista2;
      lista2 = lista2Aux;
    }
  }

  if (lista2 != NULL) {
    // Se debe arreglarrrr para que no recorra otra vez la lista1
    for (;lista1Aux->sig != NULL; lista1Aux = lista1Aux->sig);
    lista1Aux->sig = lista2;
    lista2->ant = lista1Aux;
    return punteroAlInicio;
  } else {
    return punteroAlInicio;
  }

}


DList dlist_mergeSort(DList lista, Comparacion c){
  // El calculo del largo tal vez se tendria que incluir en la lista.
  int* largoP = malloc(sizeof(int));
  dlist_recorrer(lista, contar_largo, largoP);
  int largo = *largoP;
  //------------------
  Stack stack = stack_new(largo);
  Stack stackOrdenadas = stack_new(largo);
  stack_push(stack, lista);
  // Primera etapa, colocar en stackOrdenadas listas ordenadas.
  while (stack_isEmpty(stack) == 0) {
    DList primero = stack_top(stack);
    stack_pop(stack);
    if (primero->sig == NULL) {
      if (stack_isEmpty(stack) == 1) {
        stack_push(stackOrdenadas, primero);
      } else {
        DList segundo = stack_top(stack);
        stack_pop(stack);
        if (segundo->sig == NULL) {
          primero = dlist_merge(primero, segundo, c);
          stack_push(stackOrdenadas, primero);
        } else {
          DList mitad = dlist_split(segundo);
          stack_push(stack, segundo);
          stack_push(stack, mitad);
          stack_push(stack, primero);
        }
      }
    } else {
      DList mitad = dlist_split(primero);
      stack_push(stack, mitad);
      stack_push(stack, primero);
    }
  }



  // Segunda etapa junatar las listas ordenadas.
  while (!(stack_isEmpty(stack) && stack_unoSolo(stackOrdenadas)) && !(stack_isEmpty(stackOrdenadas) && stack_unoSolo(stack))) {
      while (!stack_isEmpty(stackOrdenadas)) {
        if (stack_unoSolo(stackOrdenadas)) {
          DList primer2 = stack_top(stackOrdenadas);

          stack_push(stack, primer2);
          stack_pop(stackOrdenadas);
        } else {
          DList primer = stack_top(stackOrdenadas);
          stack_pop(stackOrdenadas);

          DList segun = stack_top(stackOrdenadas);
          stack_pop(stackOrdenadas);

          primer =  dlist_merge(primer,segun, c);

          stack_push(stack, primer);
        }
      }

      while (!stack_isEmpty(stack)) {
        if (stack_unoSolo(stack)) {
          stack_push(stackOrdenadas, stack_top(stack));
          stack_pop(stack);
        } else {
          DList primerS = stack_top(stack);
          stack_pop(stack);

          DList segunS = stack_top(stack);
          stack_pop(stack);

          DList primerSs =  dlist_merge(primerS,segunS, c);

          stack_push(stackOrdenadas, primerSs);
        }
      }
  }
  DList result;
  if (stack_isEmpty(stack))
    result = stack_top(stackOrdenadas);
  if (stack_isEmpty(stackOrdenadas))
    result = stack_top(stack);
  stack_destruir(stack);
  stack_destruir(stackOrdenadas);
  return result;

}




