%{
#include "ejemplo2.tab.h"
%}

NUM [0-9]+
NUM_R [0-9]*"."[0-9]+
CAD "\""[^'"\n]+[^'"]"\""
POW "pow("{NUM_R}
%%

{NUM}           {
		printf("Numero entero %s\n",yytext);
                yylval.entero = atoi(yytext);
                return (ENTERO);
                }
{NUM_R}           {
		printf("Numero real %s\n",yytext);
                yylval.real = atof(yytext);
                return (REAL);
                }
{CAD}						{
	printf("Cadena %s\n",yytext);
								yylval.str = yytext;
								return(CADENA);
								}

"+"	 						{
		printf("Signo mas\n");
                return (yytext[0]);
                }
"-"             {
                printf("Signo menos\n");
                return (yytext[0]);
                }

"*"             {
								printf("Signo multiplicacion\n");
								return (yytext[0]);
								}

"/"             {
                printf("Signo division\n");
                return (yytext[0]);
                }

"pow"						{
								printf("operacion pow\n");
								return
								}

"\n"            {
		printf("Salto de linea\n");
                return (yytext[0]);
                }
.               ;
%%
