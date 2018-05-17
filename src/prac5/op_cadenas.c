#include <stdio.h>

int len_cadena(char*);
char* concatenar(char*, char*)

int main(){
  char* cadena = "simon";
  int longitud = 0;

  longitud = len_cadena(cadena);
  printf("%d\n", longitud);

  return 0;
}

int len_cadena(char* cad){
  int i = 0;
  while(cad[i]) i++;
  return i;
}
