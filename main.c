#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"
#include "comparacion.h"

int main()
{

  DList hola = lecturaYcreacionL("salida.txt");
  insertionSortDList(hola,comparacion_nombre);
  mostrarDList(hola);
  printf("\n --------------\n");
  DList a = lecturaYcreacionL("salida.txt");
  selectionSortDList(a,comparacion_nombre);
  mostrarDList(a);
  destruirDList(hola, d);
  destruirDList(a, d);
  return 0;
}

