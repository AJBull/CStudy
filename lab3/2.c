#include <stdio.h>
#include <string.h>

void chomp(char *s);

int main ()
{
  char str[128];
  char * pch;
  int countchar=0;
  int countwords=0;
  puts("Enter a string:");
  fgets(str,128,stdin);
  chomp(str);
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  while (pch != NULL)
  {
    countchar=strlen(pch);
    countwords++;
    printf ("%s-->%d\n",pch, countchar);
    pch = strtok (NULL, " ");
  }
    printf("Total:%d\n",countwords);
  return 0;
}

void chomp(char *s) {
    while(*s && *s != '\n' && *s != '\r') s++;
 
    *s = 0;
}
