#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"
#include "comparacion.h"

int main()
{

  DList hola = dlist_leer_crear("salida.txt");
  dlist_insertionSort(hola,comparacion_edad);
  dlist_mostrar(hola);
  printf("\n --------------\n");
  DList a = dlist_leer_crear("salida.txt");
  dlist_selectionSort(a,comparacion_nombre);
  dlist_mostrar(a);
  dlist_destruir(hola, persona_destruir);
  dlist_destruir(a, persona_destruir);
  return 0;
}

