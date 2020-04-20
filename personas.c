#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct
{
  // Array que contiene informacion, ya sea personas o lugar de nacimiento.
  char **array;
  // Largo de la array anterior.
  long largo;
} arrayDatos;

arrayDatos *parser(const char *fileName)
{
  int total_size = 200;
  arrayDatos *lista = (arrayDatos *)malloc(1, sizeof(arrayDatos));
  char **array = (char **)malloc(total_size * sizeof(char *));
  FILE *fp;
  fp = fopen(fileName, "r");
  char *buff = malloc(sizeof(char) * 256);
  int linea;
  for (linea = 0; !feof(fp); linea++)
  {
    // Read a line
    if (fscanf(fp, "%255[^\n]\n", buff) != EOF)
    {
      if (total_size == linea)
      {
        total_size *= 2;
        array = (char **)realloc(total_size * sizeof(char *));
      }
      // !char *temp = (char *)malloc(256, sizeof(char));
      // !temp = buff;
      // !temp[strlen(buff)] = '\0';
      // !array[linea] = temp;
      buff[strlen(buff)] = '\0';
      array[linea] = buff;
    }
  }
  fclose(fp);
  lista->array = array;
  lista->largo = linea;
  return lista;
}

int main()
{
  arrayDatos *arrayNacimiento = parser("paises.txt");
  arrayDatos *arrayPersonas = parser("nombres1.txt");
  return 0;
}
