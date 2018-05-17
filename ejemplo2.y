%{
#include <stdio.h>
//#include <string.h>
//#include <math.h>
int yylex(void);
void yyerror (char *);
int len_cad(char*);
char* concatenar(char*, char*);
%}

/* Declaraciones de BISON */
%union{
	int entero;
  double real;
	char* str;
}

%token <entero> ENTERO
%token <real> REAL
%token <str> CADENA
%type <entero> exp_e
%type <real> exp_f
%type <real> exp_r
%type <str> exp_c

%left '+''-'
%left '*''/'

/* Gramática */
%%

input:    /* cadena vacía */
        | input line
;

line:     '\n'
        | exp_e '\n'  { printf ("\tresultado: %d\n", $1); }
        | exp_r '\n'  { printf ("\tresultado: %.2f\n", $1); }
				| exp_f '\n'  { printf ("\tresultado: %.2f\n", $1); }
        | exp_c '\n'  { printf ("\tresultado: %s\n", $1); }

;

exp_c:
		CADENA	{ $$ = $1; }
	|	exp_c '+' exp_c	{ $$ = concatenar($1, $3); }

exp_f:
		ENTERO	{ $$ = $1; }
	|	REAL							{ $$ = $1; }
	| exp_f '+' exp_f        { $$ = $1 + $3;    }
	| exp_f '-' exp_f       { $$ = $1 - $3;    }
  | exp_f '*' exp_f        { $$ = $1 * $3;    }
  | exp_f '/' exp_f        { $$ = $1 / $3;    }
;

exp_e:     ENTERO	{ $$ = $1; }
	| exp_e '+' exp_e        { $$ = $1 + $3;    }
	| exp_e '-' exp_e       { $$ = $1 - $3;    }
  | exp_e '*' exp_e        { $$ = $1 * $3;    }
  | exp_e '/' exp_e        { $$ = $1 / $3;    }
;

exp_r: REAL {$$ = $1; }
	| exp_r '+' exp_r        { $$ = $1 + $3;    }
	| exp_r '-' exp_r       { $$ = $1 - $3;    }
  | exp_r '*' exp_r        { $$ = $1 * $3;    }
  | exp_r '/' exp_r        {  if ($3) $$=$1/$3;
                              else $$=$1;   }
;


%%

int len_cad(char* cadena){
  int i = 1;
  while(cadena[i] != '\0') i++;
  return i;
}

char* concatenar(char* cad1, char* cad2){
  char* cadena;

  printf("cad1: %s\n", cad1);
  printf("cad2: %s\n", cad2);
  int len_cad1 = 0;
  int len_cad2 = 0;
  int i = 0, j = 0;

  len_cad1 = len_cad(cad1);
  len_cad2 = len_cad(cad2);
	printf("%d\n", len_cad1);
	printf("%d\n", len_cad2);

  for(i = 0; i < len_cad1; i++) cadena[i] = cad1[i];

  for(j = 0; j < len_cad2; j++){
    cadena[i] = cad2[j];
    i++;
  }
  cadena[i] = '\0';
	printf("%s\n", cadena);
  return cadena;
}

char* resta(char* cad1, char* cad2){

	char* cadena;
	tam_cad1 = len_cad(cad1);
	tam_cad2 = len_cad(cad2);

	int i;
	int j = 0;

	for(i = 0; i < tam_cad1; i++){
		if (cad1[i] == cad2[j]){
			j++;
		}
		else if( cad1[i] != cad2[j] and j!=0)
			j = 0
		else
			cadena[i] == cad1
	}
	return cadena
}

int main() {
  yyparse();
  return 0;
}

void yyerror (char *s)
{
  printf ("--%s--\n", s);
}

int yywrap()
{
  return 1;
}

//"hola"+"hola"-"laho"
//holahola = hola
//pow(dec|int|exp, int)
//-5---5
