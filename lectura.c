#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>

#include "list.h"
#include "lectura.h"

//const char *filename nombre archivo salida, debe ser tomado al ejecutar main
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

  nueva->nombre = nombre;
  nueva->edad = edadE;
  nueva->lugarDeNacimiendo = lugar;

  return nueva;

}

