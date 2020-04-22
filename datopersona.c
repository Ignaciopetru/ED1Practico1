#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "datopersona.h"


Persona* persona_crear(char* nombre, int edadE, char* lugar) {
  Persona* nueva = malloc(sizeof(Persona));
  nueva->nombre = nombre;
  nueva->edad = edadE;
  nueva->lugar = lugar;
  return nueva;
}

void persona_destruir(Persona * persona, void * aux) {
  free(persona->nombre);
  free(persona->lugar);
  free(persona);
}

void contar_largo(Persona* persona, int * largo) {
  (*largo)++;
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

  dnodo_agregar_inicio(&lista, persona_crear(nombre, edadE, lugar));
  }
  free(edad);
  return lista;
}

void persona_mostrar(Persona * persona, FILE * fp){
  fprintf(fp, "%s, %ld, %s\n",persona->nombre, persona->edad, persona->lugar);
}
