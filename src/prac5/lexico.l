%{
#include "lista.h"
#include "sintactico.tab.h" /* generado automaticamente por bison */
%}

NUM [0-9]
ENTERO {NUM}+
REAL {NUM}*"."{NUM}+
LETRA [a-zA-Z]
TIPO int|double|string
ID [a-zA-Z][a-zA-Z0-9]*"_"?[a-zA-Z0-9]*
CAD "\""[^'"\n]+"\""


%%

{ENTERO}          {
                  printf("Numero entero %s\n", yytext);
                  yylval.entero = atoi(yytext);
                  return (ENTERO);
                  }

{REAL}            {
                  printf("Numero real %s\n", yytext);
                  yylval.flotante = atof(yytext);
                  return (REAL);
                  }

{CAD}             {
                  printf("Cadena: %s\n", yytext);
                  char * aux;
                  int i=0,j=0,k=0;
                  while(yytext[i]){i++;}
                  //printf("el tamaño de la cadena %s es: %d\n",yytext,i);
                  aux = malloc (i-1);
                  for(j=0,k=1;j<(i-2);j++,k++){
                          aux[j]=yytext[k];
                  }
                  aux[j+1]='\0';
                  //printf("aux =%s\n",aux);
                  yylval.str = aux;
                  //printf("%s\n", yylval.str);
                  return (CADENA);
                  }

[Pp][Oo][Ww]      {
                  printf("Potencia %s\n", yytext);
                  return (POW);
                  }

{TIPO}            {
                  printf("Tipo de dato: %s\n", yytext);
                  char * aux;
                  int i=0,j=0,k=0;
                  while(yytext[i]){i++;}
                  //printf("el tamaño de la cadena %s es: %d\n",yytext,i);
                  aux = malloc (i+1);
                  for(j=0,k=0;j<i;j++,k++){
                          aux[j]=yytext[k];
                  }
                  aux[j+1]='\0';
                  //printf("aux =%s\n",aux);
                  yylval.str = aux;
                  //printf("%s\n", yylval.str);
                  return (TIPO);
                  }

{ID}              {
                  printf("Identificador %s\n", yytext);
                  char * aux;
                  int i=0,j=0,k=0;
                  while(yytext[i]){i++;}
                  //printf("el tamaño de la cadena %s es: %d\n",yytext,i);
                  aux = malloc (i+1);
                  for(j=0,k=0;j<i;j++,k++){
                    aux[j]=yytext[k];
                  }
                  aux[j+1]='\0';
                  //printf("aux =%s\n",aux);
                  yylval.str = aux;
                  //printf("%s\n", yylval.str);
                  return (ID);
                  }


"+"               {
                  printf("Operador mas: %s\n", yytext);
                  return (yytext[0]);
                  }

"-"               {
                  printf("Operador menos: %s\n", yytext);
                  return (yytext[0]);
                  }

"*"               {
                  printf("Operador multiplicacion: %s\n", yytext);
                  return (yytext[0]);
                  }

"/"               {
                  printf("Operador division: %s\n", yytext);
                  return (yytext[0]);
                  }

"%"               {
                  printf("Operador modulo: %s\n", yytext);
                  return (yytext[0]);
                  }

"="               {
                  printf("Asignacion: %s\n", yytext);
                  return (yytext[0]);
                  }

"("               {
                  printf("Parentesis abrir: %s\n", yytext);
                  return (yytext[0]);
                  }

")"               {
                  printf("Parentesis cerrado: %s\n", yytext);
                  return (yytext[0]);
                  }

","               {
                  printf("Coma: %s\n", yytext);
                  return (yytext[0]);
                  }

";"               {
                  printf("Fin expresión: %s\n", yytext);
                  return (yytext[0]);
                  }


"\n"              {
                  printf("\nSalto de linea %s\n", yytext);
                  return (yytext[0]);
                  }

.                 ;
%%
