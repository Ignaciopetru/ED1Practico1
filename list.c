#include <stdio.h>
#include <stdlib.h>

#include "list.h"

DList dlist_crear() {
  DList nueva;
  nueva.primero = NULL;
  return nueva;
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

void dnodo_agregar(DList* lista, void* dato) {
  if(lista->primero == NULL) {
    // Caso lista vacia.
    DNodo* nuevo = dnodo_crear(dato, NULL, NULL);
    lista->primero = nuevo;
  } else {
    // Caso lista con elementos.
    DNodo* nuevo = dnodo_crear(dato, NULL, lista->primero);
    lista->primero->ant = nuevo;
    lista->primero = nuevo;
  }
}

void m(Persona * persona){
  printf("%s, %ld, %s\n",persona->nombre, persona->edad, persona->lugar);
}

void dlist_mostrar(DList lista, Mostrar m) {
  DNodo* Nsig = lista.primero;
  for(;Nsig != NULL; Nsig = Nsig->sig) {
    m(Nsig->dato);
    //printf("%s, %ld, %s\n", Nsig->dato->nombre, Nsig->dato->edad, Nsig->dato->lugar);
  }
}



void persona_destruir(Persona * persona) {
  free(persona->nombre);
  free(persona->lugar);
  free(persona);
}

void dlist_destruir (DList lista, Destruir d) {
  DNodo* proximo = lista.primero;
  DNodo* actual;
  for (; proximo != NULL ; ) {
    actual = proximo;
    proximo = proximo->sig;
    d(actual->dato);
    free(actual);
  }
}

void dlist_intercambiar(DNodo* a, DNodo* b) {
  Persona* c = b->dato;
  b->dato = a->dato;
  a->dato = c;
}

DList dlist_leer_crear(const char* filename) {
  DList lista = dlist_crear();

  char* edad = malloc(sizeof(char)*3);

  FILE* fp;
  fp = fopen(filename, "r");
  for (;!feof(fp);) {
  char* nombre = malloc(sizeof(char)*200);
  char* lugar = malloc(sizeof(char)*200);
  // Se lee la linea y almacena segun corresponde
  fscanf(fp, "%200[^,], %3[^,], %200[^\n]\n", nombre, edad, lugar);
  // Se transforma la edad de char a int para poder ser trabajada
  long edadE = strtol(edad, NULL, 10);
  // Se agrega el nodo a la lista

  dnodo_agregar(&lista, persona_crear(nombre, edadE, lugar));
  }
  free(edad);
  return lista;
}


Persona* persona_crear(char* nombre, int edadE, char* lugar) {
  Persona* nueva = malloc(sizeof(Persona));
  nueva->nombre = nombre;
  nueva->edad = edadE;
  nueva->lugar = lugar;
  return nueva;
}
