#include <stdio.h>
#include <stdlib.h>
#include "DList.h"
#include "sort.h"


int main()
{

  DList hola = crearDList();
  agregarDNodoFinal(&hola, 10);
  agregarDNodoFinal(&hola, 2);
  agregarDNodoFinal(&hola, 3);
  agregarDNodoFinal(&hola, 11);

  mostrarDList(hola);
  printf("\n");
  insertionSortDList(hola, c);
  printf("\n");
  printf("\n");
  mostrarDList(hola);
  destruirDList(hola);
  return 0;
}

