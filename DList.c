#include <stdio.h>
#include <stdlib.h>
#include "DList.h"

// Listas doblemente enlazadas circulares



DList crearDList() {
  DList nueva;
  nueva.primero = NULL;
  return nueva;
}

DNodo* crearNodo(int dato, DNodo*ant, DNodo*sig) {
  DNodo* nuevo = malloc(sizeof(DNodo));
  nuevo->ant = ant;
  nuevo->sig = sig;
  nuevo->dato = dato;
  return nuevo;
}

void agregarDNodoFinal(DList* lista, int dato) {
  if(lista->primero == NULL) {
    DNodo* nuevo = crearNodo(dato, NULL, NULL);
    lista->primero = nuevo;
  } else {
    DNodo* Nsig = lista->primero;
    for(;Nsig->sig != NULL; Nsig = Nsig->sig);
    Nsig->sig = crearNodo(dato, Nsig, NULL);
  }
}

void mostrarDList(DList lista) {
  DNodo* Nsig = lista.primero;

  for(;Nsig != NULL; Nsig = Nsig->sig) {
    printf("%d\n", Nsig->dato);

  }
}

void destruirDList (DList lista){
  DNodo* iterador = lista.primero;
  DNodo* libertador;
  for (; iterador != NULL ; ){
    libertador = iterador;
    iterador = iterador->sig;
    free (libertador);
  }
}

void intercambiarDList(DNodo* a, DNodo* b){
  int c = b->dato;
  b->dato = a->dato;
  a->dato = c;
}
