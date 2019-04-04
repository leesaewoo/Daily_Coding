#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char c = '\t';
  
  printf("%d\n", iscntrl(c));
  
  return 0;
}
