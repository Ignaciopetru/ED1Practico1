#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "datopersona.h"

typedef void (*Sort) (DList, Comparacion);
// Achicar linea ->
void crear_archivo_salida(const char* filenameEntrada, const char* filenameSalida, Sort funcionSort, Comparacion funcionCompara) {
  // Variables usadas para calcular el timpo de ejecucion.
  clock_t start_t, end_t;
  // Creacion de la lista.
  DList lista = dlist_leer_crear(filenameEntrada);
  // Se establece el momento de inicio de ejecucion del algoritmo.
  start_t = clock();
  // Ejecucion del mismo.
  funcionSort(lista, funcionCompara);
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


void a(int * h, void * a){
  printf("%d", *h);
}
int c(int*a, int*b){
  return *a<*b;
}

int main()
{

  //crear_archivo_salida("salida.txt", "insertion.txt", dlist_mergeSort, (Comparacion) comparacion_edad);

DList hola = dlist_crear();

  DList hola2 = dlist_crear();
  int * h = malloc(sizeof(int));
  int * g = malloc(sizeof(int));
  int * f = malloc(sizeof(int));
  int * j = malloc(sizeof(int));
  *h = 0;
  *g = 1;
  *f = 5;
  *j = 3;
  hola = dnodo_agregar_inicio(hola, h);
  hola = dnodo_agregar_inicio(hola, g);
  hola = dnodo_agregar_inicio(hola, f);
  hola = dnodo_agregar_inicio(hola, j);
  dlist_recorrer(hola, a, NULL);
  printf("\n");
  //dlist_recorrer(hola2, a, NULL);
  printf("\n");

  //hola = dlist_merge(hola, hola2, c);
  DList * ac = dlist_mergeSort(&hola, c);
  dlist_recorrer(*ac, a, NULL);
  return 0;
}

