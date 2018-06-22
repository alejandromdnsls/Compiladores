//Librerias
#include <stdio.h>
#include <stdlib.h>
#include "op_cadenas.h"

/*
int main(){
  char* cad1 = "simon ";
  char* cad2 = "adios";
  char* concat;

  //concat = inversa(cad1);
  concat = potencia(cad1,-2);
  printf("%s\n", concat);

  return 0;
}
*/
int len_cadena(char* cad){
  int i = 0;
  while(cad[i]) i++;
  return i;
}

char* concatenar(char* cad1, char* cad2){
  char* cadena;
  cadena = malloc(len_cadena(cad1)+1);
  int len_cadena1 = len_cadena(cad1);
  int len_cadena2 = len_cadena(cad2);
  int i, j;

  for(i = 0; i < len_cadena1; i++) cadena[i] = cad1[i];

  for(j = 0; j < len_cadena2; j++){
    cadena[i] = cad2[j];
    i++;
  }

  cadena[i] = '\0';

  return cadena;
}

/*
char* resta(char*cad1,char*cad2)
{
    int i=0,j=0,k=0;
    int len_cadena1, len_cadena2;
    char *aux;
    len_cadena1=len_cadena(cad1);
    len_cadena2=len_cadena(cad2);
    aux=malloc(len_cadena1+len_cadena2);
    while(cad1[i]!='\0')
    {
        if(cad1[i]==cad2[j])
        {
            i++;
            j++;
        }
        else
        {
            aux[k]=cad1[i];
            i++;
            k++;
        }
    }
    if(j!=len_cadena2)
    {
        aux = cad1;
    }
    aux[k]='\0';
    return aux;
}*/
/*
 char*potencia(char*cad1, int n){
   char*cadena;
   int i, j;
   int len_cadena1 = len_cadena(cad1);
   cadena = malloc(len_cadena1*n);
   if(n>0){
     for(i = 0; i<n; i++){
       cadena=concatenar(cadena, cad1);
     }
   }
   else if(n<0){
     char*cad_nueva;
     cad_nueva = inversa(cad1);

     for(i = 0; i<n; i++){
       cadena=concatenar(cadena, cad_nueva);
     }
   }
   return cadena;
 }

 char*inversa(char*cad1){
   char*cadena;
   int len_cadena1=len_cadena(cad1);
   int i,j;
   cadena=malloc(len_cadena1+1);
   for(i = 0 ,j = len_cadena1-2; i<len_cadena1-1;i++){
     //printf("%c\n", cad1[j]);
     cadena[i] = cad1[j];
     j--;
   }
   cadena[i] = '\0';
   return cadena;
 }*/

char* resta(char*cad1, char*cad2){
  char* cadena;
  int i, j, k, flag=0;
  cadena = malloc(len_cadena(cad1)+1);
  if(len_cadena(cad2)>0){
    for(i=0, k=0; i<len_cadena(cad1);i++){
      for(j=0; j<len_cadena(cad2)&&flag==0;j++){
        if(cad1[i+j] == cad2[j]){
          continue;
        }
        else{
          break;
        }
      }
      if(j==len_cadena(cad2)){
        flag=1;
        i=i+j-1;
        j=-1;
      }
      else{
        cadena[k] = cad1[i];
        k++;
      }
    }
    cadena[k] = '\0';
  }
  else{
    cadena=cad1;
  }
  return cadena;
}
