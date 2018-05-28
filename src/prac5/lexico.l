%{
#include "sintactico.tab.h" /* generador automaticamente por bison */
%}

NUM [0-9]
ENTERO {NUM}+
REAL {NUM}*"."{NUM}+
OP "+"|"-"|"*"|"/"|"("|")"|","|";"
/* CAD \"[a-zA-Z0-9\\\@\#\+\-\/\(\)]+\" */
CAD "\""[^'"\n]+"\""
ID [a-zA-Z][a-zA-Z0-9]*"_"?[a-zA-Z0-9]*

%%

{NUM}             {
                  printf("Numero entero %s\n", yytext);
                  yylval.entero = atoi(yytext);
                  printf("%d\n", ENTERO);
                  return (ENTERO);
                  }

{REAL}            {
                  printf("Numero real %s\n", yytext);
                  yylval.flotante = atof(yytext);
                  return(REAL);
                  }

{OP}              {
                  printf("Operador %s %zu\n", yytext, yyleng);
                  printf("%d\n", yytext[0]);
                  return (yytext[0]);
                  }

{CAD}             {
                  printf("Cadena %s %zu\n", yytext, yyleng);
                  yyval.str = yytext;
                  return (CADENA)
                  }

"\n"              {
                  printf("Salto de linea %s\n", yytext);
                  return (yytext[0]);
                  }

[Pp][Oo][Ww]      {
                  printf("Potencia %s\n", yytext);
                  return (POW);
                  }

"int"             {
                  printf("Tipo de dato %s\n", yytext);
                  }

"double"          {
                  printf("Tipo de dato %s\n", yytext);
                  }

"string"          {
                  printf("Tipo de dato %s\n", yytext);
                  }

{ID}              {
                  printf("Identificador %s\n", yytext);
                  }

.                 ;
%%
