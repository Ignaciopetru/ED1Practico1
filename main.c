#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "datopersona.h"
#include "stack.h"

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



int c(int*a, int*b){
  return (*a)<(*b);
}

  void a(int * h, void * a){
  printf("%d-", *h);
}

int main()
{

  crear_archivo_salida("salida.txt", "insertion.txt", dlist_mergeSort, (Comparacion) comparacion_edad);
/*
  int * h = malloc(sizeof(int));
  *h = 42;
  int * g = malloc(sizeof(int));
  *g = 19;
  int * f = malloc(sizeof(int));
  *f = 44;
   int * j = malloc(sizeof(int));
  *j = 39;
  int * k = malloc(sizeof(int));
  *k = 31;
  int * q = malloc(sizeof(int));
  *q = 5;
  int * r = malloc(sizeof(int));
  *r = 11;
  int * t = malloc(sizeof(int));
  *t = 88;
  int * z = malloc(sizeof(int));
  *z = 72;

  DList hola = dlist_crear();

  DList hola2 = dlist_crear();


  hola2 = dnodo_agregar_inicio(hola2, h);
  hola2 = dnodo_agregar_inicio(hola2, g);
  hola2 = dnodo_agregar_inicio(hola2, f);
  hola2 = dnodo_agregar_inicio(hola2, j);
  hola2 = dnodo_agregar_inicio(hola2, k);
  hola2 = dnodo_agregar_inicio(hola2, r);
  hola2 = dnodo_agregar_inicio(hola2, t);
  hola2 = dnodo_agregar_inicio(hola2, q);
  hola2 = dnodo_agregar_inicio(hola2, q);
  hola2 = dnodo_agregar_inicio(hola2, z);



  dlist_recorrer(hola2, a, NULL);
  printf("\n");


  hola2 = dlist_mergeSort(hola2,c);
  dlist_recorrer(hola2, a, NULL);
  printf("\n");
  printf("\n");
  printf("\n");
*/


  return 0;
}

