%%
[RrAaIiZz]+"("[0-9]+","[0-9]+"," {printf("raiz");}
[RrAaIiZz]+"(""-"[0-9]+","[0-9]+"," {printf("raiz im");}
"-"?[0-9]+ {printf("Numero entero con o sin signo");}
"-"?[0-9]+"."[0-9]{1,2} {printf("Numero decimal con o sin signo");}
"pow(""-"?[0-9]+"."?[0-9]+",""-"?[0-9]")" {printf("Potencia de un numero");}
[0-9]+"+"[0-9]+ {printf("Operacion suma");}
[0-9]+"-"[0-9]+ {printf("Operacion resta");}
[0-9]+"*"[0-9]+ {printf("Operacion multiplicacion");}
[0-9]+"/"[1-9]+ {printf("Operacion division");}
[0-9]+"%"[1-9]+ {printf("Operacion modulo");}
