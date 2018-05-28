%{
#include <stdio.h>
//#include <math.h>
int yylex(void);
void yyerror (char *);
%}

/* Declaraciones de BISON */
%union{
	int entero;
  double real;
  char* str;
}

%token <entero> ENTERO
%type <entero> exp_e

%left '='
%left '+''-'
%left '*''/'

/* Gramática */
%%

input:    /* cadena vacía */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\tresultado: %d\n", $1); }
;

exp:     ENTERO	{ $$ = $1; }
	| exp '+' exp        { $$ = $1 + $3;    }
	| exp '-' exp        { $$ = $1 - $3;    }
;


%%

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
