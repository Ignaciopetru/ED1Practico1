 #ifndef DLIST_H
 #define DLIST_H

typedef struct _DNodo {
  int dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;

typedef struct {
  DNodo* primero;
} DList;

DList crearDList();
DNodo* crearNodo(int, DNodo*, DNodo*);
void agregarDNodoFinal(DList*, int);
void mostrarDList(DList);
void destruirDList (DList);
void intercambiarDList(DNodo*, DNodo*);

 #endif
