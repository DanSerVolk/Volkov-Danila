#include <stdio.h>

int nubmer_c(char *itsString, char c)
{
int i, j, dig=0;

  for (i=0; i<10; i++)
  {
    if (itsString[i]==c)
      return i;
  }
return -1;
}

int main()
{
  char c;
  printf ("Input char and string by spaces: \n ");
  scanf("%c", &c);

  char itsString[10];
  fgets( itsString, 10, stdin );

  printf("nubmer:%d", nubmer_c(itsString, c));
  return 0;
}
