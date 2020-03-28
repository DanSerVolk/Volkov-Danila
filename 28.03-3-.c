#include <stdio.h>

char itsString[10];
int A[10];

void fatoi(char *itsString)
{
  int i, j, dig=0;

  for (i=0; i<10; i++)
  {
    A[i]=itsString[i];
  }
}

int main()
{
  char c;
  int i;
  printf ("Input string: \n ");

  fgets( itsString, 10, stdin );
  fatoi(itsString);
  for (i=0; i<10; i++)
  {
    printf("%d",A[i]);
  }
return 0;
}
