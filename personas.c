#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
//#include <locale.h>
#include "personas.h"

/*typedef struct
{
  // Array que contiene informacion, ya sea personas o lugar de nacimiento.
  char **array;
  // Largo de la array anterior.
  long largo;
} arrayDatos;
*/
arrayDatos *parser(const char *filename)
{
  int total_size = 200;
  arrayDatos *lista = (arrayDatos *)malloc(sizeof(arrayDatos));
  char **array = (char **)malloc(sizeof(char *) * total_size);
  FILE *fp;
  fp = fopen(filename, "r");
  int linea;
  for (linea = 0; !feof(fp); linea++)
  {
    char *buff = malloc(sizeof(char) * 256);
    // Read a line
    if (fscanf(fp, "%255[^\n]\n", buff) != EOF)
    {
      if (total_size == linea)
      {
        total_size *= 2;
        array = (char **)realloc(array, sizeof(char *) * total_size);
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

void escrituraSalida(arrayDatos *arrayNacimiento, arrayDatos *arrayPersonas, const char *filename, long cant)
{
  srand(time(NULL));
  FILE *fp;
  // Abrimios un archivo en modo escritura, sino existe se creara.
  fp = fopen(filename, "w");
  int i;
  for (i = 0; i < cant; i++)
  {
    int randPersona = rand() % arrayPersonas->largo;
    int randEdad = (rand() % 100) + 1;
    int randNacimiento = rand() % arrayNacimiento->largo;
    fprintf(fp, "%s, %d, %s\n", arrayPersonas->array[randPersona], randEdad, arrayNacimiento->array[randNacimiento]);
  }
  fclose(fp);
}

int main(int argc, char *argv[])
{
  arrayDatos *arrayNacimiento = parser("paises.txt");
  arrayDatos *arrayPersonas = parser("nombres1.txt");
  long cant = strtol(argv[1], NULL, 10);
  escrituraSalida(arrayNacimiento, arrayPersonas, "salida.txt", cant);
  return 0;
}
