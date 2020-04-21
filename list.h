#ifndef LIST_H_INLCUDED
#define LIST_H_INLCUDED

 typedef struct _persona {
  char* nombre;
  long edad;
  char* lugarDeNacimiendo;
} Persona;

typedef struct _DNodo {
  Persona* dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;


typedef struct _DList{
  DNodo* primero;
} DList;

typedef void (* Destruir ) ( Persona * dato ) ;

DList crearDList();
DNodo* crearNodo(Persona* , DNodo*, DNodo*);
void agregarDNodo(DList*, Persona*);
void mostrarDList(DList);
void d(Persona *);
void destruirDList (DList, Destruir);
void intercambiarDList(DNodo*, DNodo*);


DList lecturaYcreacionL (const char *);
Persona* crearPersona(char*, int, char*);

#endif
