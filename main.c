#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "datopersona.h"

typedef DList (*Sort) (DList, Comparacion);
// Achicar linea ->
void crear_archivo_salida(const char* filenameEntrada, const char* filenameSalida, Sort funcionSort, Comparacion funcionCompara) {
  // Variables usadas para calcular el timpo de ejecucion.
  clock_t start_t, end_t;
  // Creacion de la lista.
  DList lista = dlist_leer_crear(filenameEntrada);
  // Se establece el momento de inicio de ejecucion del algoritmo.
  start_t = clock();
  // Ejecucion del mismo.
  lista = funcionSort(lista, funcionCompara);
  //for(;lista->ant != NULL; lista = lista->ant);
  // Se establece el momento de fin de ejecucion del algoritmo.
  end_t = clock();
  // Se calcula el tiempo de ejecucion.
  double total = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  // Abrimos archivo.
  FILE* fp = fopen(filenameSalida, "w");
  // Impirmimos el contenido de la lista.
  dlist_recorrer(lista, (Visitante)persona_imprimir , fp);
  // Se cuenta el largo de la lista (tal vez innecesario).
  int * largoL = malloc(sizeof(int));
  *largoL = 0;
  dlist_recorrer(lista, (Visitante)contar_largo, largoL);
  fprintf(fp,"\nEl algoritmo tardo %f s en ordenar una lista de %d elementos", total, *largoL);
  fclose(fp);
  // Se libera memoria.
  dlist_destruir(lista, (Visitante) persona_destruir);
  free(largoL);
}

int main()
{
  crear_archivo_salida("personas.txt", "insertion1.txt", dlist_insertionSort, (Comparacion) comparacion_edad);
  return 0;
}

