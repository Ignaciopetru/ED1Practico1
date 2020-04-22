#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "comparacion.h"

// dlist_selectionSort: implementacion del algoritmo selection sort
// en listas doblemente enlazadas.
void dlist_selectionSort(DList, Compara);

// dlist_insertionSort: implementacion del algoritmo insertion sort
// en listas doblemente enlazadas.
void dlist_insertionSort(DList, Compara);

DNodo* dlist_mergeSortAux(DNodo* , DNodo* , Compara);

// dlist_mergeSortCall: 
void dlist_mergeSortCall(DNodo*, Compara); 

// dlist_mergeSort: implementacion del algoritmo merge sort en listas
// doblemente enlazadas, el cual se ejecuta en la funcion auxiliar
// debido a la necesidad de ser llamada de forma recursiva.
void dlist_mergeSort(DList, Compara);



#endif
