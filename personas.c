#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include "personas.h"

Datos* parser(const char* file) {
  int total_size = 200;
  Datos* lista = (Datos*)malloc(sizeof(Datos));
  char** array = (char**)malloc(sizeof(char*) * total_size);
  FILE* fp;
  fp = fopen(file, "r");
  int linea;
  for (linea = 0; !feof(fp); linea++) {
    char* buff = malloc(sizeof(char) * 256);
    if (fscanf(fp, "%255[^\n]\n", buff) != EOF) {
      if (total_size == linea) {
        total_size *= 2;
        array = (char**)realloc(array, sizeof(char*) * total_size);
      }
      buff[strlen(buff)] = '\0';
      array[linea] = buff;
    }
  }
  fclose(fp);
  lista->array = array;
  lista->largo = linea;
  return lista;
}

void escritura(FILE* fp, char* first, int second, char* third) {
  fprintf(fp, "%s, %d, %s\n", first, second, third);
}

void escSalida(Datos* datosNac, Datos* datosPer, const char* file, long cant) {
  srand(time(NULL));
  FILE* fp;
  fp = fopen(file, "w");
  int i;
  for (i = 0; i < cant; i++) {
    int ranPer = rand() % datosPer->largo;
    int ranEdad = (rand() % 100) + 1;
    int ranNac = rand() % datosNac->largo;
    escritura(fp, datosPer->array[ranPer], ranEdad, datosNac->array[ranNac]);
  }
  fclose(fp);
}

void freeDatos(Datos* array) {
  int i;
  for (i = 0; i < array->largo; i++)
    free(array->array[i]);
  free(array);
}

int main(int argc, char* argv[]) {
  Datos* datosNac = parser("datos/paises.txt");
  Datos* datosPer = parser("datos/nombres1.txt");
  long cant = strtol(argv[1], NULL, 10);
  escSalida(datosNac, datosPer, "salida.txt", cant);
  freeDatos(datosNac);
  freeDatos(datosPer);
  return 0;
}
