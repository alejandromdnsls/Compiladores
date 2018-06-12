%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "op_cadenas.h"
#include "lista.h"
int yylex(void);
void yyerror(char *);
lista ts; //Se declara la lista en este caso Tabla de Simbolos
int flag_esta = 1; // Controla que las variables hayan sido declaradas
int flag_incompatibles=1; //Controla que los tipos de datos coincidan
int flag_op = 1; //controla las operaciones que no se pueden hacer
int flag_print = 0; // controla la impresion de resultado para hacer la que corresponde a su tipo puede ser 1, 2 o 3
%}

/* Declaraciones de BISON */

%union{  /* especifica la colección completa de tipo de datos pibles */
  int entero;
  double flotante;
  char* str;
  elemento elem;
}

%token <entero> ENTERO /* terminal, define el token y su tipo */
%token <flotante> REAL
%token <str> CADENA TIPO
%token <str> ID IF
%token POW
%token IGUAL
%type <entero> exp_e /* no terminal */
%type <flotante> exp_f
%type <str> exp_c
%type <entero> expCondicion
%type <elem> expVar
%left '('')'
%left '>''<' IGUAL '='
%left '+''-'
%left '*''/'

/* Gramática */
%%

input:    /* cadena vacía */
        | input line
;

line:     '\n'
        | exp_e '\n' { printf("\tresultado: %d\n", $1); }
        | exp_f '\n' { printf("\tresultado: %f\n", $1); }
        | exp_c '\n' { printf("\tresultado: %s\n", $1); }
        | decl '\n'
        | asig '\n'
        | expVar '\n' {
                        if(flag_print==1){
                          printf("\tresultado: %d\n", $1.valor.valor1);
                          flag_print = 0;
                        }
                        else if(flag_print==2){
                          printf("\tresultado: %f\n", $1.valor.valor2);
                          flag_print = 0;
                        }
                        else if(flag_print==3){
                          printf("\tresultado: %s\n", $1.valor.valor3);
                          flag_print = 0;
                        }
                        else
                          flag_incompatibles=1;
                          flag_op=1;
                          flag_esta=1;
                      }
        | err '\n'
        | expCondicion '\n' {
                              if($1==1)
                                printf("\n\tIF: True\n");
                              else
                                printf("\n\tIF: False\n");
                            }
;

exp_e:  ENTERO { $$ = $1; /*printf("%d\n", $1);*/ }
        | '-' exp_e { $$ = ($2)*(-1); }
        | '+' exp_e { $$ = ($2)*(-1); }
        | exp_e '+' exp_e { $$ = $1 + $3; }
        | exp_e '-' exp_e { $$ = $1 - $3; }
        | exp_e '*' exp_e { $$ = $1 * $3; }
        | exp_e '/' exp_e { $$ = $1 / $3; }
        //| exp_e '%' exp_e { $$ = $1 % $3; }
        | POW '(' exp_e ',' exp_e ')' { $$ = pow($3,$5); }
        | exp_e '+' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}
        | exp_e '-' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}
        | exp_e '*' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}
        | exp_e '/' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}

;

exp_f:  REAL { $$ = $1; /*printf("%f\n", $1);*/ }
        | '-' exp_f { $$ = ($2)*(-1); }
        | '+' exp_f { $$ = ($2)*(-1); }
        | exp_f '+' exp_f { $$ = $1 + $3; }
        | exp_f '-' exp_f { $$ = $1 - $3; }
        | exp_f '*' exp_f { $$ = $1 * $3; }
        | exp_f '/' exp_f { $$ = $1 / $3; }
        //| exp_f '%' exp_f { $$ = $1 % $3; }
        | POW '(' exp_f ',' exp_f ')' { $$ = pow($3,$5); }
        | exp_e '+' exp_f { $$ = $1 + $3; }
        | exp_e '-' exp_f { $$ = $1 - $3; }
        | exp_e '*' exp_f { $$ = $1 * $3; }
        | exp_e '/' exp_f { $$ = $1 / $3; }
        //| exp_e '%' exp_f { $$ = $1 % $3; }
        | POW '(' exp_e ',' exp_f ')' { $$ = pow($3,$5); }
        | exp_f '+' exp_e { $$ = $1 + $3; }
        | exp_f '-' exp_e { $$ = $1 - $3; }
        | exp_f '*' exp_e { $$ = $1 * $3; }
        | exp_f '/' exp_e { $$ = $1 / $3; }
        //| exp_f '%' exp_e { $$ = $1 % $3; }
        | POW '(' exp_f ',' exp_e ')' { $$ = pow($3,$5); }
        | exp_f '+' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}
        | exp_f '-' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}
        | exp_f '*' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}
        | exp_f '/' exp_c {printf("\n\t-->ERROR! Operacion no permitida\n"); $$=0;}

