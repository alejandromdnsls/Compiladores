%{

%}

NUM [0-9]
ENTERO {NUM}+
REAL {NUM}*"."{NUM}+
OP "+"|"-"|"*"|"/"|"("|")"|","|";"

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

"\n"              {
                  printf("Salto de linea\n");
                  }

.                 ;
%%
