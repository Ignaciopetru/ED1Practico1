#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED
#endif // PERSONAS_H_INCLUDED
#include <stddef.h>

typedef struct
{
  // Array que contiene informacion, ya sea personas o lugar de nacimiento.
  char **array;
  // Largo de la array anterior.
  long largo;
} arrayDatos;

arrayDatos *parser(const char *);

void escrituraSalida(arrayDatos *, arrayDatos *, const char *, long );

