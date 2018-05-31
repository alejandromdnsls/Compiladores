#include<stdio.h>
#include "TADListaSL.h"

//Función para imprimir el elemento de la lista con base en mi estructura elemento
void ImprimeLista(lista *l);

//PROGRAMA PRINCIPAL
int main (void)
{
	lista TablaSimbolos; //Tabla Simbolos
	posicion aux;	//Posición auxiliar para manejar la lista
	elemento e;		//Elemento e

	Initialize(&TablaSimbolos); //Inicializar la lista

	e.name = "var1";
	e.tipo = 1;
	e.valor.valor1 = 5;

	Add(&TablaSimbolos, e);

	e.name = "var2";
	e.tipo = 2;
	e.valor.valor2 = 9.8;

	Add(&TablaSimbolos, e);

	e.name = "var2";
	e.tipo = 1;
	e.valor.valor1 = 4;

  //ImprimeLista(&TablaSimbolos);

	if(Buscar(&TablaSimbolos,e)){
		printf("Se encontró el elemeto\n");
	}
	else{
		Add(&TablaSimbolos, e);
		printf("Se agregó\n");
	}

	e.name = "var5";
	e.tipo = 1;
	e.valor.valor1 = 4;

	Add(&TablaSimbolos, e);


	ImprimeLista(&TablaSimbolos);

  VerLigasLista(&TablaSimbolos);
	ImprimeLista(&TablaSimbolos);

	return 0;
}


//Función para imprimir el elemento de la lista con base en mi estructura elemento
void ImprimeLista(lista *l)
{
	posicion p;
	elemento e;
	int i;

	//Recorrer e imprimir los elementos mientras se tenga una posición valida
	p=First(l);		//Iniciamos por el primero de la lista

	//Mientras la posición sea valida
	for(i=1;ValidatePosition(l,p);i++)
	{
		e=Position(l,p);

		if(e.tipo == 1){
			printf("\nVariable %d\n",i);
			printf("Nombre: %s, Tipo: %d, Valor: %d\n", e.name, e.tipo, e.valor.valor1);
		}
		else if(e.tipo == 2){
			printf("\nVariable %d\n",i);
			printf("Nombre: %s, Tipo: %d, Valor: %.2f\n", e.name, e.tipo, e.valor.valor2);
		}
		else if(e.tipo == 3){
			printf("\nVariable %d\n",i);
			printf("Nombre: %s, Tipo: %d, Valor: %s\n", e.name, e.tipo, e.valor.valor3);
		}
		p=Following(l,p);
	}
	return;
}
