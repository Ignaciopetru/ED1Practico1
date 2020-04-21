#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comparacion.h"

int c (int* a, int* b){
  if(*a < *b)
    return 1;
  else
    return 0;
}
/*
int comparacion_edad(Persona *persona1, Persona *persona2)
{
  if (persona1->edad <= persona2->edad)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

int comparacion_nombre(Persona *persona1, Persona *persona2)
{
  if (strcmp(persona1->nombre, persona2->nombre) <= 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
*/
