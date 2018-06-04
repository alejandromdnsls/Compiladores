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
  random_string(s, 30);
  printf("%s\n", s);
  return 0;
}
