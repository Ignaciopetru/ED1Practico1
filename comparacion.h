#include <stddef.h>
#ifndef COMPARACION_H_INCLUDED
#define COMPARACION_H_INCLUDED
#include "list.h"

typedef int (* Compara ) ( void * dato1 , void * dato2 ) ;

int comparacion_edad(Persona*, Persona*);

int comparacion_nombre(Persona*, Persona*);
#endif // COMPARACION_H_INCLUDED
