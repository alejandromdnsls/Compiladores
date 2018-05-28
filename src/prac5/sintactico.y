%{
#include <stdio.h>
#include <math.h>
#include "op_cadenas.h"
int yylex(void);
void yyerror(char *);
%}

/* Declaraciones de BISON */

%union{  /* especifica la colección completa de tipo de datos posibles */
  int entero;
  double flotante;
  char* str;
}

%token <entero> ENTERO /* terminal, define el token y su tipo */
%token <flotante> REAL
%token <str> CADENA
%token POW
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
        | exp_e '\n' { printf("\tresultado %d\n", $1); }
        | exp_f '\n' { printf("\tresultado %.2f\n", $1); }
        | exp_c '\n' { printf("\tresultaod %s\n", $1); }
;

exp_e:  ENTERO { $$ = $1; }
        | '-' ENTERO { $$ = ($2)*(-1); }
        | exp_e '+' exp_e { $$ = $1 + $3; }
        | exp_e '-' exp_e { $$ = $1 - $3; }
        | exp_e '*' exp_e { $$ = $1 * $3; }
        | exp_e '/' exp_e { $$ = $1 / $3; }
        | POW '(' exp_e ',' exp_e ')' ';' { $$ = pow($3,$5); }

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
      | exp_c '+' exp_c { char* aux;
                          aux = concatenar ($1, $3);
                          $$ = aux;
                        }
;

%%

int main(){
  yyparse();
  return 0;
}

void yyerror(char *s){
  printf("--%s--\n", s);
}

int yywrap(){
  return 1;
}
