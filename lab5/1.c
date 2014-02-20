#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** printwords(char* string, int * pcount)
{
char seps[] = " ,\t\n";
char * token;
char** outwords = NULL;


    printf( "Original words order:\n" );
    /* Establish string and get the first token: */
    token = strtok( string, seps );
    while( token != NULL )
    {
        /* While there are tokens in "string" */
  int len = strlen(token);
  (*pcount)++;
  outwords = (char**)realloc(outwords, (*pcount) * sizeof(char*));
  outwords[(*pcount) - 1] = (char*)calloc(len + 1, sizeof(char));
  strcpy(outwords[(*pcount) - 1], token);
        /* Get next token: */
        printf("%s ",token);
	token = strtok(NULL, seps);
    }
	putchar('\n');
    return outwords;
}
void getwords(char ***array, char ***parray)
{
 *parray = *array;
}

char * shuffle(char *array[], size_t n)
{
    srand(time(NULL));
    char *t;
    if (n > 1)
    {

        int i,j;
        for (i = 0; i < n - 1; i++)
        {
          j = i + rand() / (RAND_MAX / (n - i) + 1);
          t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
return (char *)array;
}



int main()
{
char str[256];
char** words = NULL;
char** pwords = NULL;
pwords = (char**)malloc(sizeof(char**));
int count=0;
int i=0;
puts("Enter a string");
fgets(str, 255, stdin);
words = printwords(str,&count);
getwords(&words,&pwords);
shuffle(pwords,count);
puts("Shuffled words order");
for (i = 0; i <count; i++)
{
  printf("%s ", pwords[i]);
}
  putchar('\n');
return 0;
}

