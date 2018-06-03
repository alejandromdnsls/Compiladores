#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void Initialize (lista *l){
	l->frente=NULL;
	l->final=NULL;
	l->tamanio=0;
	return;
}

void Destroy (lista *l){
	//Apuntador auxiliar a nodo
	nodo *aux;

	while(l->frente != NULL){
		//Guardar la referencia el frente
		aux = l->frente;

		//El nuevo frente es el siguiente
		l->frente = l->frente->siguiente;

		//Liberar el antiguo frente de memoria
		free(aux);
	}

	//Colocar el final inicializado en "NULL"
	l->final = NULL;
	l->tamanio = 0;

	return;
}

boolean Buscar(lista *l, elemento e){
	posicion aux=l->frente;

	while(aux!=NULL){
		if(strcmp(aux->e.name, e.name)==0 && aux->e.tipo == e.tipo){
			//printf("entro\n");
			return TRUE;
		}
		aux=aux->siguiente;
	}
	return FALSE;
}

boolean Empty (lista *l){
	return (l->final==NULL&&l->frente==NULL&&l->tamanio==0) ? TRUE:FALSE;
}

void Insert(lista *l,elemento e)
{
	posicion aux;
	aux=malloc(sizeof(nodo));

	//Si no se puede reservar memoria para el nuevo nodo
	if(aux==NULL){
		printf("\nERROR: No se puede crear un nuevo nodo");
		exit(1);
	}

	//Agregar el elemento al nodo
	aux->e=e;

	//Si la lista esta vacia
	if(Empty(l)){
		aux->siguiente=NULL;
		l->frente=aux;
		l->final=aux;
	}
	//Si la lista no esta vacia
	else{
		l->final->siguiente=aux;
		aux->siguiente=NULL;
		l->final=aux;
	}
//Incrementar el tamaño de la lista
	l->tamanio++;
	return;
}

void MostrarNodos(lista *l){
	posicion aux;
	aux=l->frente;
	printf("\n********************************************************");
	while(aux!=NULL){
		printf("\nPosicion=%p\tSiguiente=%p",aux,aux->siguiente);
		aux=aux->siguiente;
	}
	printf("\n********************************************************\n");

	return;
}

void ImprimeTS(lista *l){
  posicion p;
  elemento e;
  int i;
  //Recorrer e imprimir los elementos
  p = l->frente; //Iniciamos por el primero de la lista
  printf("\n******************* Tabla de Simbolos ******************\n");
  for(i=0; p!=NULL; i++){
    e = p->e;

    if(e.tipo == 1){
			printf("\nElemento %d\n",i);
			printf("Nombre: %s, Tipo: %d, Valor: %d\n", e.name, e.tipo, e.valor.valor1);
		}
		else if(e.tipo == 2){
			printf("\nElemento %d\n",i);
			printf("Nombre: %s, Tipo: %d, Valor: %.2f\n", e.name, e.tipo, e.valor.valor2);
		}
		else if(e.tipo == 3){
			printf("\nElemento %d\n",i);
			printf("Nombre: %s, Tipo: %d, Valor: %s\n", e.name, e.tipo, e.valor.valor3);
		}
    p = p->siguiente;
  }
  MostrarNodos(l);
  return;
}
