#include <stdio.h>
#include <string.h>

void chomp(char *s);

int main ()
{
  char str[128];
  char * pch;
  char * word;
  int countchar=0;
  int maxcountchar=0;
  puts("Enter a string:");
  fgets(str,128,stdin);
  chomp(str);
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    countchar=strlen(pch);
    if (countchar>maxcountchar)
	{
	maxcountchar=countchar;
	word=pch;
	}

    pch = strtok (NULL, " ,.-");
  }
    printf("The longest word is %s-->%d\n",word,maxcountchar);
  return 0;
}

void chomp(char *s) {
    while(*s && *s != '\n' && *s != '\r') s++;

    *s = 0;
}

