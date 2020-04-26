all: master personas

master: list.o datopersona.o main.c
	gcc -o master main.c list.o datopersona.o

datopersona.o: list.h datopersona.h datopersona.c
	gcc -c datopersona.c

list.o: list.c list.h
	gcc -c list.c

personas: personas.c personas.h
	gcc -o personas personas.c

clean:
	rm *.o