;

exp_c:  CADENA  { $$ = $1; /*printf("%s\n", $1) */ }
        | exp_c '+' exp_c {
                            char* aux;
                            aux = concatenar($1, $3);
                            $$ = aux;
                          }

        | exp_c '-' exp_c {
                            char* aux;
                            aux = resta($1,$3);
                            $$ = aux;
                          }
 ;



expVar: ID  {
              posicion p;
              elemento e;
              elemento * e_ts;
              //limpiar $1
              e.name = $1;
              p = Search(&ts, e);
              if(p!=NULL){
                e_ts = getElement(&ts, p);
                $$ = *e_ts;
              }
              else{
                printf("\n\t-->ERROR! no ha sido declarada previamente %s\n", $1);
                flag_esta = 0;
              }
            }

      | '-' expVar  {
                      if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                      elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                      e_aux = &$2;
                      $$ = *e_aux;
                      if($$.tipo == 1){
                        $$.valor.valor1 = ($2.valor.valor1)*(-1);
                        flag_print = 1;
                      }
                      else if($$.tipo == 2){
                        $$.valor.valor2 = ($2.valor.valor2)*(-1);
                        flag_print = 2;
                      }
                      else if($$.tipo == 3){
                        printf("\n\t-->ERROR! No hay cadenas negativas\n");
                      }
                      }
                    }
      | '(' expVar ')'{
                        elemento*e_aux; //Pasa una copia a $$ un tipo elemento
                        e_aux = &$2;
        $$ = *e_aux;
        if($$.tipo == 1){
          $$.valor.valor1 = $2.valor.valor1;
          flag_print = 1;
        }
        else if($$.tipo == 2){
          $$.valor.valor2 = $2.valor.valor2;
          flag_print = 2;
        }
        else if($$.tipo == 3){
          $$.valor.valor3 = $2.valor.valor3;
        }
                      }

      | expVar '+' expVar {
                            //printf("$$.name: %s\n", $$.name);
                            //printf("$$.tipo: %d\n", $$.tipo);
                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                            if($$.tipo == 1){
                              $$.tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                              if($1.tipo == 1 && $3.tipo==1){
                                $$.valor.valor2 = $1.valor.valor1 + $3.valor.valor1;
                                flag_print=2;
                              }
                              else if($1.tipo == 1 && $3.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor1 + $3.valor.valor2;
                                flag_print = 2;
                              }
                              else if($1.tipo == 2 && $3.tipo == 1){
                                $$.valor.valor2 = $1.valor.valor2 + $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if($1.tipo == 2 && $3.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 + $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                            }
                            else if($$.tipo ==2){
                              if($1.tipo == 1 && $3.tipo==1){
                                $$.valor.valor2 = $1.valor.valor1 + $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if($1.tipo == 1 && $3.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor1 + $3.valor.valor2;
                                flag_print = 2;
                              }
                              else if($1.tipo == 2 && $3.tipo == 1){
                                $$.valor.valor2 = $1.valor.valor2 + $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if($1.tipo == 2 && $3.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 + $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print=0;
                              }
                            }
                            else if($$.tipo == 3){
                              if($1.tipo == 3 && $3.tipo == 3){
                                $$.valor.valor3 = concatenar($1.valor.valor3, $3.valor.valor3);
                                flag_print = 3;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print=0;
                              }
                            }
                            //printf("$$.name: %s\n", $$.name);
                            //printf("$$.tipo: %d\n", $$.tipo);
                            //printf("$$.valor: %f\n", $$.valor.valor2);
                            }
                          }


        | expVar '+' exp_e  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 + $3;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 + $3;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | expVar '+' exp_f  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 + $3;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 + $3;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | expVar '+' exp_c  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if($$.tipo == 3)
                                $$.valor.valor3 = concatenar($1.valor.valor3, $3);
                                flag_print = 3;
                              }
                            }

        | exp_e '+' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux + $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = aux + $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | exp_f '+' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux + $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = aux + $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | exp_c '+' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if($$.tipo == 3)
                                $$.valor.valor3 = concatenar(aux, $3.valor.valor3);
                                flag_print = 3;
                              }
                            }

        | expVar '-' expVar {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if($1.tipo == 1 && $3.tipo==1){
                                  $$.valor.valor2 = $1.valor.valor1 - $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 1 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor1 - $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 1){
                                  $$.valor.valor2 = $1.valor.valor2 - $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor2 - $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if($$.tipo ==2){
                                if($1.tipo == 1 && $3.tipo==1){
                                  $$.valor.valor2 = $1.valor.valor1 - $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 1 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor1 - $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 1){
                                  $$.valor.valor2 = $1.valor.valor2 - $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor2 - $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if($$.tipo == 3){
                                if($1.tipo == 3 && $3.tipo == 3){
                                  $$.valor.valor3 = resta($1.valor.valor3, $3.valor.valor3);
                                  flag_print = 3;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }

                            }

        | expVar '-' exp_e  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 - $3;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 - $3;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | expVar '-' exp_f  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 - $3;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 - $3;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | expVar '-' exp_c  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if($$.tipo == 3){
                                $$.valor.valor3 = resta($1.valor.valor3, $3);
                                flag_print = 3;
                              }
                              }
                            }

        | exp_e '-' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux - $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = aux - $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | exp_f '-' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux - $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = aux - $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | exp_c '-' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if($$.tipo == 3)
                                $$.valor.valor3 = resta(aux, $3.valor.valor3);
                                flag_print = 3;
                              }
                            }

        | expVar '*' expVar {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if($1.tipo == 1 && $3.tipo==1){
                                  $$.valor.valor2 = $1.valor.valor1 * $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 1 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor1 * $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 1){
                                  $$.valor.valor2 = $1.valor.valor2 * $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor2 * $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if($$.tipo ==2){
                                if($1.tipo == 1 && $3.tipo==1){
                                  $$.valor.valor2 = $1.valor.valor1 * $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 1 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor1 * $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 1){
                                  $$.valor.valor2 = $1.valor.valor2 * $3.valor.valor1;
                                  flag_print = 2;
                                }
                                else if($1.tipo == 2 && $3.tipo == 2){
                                  $$.valor.valor2 = $1.valor.valor2 * $3.valor.valor2;
                                  flag_print = 2;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              else if($$.tipo == 3){
                                if($1.tipo == 3 && $3.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                  flag_print = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }
                            }

        | expVar '*' exp_e  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 * $3;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 * $3;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | expVar '*' exp_f  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 * $3;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = $1.valor.valor2 * $3;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | expVar '*' exp_c  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if($$.tipo == 3){
                                if($$.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                  flag_print = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }
                            }

        | exp_e '*' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux * $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = aux * $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | exp_f '*' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux * $3.valor.valor1;
                                flag_print = 2;
                              }
                              else if ($$.tipo == 2){
                                $$.valor.valor2 = aux * $3.valor.valor2;
                                flag_print = 2;
                              }
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              }
                            }

        | exp_c '*' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                                flag_print = 0;
                              }
                              else if($$.tipo == 3){
                                if($$.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                  flag_print = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                  flag_print = 0;
                                }
                              }
                              }
                            }

        | expVar '/' expVar {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if($1.tipo == 1 && $3.tipo==1)
                                  $$.valor.valor2 = $1.valor.valor1 / $3.valor.valor1;
                                else if($1.tipo == 1 && $3.tipo == 2)
                                  $$.valor.valor2 = $1.valor.valor1 / $3.valor.valor2;
                                else if($1.tipo == 2 && $3.tipo == 1)
                                  $$.valor.valor2 = $1.valor.valor2 / $3.valor.valor1;
                                else if($1.tipo == 2 && $3.tipo == 2)
                                  $$.valor.valor2 = $1.valor.valor2 / $3.valor.valor2;
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if($$.tipo ==2){
                                if($1.tipo == 1 && $3.tipo==1)
                                  $$.valor.valor2 = $1.valor.valor1 / $3.valor.valor1;
                                else if($1.tipo == 1 && $3.tipo == 2)
                                  $$.valor.valor2 = $1.valor.valor1 / $3.valor.valor2;
                                else if($1.tipo == 2 && $3.tipo == 1)
                                  $$.valor.valor2 = $1.valor.valor2 / $3.valor.valor1;
                                else if($1.tipo == 2 && $3.tipo == 2)
                                  $$.valor.valor2 = $1.valor.valor2 / $3.valor.valor2;
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if($$.tipo == 3){
                                if($1.tipo == 3 && $3.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            }

        | expVar '/' exp_e  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 / $3;
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = $1.valor.valor2 / $3;
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | expVar '/' exp_f  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = $1.valor.valor1 / $3;
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = $1.valor.valor2 / $3;
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | expVar '/' exp_c  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if($$.tipo == 3){
                                if($$.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            }

        | exp_e '/' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux / $3.valor.valor1;
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = aux / $3.valor.valor2;
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | exp_f '/' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = aux / $3.valor.valor1;
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = aux / $3.valor.valor2;
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | exp_c '/' expVar  {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = $1;   //guarda exp_e para no perder el valor
                              e_aux = &$3;
                              $$ = *e_aux;
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if($$.tipo == 3){
                                if($$.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            }

        | POW '(' expVar ',' expVar')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2; //Se fuerza a ser de tipo double para no perder los decimales en la recursion
                                if($3.tipo == 1 && $5.tipo==1)
                                  $$.valor.valor2 = pow($3.valor.valor1 , $5.valor.valor1);
                                else if($3.tipo == 1 && $5.tipo == 2)
                                  $$.valor.valor2 = pow($3.valor.valor1 , $5.valor.valor2);
                                else if($3.tipo == 2 && $5.tipo == 1)
                                  $$.valor.valor2 = pow($3.valor.valor2 , $5.valor.valor1);
                                else if($3.tipo == 2 && $5.tipo == 2)
                                  $$.valor.valor2 = pow($3.valor.valor2 , $5.valor.valor2);
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if($$.tipo ==2){
                                if($3.tipo == 1 && $5.tipo==1)
                                  $$.valor.valor2 = pow($3.valor.valor1 , $5.valor.valor1);
                                else if($3.tipo == 1 && $5.tipo == 2)
                                  $$.valor.valor2 = pow($3.valor.valor1 , $5.valor.valor2);
                                else if($3.tipo == 2 && $5.tipo == 1)
                                  $$.valor.valor2 = pow($3.valor.valor2 , $5.valor.valor1);
                                else if($3.tipo == 2 && $5.tipo == 2)
                                  $$.valor.valor2 = pow($3.valor.valor2 , $5.valor.valor2);
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              else if($$.tipo == 3){
                                if($3.tipo == 3 && $5.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            }

        | POW '(' expVar',' exp_e ')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = pow($3.valor.valor1 , $5);
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = pow($3.valor.valor2 , $5);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | POW '(' expVar',' exp_f ')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = pow($3.valor.valor1 , $5);
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = pow($3.valor.valor2 , $5);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | POW '(' expVar',' exp_c ')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if($$.tipo == 3){
                                if($$.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            }

        | POW '(' exp_e ',' expVar ')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //para pasarle a $$ un tipo elemento
                              int aux = $3;   //guarda exp_e para no perder el valor
                              e_aux = &$5;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = pow(aux , $5.valor.valor1);
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = pow(aux , $5.valor.valor2);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | POW '(' exp_f ',' expVar ')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              double aux = $3;   //guarda exp_e para no perder el valor
                              e_aux = &$5;
                              $$ = *e_aux;
                              if($$.tipo == 1){
                                $$.tipo = 2;
                                $$.valor.valor2 = pow(aux , $5.valor.valor1);
                              }
                              else if ($$.tipo == 2)
                                $$.valor.valor2 = pow(aux , $5.valor.valor2);
                              else{
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              }
                            }

        | POW '(' exp_c ',' expVar ')' {
                              if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              elemento*e_aux; //Apuntar al elemento &3 y no perderlo en la recursion
                              char * aux = $3;   //guarda exp_e para no perder el valor
                              e_aux = &$5;
                              $$ = *e_aux;
                              if ($$.tipo == 1){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if ($$.tipo == 2){
                                printf("\n\t-->ERROR! Incompatible types\n");
                                flag_incompatibles = 0;
                              }
                              else if($$.tipo == 3){
                                if($$.tipo == 3){
                                  printf("\n\t-->ERROR! Operacion no se puede realizar\n");
                                  flag_op = 0;
                                }
                                else{
                                  printf("\n\t-->ERROR! Incompatible types\n");
                                  flag_incompatibles = 0;
                                }
                              }
                              }
                            }

decl:  TIPO ID ';' {
                      elemento e;
                      int tipo;

                      if(!strcmp($1, "int")){
                        tipo = 1;
                      }
                      else if(!strcmp($1, "double")){
                        tipo = 2;
                      }
                      else if(!strcmp($1, "string")){
                        tipo = 3;
                      }

                      e.name = $2;
                      e.tipo = tipo;

                      if(Buscar(&ts, e)){
                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                      }
                      else{
                        Insert(&ts, e);
                        printf("\n\t Se agregó correctamente\n");
                        ImprimeTS(&ts);
                      }
                    }

        | TIPO ID '=' expVar ';'   {
                                      elemento e;
                                      //posicion p_expVar;

                                      //p_expVar = Search(&ts, $4);

                                      if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                                        if(!strcmp($1, "int")){
                                          e.name = $2;
                                          e.tipo = 1;
                                          if($4.tipo == 1)
                                            e.valor.valor1 = $4.valor.valor1;
                                          else if($4.tipo == 2)
                                            e.valor.valor1 = $4.valor.valor2;
                                          else if($4.tipo == 3)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is int and %s string", e.name, $4.name);

                                          if(Buscar(&ts, e)){
                                            printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                          }
                                          else{
                                            Insert(&ts, e);
                                            printf("\n\t Se agregó correctamente\n");
                                            ImprimeTS(&ts);
                                          }
                                        }
                                        if(!strcmp($1, "double")){
                                          e.name = $2;
                                          e.tipo = 2;
                                          if($4.tipo == 1)
                                            e.valor.valor2 = $4.valor.valor1;
                                          else if($4.tipo == 2)
                                            e.valor.valor2 = $4.valor.valor2;
                                          else if($4.tipo == 3)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is double and %s string", e.name, $4.name);

                                          if(Buscar(&ts, e)){
                                            printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                          }
                                          else{
                                            Insert(&ts, e);
                                            printf("\n\t Se agregó correctamente\n");
                                            ImprimeTS(&ts);
                                          }
                                        }
                                        if(!strcmp($1, "string")){
                                          e.name = $2;
                                          e.tipo = 3;
                                          if($4.tipo == 1)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s int", e.name, $4.name);
                                          else if($4.tipo == 2)
                                            printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s double", e.name, $4.name);
                                          else if($4.tipo == 3)
                                            e.valor.valor3 = $4.valor.valor3;

                                          if(Buscar(&ts, e)){
                                            printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                          }
                                          else{
                                            Insert(&ts, e);
                                            printf("\n\t Se agregó correctamente\n");
                                            ImprimeTS(&ts);
                                          }
                                        }
                                      }
                                      else{
                                        printf("\n\t-->ERROR! no se ha podido declarar %s\n", $2);
                                        flag_esta = 1;
                                        flag_incompatibles = 1;
                                        flag_op = 1;
                                      }
                                  }

        | TIPO ID '=' exp_e ';'   {
                                    elemento e;

                                    if(!strcmp($1, "int")){
                                      e.name = $2;
                                      e.tipo = 1;
                                      e.valor.valor1 = $4;
                                      if(Buscar(&ts, e)){
                                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                      }
                                      else{
                                        Insert(&ts, e);
                                        printf("\n\t Se agregó correctamente\n");
                                        ImprimeTS(&ts);
                                      }
                                    }
                                    else if(!strcmp($1, "double")){
                                      e.name = $2;
                                      e.tipo = 2;
                                      e.valor.valor2 = $4;
                                      if(Buscar(&ts, e)){
                                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                      }
                                      else{
                                        Insert(&ts, e);
                                        printf("\n\t Se agregó correctamente\n");
                                        ImprimeTS(&ts);
                                      }
                                    }
                                    else if(!strcmp($1, "string")){
                                      printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                    }
                                  }

      | TIPO ID '=' exp_f ';'   {
                                  elemento e;
                                  if(!strcmp($1, "int")){
                                    e.name = $2;
                                    e.tipo = 1;
                                    e.valor.valor1 = $4;
                                    if(Buscar(&ts, e)){
                                      printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                    }
                                    else{
                                      Insert(&ts, e);
                                      printf("\n\t Se agregó correctamente\n");
                                      ImprimeTS(&ts);
                                    }
                                  }
                                  else if(!strcmp($1, "double")){
                                    e.name = $2;
                                    e.tipo = 2;
                                    e.valor.valor2 = $4;
                                    if(Buscar(&ts, e)){
                                      printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                    }
                                    else{
                                      Insert(&ts, e);
                                      printf("\n\t Se agregó correctamente\n");
                                      ImprimeTS(&ts);
                                    }
                                  }
                                  else if(!strcmp($1, "string")){
                                    printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                  }
                                }

        | TIPO ID '=' exp_c ';'  {
                                    elemento e;
                                    if(!strcmp($1, "int")){
                                      printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                    }
                                    else if(!strcmp($1, "double")){
                                      printf("\n\t--->ERROR! Incompatible types in assigment\n");
                                    }
                                    else if(!strcmp($1, "string")){
                                      e.name = $2;
                                      e.tipo = 3;
                                      e.valor.valor3 = $4;
                                      if(Buscar(&ts, e)){
                                        printf("\n\t-->ERROR! ya ha sido declarada previamente %s\n", $2);
                                      }
                                      else{
                                        Insert(&ts, e);
                                        printf("\n\t Se agregó correctamente\n");
                                        ImprimeTS(&ts);
                                      }
                                    }
                                  }
;

asig: ID '=' exp_e ';'  {
                          elemento e;
                          posicion p;
                          elemento * e_ts;

                          e.name = $1;

                          p = Search(&ts,e);

                          if(p != NULL){
                            //printf("Posicion en la que encontre el elemento %p\n", p);
                            e_ts = getElement(&ts, p);
                            //printf("Elemento apuntado y guardado: %p\n", e_ts);

                            if(e_ts->tipo == 1){
                              e_ts->valor.valor1=$3;
                              printf("\n\tAsignacion correcta\n");
                              ImprimeTS(&ts);
                            }
                            else if(e_ts->tipo == 2){
                              e_ts->valor.valor2=$3;
                              printf("\n\tAsignacion correcta\n");
                              ImprimeTS(&ts);
                            }
                            else if(e_ts->tipo == 3){
                              printf("\n\t--->ERROR! Incompatible types in assigment\n");
                            }
                          }
                          else{
                            printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                          }
                        }

      | ID '=' exp_f ';'  {
                            elemento e;
                            posicion p;
                            elemento * e_ts;

                            e.name = $1;
                            p = Search(&ts,e);

                            if(p != NULL){
                              //printf("Posicion en la que encontre el elemento %p\n", p);
                              e_ts = getElement(&ts, p);
                              //printf("Elemento apuntado y guardado: %p\n", e_ts);

                              if(e_ts->tipo == 1){
                                e_ts->valor.valor1=$3;
                                printf("\n\tAsignacion correcta\n");
                                ImprimeTS(&ts);
                              }
                              else if(e_ts->tipo == 2){
                                e_ts->valor.valor2=$3;
                                printf("\n\tAsignacion correcta\n");
                                ImprimeTS(&ts);
                              }
                              else if(e_ts->tipo == 3){
                                printf("\n\t--->ERROR! Incompatible types in assigment\n");
                              }
                            }
                            else{
                              printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                            }
                          }

      | ID '=' exp_c ';'  {
                            elemento e;
                            posicion p;
                            elemento * e_ts;

                            e.name = $1;
                            p = Search(&ts,e);

                            if(p != NULL){
                              //printf("Posicion en la que encontre el elemento %p\n", p);
                              e_ts = getElement(&ts, p);
                              //printf("Elemento apuntado y guardado: %p\n", e_ts);

                              if(e_ts->tipo == 1){
                                printf("\n\t--->ERROR! Incompatible types in assigment\n");

                              }
                              else if(e_ts->tipo == 2){
                                printf("\n\t--->ERROR! Incompatible types in assigment\n");
                              }
                              else if(e_ts->tipo == 3){
                                e_ts->valor.valor3=$3;
                                printf("\n\tAsignacion correcta\n");
                                ImprimeTS(&ts);
                              }
                            }
                            else{
                              printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                            }
                          }

      | ID '=' expVar ';' {
                            elemento e;
                            posicion p;
                            elemento * e_ts;

                            e.name = $1;

                            p = Search(&ts, e);

                            if(flag_esta == 1 && flag_incompatibles == 1 && flag_op==1){
                              e_ts = getElement(&ts, p);
                              if(p != NULL){
                                e_ts = getElement(&ts, p);
                                if(e_ts->tipo == 1){
                                  if($3.tipo == 1){
                                    e_ts->valor.valor1 = $3.valor.valor1;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if($3.tipo == 2){
                                    e_ts->valor.valor1 = $3.valor.valor2;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if($3.tipo == 3)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s int", e.name, $3.name);
                                }
                                else if(e_ts->tipo == 2){
                                  if($3.tipo == 1){
                                    e_ts->valor.valor2 = $3.valor.valor1;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if($3.tipo == 2){
                                    e_ts->valor.valor2 = $3.valor.valor2;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                  else if($3.tipo == 3)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is string and %s double", e.name, $3.name);
                                }
                                else if(e_ts->tipo == 3){
                                  if($3.tipo == 1)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is int and %s string", e.name, $3.name);
                                  else if($3.tipo == 2)
                                    printf("\n\t---> ERROR! Incompatible types in assigment: %s is double and %s string", e.name, $3.name);
                                  else if($3.tipo == 3){
                                    e_ts->valor.valor3=$3.valor.valor3;
                                    printf("\n\tAsignacion correcta\n");
                                    ImprimeTS(&ts);
                                  }
                                }
                              }
                              else{
                                printf("\n\t-->ERROR! asignacion primero tiene que ser declarado %s\n", e.name);
                              }
                            }
                            else{
                              printf("\n\t-->ERROR! no se ha podido declarar %s\n", $1);
                              flag_esta = 1;
                              flag_incompatibles = 1;
                              flag_op = 1;
                            }
                          }
;

expCondicion:  IF '(' expVar '<' expVar ')' ';' {
                                                  if($3.tipo==1 && $3.tipo==1){
                                                    if($3.valor.valor1 < $5.valor.valor1)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if($3.tipo==1 && $3.tipo==2){
                                                    if($3.valor.valor1 < $5.valor.valor2)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if ($3.tipo==2 && $3.tipo==1){
                                                    if($3.valor.valor2 < $5.valor.valor1)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if($3.tipo==2 && $3.tipo==2){
                                                    if($3.valor.valor2 < $5.valor.valor2)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }

                                                  else{
                                                    printf("--->ERROR! no se puede\n");
                                                  }
                                                }

|IF '(' expVar '>' expVar ')' ';' {
                                                  if($3.tipo==1 && $3.tipo==1){
                                                    if($3.valor.valor1 > $5.valor.valor1)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if($3.tipo==1 && $3.tipo==2){
                                                    if($3.valor.valor1 > $5.valor.valor2)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if ($3.tipo==2 && $3.tipo==1){
                                                    if($3.valor.valor2 > $5.valor.valor1)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if($3.tipo==2 && $3.tipo==2){
                                                    if($3.valor.valor2 > $5.valor.valor2)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }

                                                  else{
                                                    printf("--->ERROR! no se puede\n");
                                                  }
                                                }

|IF '(' expVar IGUAL expVar ')' ';' {
                                                  if($3.tipo==1 && $3.tipo==1){
                                                    if($3.valor.valor1 == $5.valor.valor1)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if($3.tipo==1 && $3.tipo==2){
                                                    if($3.valor.valor1 == $5.valor.valor2)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if ($3.tipo==2 && $3.tipo==1){
                                                    if($3.valor.valor2 == $5.valor.valor1)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }
                                                  else if($3.tipo==2 && $3.tipo==2){
                                                    if($3.valor.valor2 == $5.valor.valor2)
                                                      $$ = 1;
                                                    else
                                                      $$ = 0;
                                                  }

                                                  else{
                                                    printf("--->ERROR! no se puede\n");
                                                  }
                                                }
;


err:    TIPO ID '=' expVar { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | TIPO ID '=' exp_e { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | TIPO ID '=' exp_f { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | TIPO ID '=' exp_c { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | TIPO ID { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | ID '=' exp_e { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | ID '=' exp_f { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | ID '=' exp_c { printf("\n\t-->ERROR! te falto escribir ';'\n"); }
      | ID '=' expVar { printf("\n\t-->ERROR! te falto escribir ';'\n"); }

;
%%

int main(){
  Initialize(&ts);
  yyparse();
  Destroy(&ts);
  ImprimeTS(&ts);
  return 0;
}

void yyerror(char *s){
  printf("--%s--\n", s);
}

int yywrap(){
  return 1;
}
