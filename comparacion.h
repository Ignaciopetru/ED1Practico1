#include <stddef.h>
#ifndef COMPARACION_H_INCLUDED
#define COMPARACION_H_INCLUDED
#include "list.h"
#include "datopersona.h"

// Tipo de la funcion que toman los métodos de sort para ordenar
typedef int (*Compara) (Persona*, Persona*);

// comparacion_edad: Persona*, Persona* -> int
// Método de comparación para ordenar las personas según su edad
int comparacion_edad(Persona*, Persona*);

// comparacion_edad: Persona*, Persona* -> int
// Método de comparación para ordenar las personas según su nombre
int comparacion_nombre(Persona*, Persona*);
#endif // COMPARACION_H_INCLUDED
