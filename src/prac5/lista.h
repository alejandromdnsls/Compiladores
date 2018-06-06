#ifndef LISTA_H
#define LISTA_H

#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef struct Valor{
	int valor1;
	double valor2;
	char* valor3;
}Valor;

typedef struct elemento{
	char* name;
	int tipo;
	Valor valor;
}elemento;

//Estructura de un NODO SIMPLEMENTE LIGADO
typedef struct nodo
{
	elemento e;
	//Realación con el siguiente nodo
	struct nodo *siguiente;
} nodo;

//Se define una posicion como un apuntador a nodo
typedef nodo* posicion;

//Estructura de una lista
typedef struct lista
{
	int tamanio;
	posicion frente;
	posicion final;
}lista;


void Initialize (lista *l);

void Destroy (lista *l);

boolean Buscar(lista *l, elemento e);

posicion Search(lista *l, elemento e);

elemento*getElement(lista *l, posicion p);
elemento obtenerElemento(lista *l, posicion p);

boolean Empty(lista *l);

void Insert(lista *l,elemento e);

void MostrarNodos(lista *l);

void ImprimeTS(lista *l);

#endif
