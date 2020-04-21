#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"
#include "comparacion.h"
#include "lectura.h"

int main()
{
/*
  DList hola = crearDList();

  agregarDNodo(&hola,10);
  agregarDNodo(&hola, 3);
  agregarDNodo(&hola, 2);
  agregarDNodo(&hola, 11);

  mostrarDList(hola);
  printf("\n");
  insertionSortDList(hola, c);
  printf("\n");
  printf("\n");
  mostrarDList(hola);
  destruirDList(hola);*/
  DList hola = lecturaYcreacionL("salida.txt");
  mostrarList(hola);
  return 0;
}

