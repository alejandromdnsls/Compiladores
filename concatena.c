#include <stdio.h>

int len_cad(char*);
char* concatenar(char*, char*);
char* resta(char*, char*);
int main(){

  char* cad1;
  char* cad2;
  char* cadena;
  cad1 = "holahola";
  cad2 = "laho";

  cadena = resta(cad1, cad2);
  printf("%s\n", cadena);

  return 0;
}

int len_cad(char* cadena){
  int i = 1;
  while(cadena[i] != '\0') i++;
  return i;
}

char* concatenar(char* cad1, char* cad2){
  char* cadena;
  int len_cad1 = 0;
  int len_cad2 = 0;
  int i = 0, j = 0;

  len_cad1 = len_cad(cad1);
  len_cad2 = len_cad(cad2);

  for(i = 0; i < len_cad1; i++) cadena[i] = cad1[i];

  for(j = 0; j < len_cad2; j++){
    cadena[i] = cad2[j];
    i++;
  }
  cadena[i] = '\0';
  return cadena;
}

char* resta(char* cad1, char* cad2){

	char* cadena;
  int tam_cad1 = 0;
  int tam_cad2 = 0;
	tam_cad1 = len_cad(cad1);
	tam_cad2 = len_cad(cad2);

	int i;
	int j = 0;

	for(i = 0; i < tam_cad1; i++){
		if (cad1[i] == cad2[j]){
			j++;
		}
		
		else
			cadena[i] == cad1[j];
	}
	return cadena;
}
