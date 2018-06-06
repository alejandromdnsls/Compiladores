#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void random_string(char * string, unsigned length)
{
  /* Seed number for rand() */
  srand((unsigned int) time(0) + getpid());

  /* ASCII characters 33 to 126 */
  int i;
  for (i = 0; i < length; ++i)
    {
      string[i] = rand() % 94 + 33;
    }

  string[i] = '\0';
}

int main(void)
{
  char s[31];
  int a;
  int b;
  int * ap;
  int *otro;
  a=5;
  ap = &a;
  otro = &b;
  *otro=*ap;
  printf("%p\n", &a);
  printf("%p\n", ap);
  printf("%d\n", *ap);
  printf("%p\n", otro);
  printf("%p\n", &b);
  printf("%d\n", b);



  printf("%s\n", s);
  return 0;
}
