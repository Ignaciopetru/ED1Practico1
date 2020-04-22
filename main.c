#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "sort.h"
#include "comparacion.h"
#include "datopersona.h"

typedef void (*Sort) (DList, Compara);

void crear_archivo_salida(const char* filenameEntrada, const char* filenameSalida, Sort funcionSort, Compara funcionCompara) {
  clock_t start_t, end_t, total_t;

  DList lista = dlist_leer_crear(filenameEntrada);
  start_t = clock();
  funcionSort(lista, funcionCompara);
  end_t = clock();
  double total = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  FILE* fp;
  fp = fopen(filenameSalida, "w");
  dlist_recorrer(lista, persona_imprimir, fp);
  int * largoL = malloc(sizeof(int));
  dlist_recorrer(lista, contar_largo, largoL);
  fprintf(fp,"\nEl algoritmo tardo %f s en ordenar una lista de %d elementos", total, *largoL);
  fclose(fp);
  free(largoL);

}

int main()
{
  crear_archivo_salida("salida.txt", "insertion.txt", dlist_insertionSort, comparacion_edad);
  return 0;
}

