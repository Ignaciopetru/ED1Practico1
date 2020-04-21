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

    printf("%s, %d, %s\n", Nsig->dato->nombre, Nsig->dato->edad, Nsig->dato->lugarDeNacimiendo);

  }
}

void destruirDList (DList lista){
  DNodo* proximo = lista.primero;
  DNodo* actual;
  for (; proximo != NULL ; ){
    actual = proximo;
    proximo = proximo->sig;
    //Antes de liberar el puntero al nodo, liberar el contenido del nodo, con funcion typedef void (* Destruir ) ( void * dato ) ;
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
  char* nombre = malloc(sizeof(char)*200);
  char edad[3];
  char* lugar = malloc(sizeof(char)*200);
  FILE* fp;
  fp = fopen(filename, "r");
  for(;!feof(fp);){
  // Se lee la linea y almacena segun corresponde
  fscanf(fp, "%200[^\,], %3[^\,], %200[^\n]\n", nombre, edad, lugar);
  // Se transforma la edad de char a int para poder ser trabajada
  int edadE = atoi(edad);
  // Se agrega el nodo a la lista

  agregarDNodo(&lista, crearPersona(nombre, edadE, lugar));
  }

  free(nombre);
  free(lugar);
  return lista;
}


Persona* crearPersona(char* nombre, int edadE, char* lugar){
  Persona* nueva = malloc(sizeof(Persona));
  nueva->nombre = malloc(sizeof(char)*200);
  strcpy(nueva->nombre, nombre);
  nueva->edad = edadE;
  nueva->lugarDeNacimiendo = malloc(sizeof(char)*200);
  strcpy(nueva->lugarDeNacimiendo, lugar);

  return nueva;

}
