%{

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
                  printf("Numero entero\n");
                  }

{REAL}            {
                  printf("Numero real\n");
                  }

{OP}              {
                  printf("Operador\n");
                  }

{CAD}              {
                  printf("Cadena\n");
                  }

"\n"              {
                  printf("Salto de linea\n");
                  }

[Pp][Oo][Ww]      {
                  printf("Potencia\n");
                  }

"int"             {
                  printf("Tipo de dato int\n");
                  }

"double"          {
                  printf("Tipo de dato double\n");
                  }

"string"          {
                  printf("Tipo de dato string\n");
                  }

{ID}              {
                  printf("Identificador\n");
                  }

.                 ;
%%
