%{
#include <stdio.h>
#include <math.h>
#include "op_cadenas.h"
#include "TADListaSL.h"
int yylex(void);
void yyerror(char *);
void ImprimeLista(lista *l);
lista ts;
%}

/* Declaraciones de BISON */

%union{  /* especifica la colección completa de tipo de datos posibles */
  int entero;
  double flotante;
  char* str;
  /*Valor* valor;*/
}

%token <entero> ENTERO /* terminal, define el token y su tipo */
%token <flotante> REAL
%token <str> CADENA
%token <str> ID
%token POW
%token INT
%token DOUBLE
%token STRING
%type <entero> exp_e /* no terminal */
%type <flotante> exp_f
%type <str> exp_c

%left '='
%left '+''-'
%left '*''/'

/* Gramática */
%%

input:    /* cadena vacía */
        | input line
;

line:     '\n'
        | exp_e '\n' { printf("\tresultado: %d\n", $1); }
        | exp_f '\n' { printf("\tresultado: %.2f\n", $1); }
        | exp_c '\n' { printf("\tresultado: %s\n", $1); }
        | decl '\n'
;

exp_e:  ENTERO { $$ = $1; }
        | '-' ENTERO { $$ = ($2)*(-1); }
        | exp_e '+' exp_e { $$ = $1 + $3; }
        | exp_e '-' exp_e { $$ = $1 - $3; }
        | exp_e '*' exp_e { $$ = $1 * $3; }
        | exp_e '/' exp_e { $$ = $1 / $3; }
        | POW '(' exp_e ',' exp_e ')' ';' { $$ = pow($3,$5); }
;

exp_f:  REAL { $$ = $1; }
        | exp_f '+' exp_f { $$ = $1 + $3; }
        | exp_f '-' exp_f { $$ = $1 - $3; }
        | exp_f '*' exp_f { $$ = $1 * $3; }
        | exp_f '/' exp_f { $$ = $1 / $3; }
        | exp_e '+' exp_f { $$ = $1 + $3; }
        | exp_e '-' exp_f { $$ = $1 - $3; }
        | exp_e '*' exp_f { $$ = $1 * $3; }
        | exp_e '/' exp_f { $$ = $1 / $3; }
        | exp_f '+' exp_e { $$ = $1 + $3; }
        | exp_f '-' exp_e { $$ = $1 - $3; }
        | exp_f '*' exp_e { $$ = $1 * $3; }
        | exp_f '/' exp_e { $$ = $1 / $3; }
;

exp_c:  CADENA  { $$ = $1; }
      | exp_c '+' exp_c ';'{
                          printf( "%s\n", $3);
                          char* aux;
                          aux = concatenar($1, $3);
                          $$ = aux;
                        }
;


decl: INT ID ';' {  elemento e;
                    char * aux;
                    aux = $2;
                    e.name = aux;
                    e.tipo = 1;
                    if(Buscar(&ts, e)){
                      printf("\n--->ERROR! Ya ha sido declarada %s con int\n", e.name);
                    }
                    else{
                      Add(&ts, e);
                      printf("\nSe agregó correctamente\n");
                    }

                    ImprimeLista(&ts);

                  }
    | INT ID '=' exp_e ';' {  elemento e;
                              e.name = $2;
                              e.tipo = 1;
                              e.valor.valor1 = $4;
                              if(Buscar(&ts, e)){
                                printf("\n--->ERROR! Ya ha sido declarada %s con int\n", e.name);
                              }
                              else{
                                Add(&ts, e);
                                printf("\nSe agregó correctamente\n");
                              }
                              ImprimeLista(&ts);
                            }
    | DOUBLE ID ';' {
                      elemento e;
                      e.name = $2;
                      e.tipo = 2;

                      if(Buscar(&ts, e)){
                        printf("\n--->ERROR! Ya ha sido declarada %s con double\n", e.name);
                      }
                      else{
                        Add(&ts, e);
                        printf("\nSe agregó correctamente\n");
                      }

                      ImprimeLista(&ts);
                    }
    | DOUBLE ID '=' exp_f ';' { elemento e;
                                e.name = $2;
                                e.tipo = 2;
                                e.valor.valor2 = $4;
                                if(Buscar(&ts, e)){
                                  printf("\n--->ERROR! Ya ha sido declarada %s con double\n", e.name);
                                }
                                else{
                                  Add(&ts, e);
                                  printf("\nSe agregó correctamente\n");
                                }
                                ImprimeLista(&ts);
                              }

;


/* expvar, expdec, exptipo */

%%

void ImprimeLista(lista *l)
{
	posicion p;
	elemento e;
	int i;

	//Recorrer e imprimir los elementos mientras se tenga una posición valida
	p=First(l);		//Iniciamos por el primero de la lista
  printf("\n******************* Tabla de Simbolos ******************\n");
	//Mientras la posición sea valida
	for(i=1;ValidatePosition(l,p);i++)
	{
		e=Position(l,p);

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
		p=Following(l,p);
	}
  VerLigasLista(&ts);
	return;
}

int main(){
  Initialize(&ts);
  yyparse();
  Destroy(&ts);
  ImprimeLista(&ts);
  return 0;
}

void yyerror(char *s){
  printf("--%s--\n", s);
}

int yywrap(){
  return 1;
}
