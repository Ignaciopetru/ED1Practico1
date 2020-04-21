#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Listas doblemente enlazadas


DList crearDList() {
  DList nueva;
  nueva.primero = NULL;
  return nueva;
}

DNodo* crearNodo(Persona* persona, DNodo*ant, DNodo*sig) {
  DNodo* nuevo = malloc(sizeof(DNodo));
  nuevo->ant = ant;
  nuevo->sig = sig;
  nuevo->dato = persona;
  return nuevo;
}

void agregarDNodo(DList* lista, Persona* persona) {

  if(lista->primero == NULL) {
    // Caso lista vacia.
    DNodo* nuevo = crearNodo(persona, NULL, NULL);
    lista->primero = nuevo;
  } else {
    // Caso lista con elementos.
    DNodo* nuevo = crearNodo(persona, NULL, lista->primero);
    lista->primero->ant = nuevo;
    lista->primero = nuevo;
  }

}

void mostrarDList(DList lista) {
  DNodo* Nsig = lista.primero;

  for(;Nsig != NULL; Nsig = Nsig->sig) {

    printf("%s, %ld, %s\n", Nsig->dato->nombre, Nsig->dato->edad, Nsig->dato->lugarDeNacimiendo);

  }
}

void d(Persona * persona){
  free(persona->nombre);
  free(persona->lugarDeNacimiendo);
  free(persona);
}

void destruirDList (DList lista, Destruir d){
  DNodo* proximo = lista.primero;
  DNodo* actual;
  for (; proximo != NULL ; ){
    actual = proximo;
    proximo = proximo->sig;
    d(actual->dato);
    free (actual);
  }
}

void intercambiarDList(DNodo* a, DNodo* b){
  Persona * c = b->dato;
  b->dato = a->dato;
  a->dato = c;
}

DList lecturaYcreacionL (const char *filename){
  DList lista = crearDList();

  char* edad = malloc(sizeof(char)*3);

  FILE* fp;
  fp = fopen(filename, "r");
  for(;!feof(fp);){
  char* nombre = malloc(sizeof(char)*200);
  char* lugar = malloc(sizeof(char)*200);
  // Se lee la linea y almacena segun corresponde
  fscanf(fp, "%200[^,], %3[^,], %200[^\n]\n", nombre, edad, lugar);
  // Se transforma la edad de char a int para poder ser trabajada
  long edadE = strtol(edad, NULL, 10);
  // Se agrega el nodo a la lista

  agregarDNodo(&lista, crearPersona(nombre, edadE, lugar));
  }
  free(edad);
  return lista;
}


Persona* crearPersona(char* nombre, int edadE, char* lugar){
  Persona* nueva = malloc(sizeof(Persona));

  nueva->nombre = nombre;
  nueva->edad = edadE;
  nueva->lugarDeNacimiendo = lugar;

  return nueva;

}
