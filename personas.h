#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
#endif // PERSONAS_H_INCLUDED
#include <stddef.h>

typedef struct{
  // Array que contiene informacion, ya sea personas o lugar de nacimiento.
  char **array;
  // Largo de la array anterior.
  long largo;
} Datos;

// parser: const char* -> Datos*
// Lee el archivo pasado como parámetro y devuelve un array con las lineas leídas, y su longitud total. 
Datos *parser(const char *);

// escritura: FILE*, char*, int, char*
// Escribe la informacion de la persona en el archivo de salida
void escritura(FILE *, char*, int, char*);

// escSalida: Datos*, Datos*, const char, long
// Elige n (parámetro long) personas a construir, formatea la informacion
// y llama a 'escritura' para escribir la linea en el archivo de salida. 
void escSalida(Datos *, Datos *, const char *, long );

// freeDatos: Datos*
// Libera la memoria de la estructura (array y largo).
void freeDatos(Datos *);