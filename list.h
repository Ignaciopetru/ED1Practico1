#ifndef LIST_H_INLCUDED
#define LIST_H_INLCUDED


typedef struct _DNodo {
  Persona* dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;

typedef struct _DList{
  DNodo* primero;
} DList;

DList crearDList();
DNodo* crearNodo(Persona* , DNodo*, DNodo*);
void agregarDNodo(DList*, Persona*);
void mostrarDList(DList);
void destruirDList (DList);
void intercambiarDList(DNodo*, DNodo*);

#endif
