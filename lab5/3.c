#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char** printwords(char* string, int * pcount)
{
char seps[] = " ,\t\n";
char * token;
char** outwords = NULL;
(*pcount)=0;

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
        token = strtok(NULL, seps);
    }
    return outwords;
    free(outwords);
}
void getwords(char ***array, char ***parray)
{
 *parray = *array;
}

void shuffle(char * a, int n)
{
      int i = n - 2;
      int j;
      char temp;

      srand(time(NULL));

      while (i > 0)
      {
            j = 1 + (rand() % (i));
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = i - 1;
      }
}


char * charshuffle(char *array[], size_t n)
{
        int i=0,len=0;
        for (i=0;i<n;i++)
                {
                len=0;
                len = strlen(*(array+i));
                shuffle(*(array+i),len);
                }

return (char *)array;
}






int main(int argc, char *argv[] ){
  int x = 0,i=0, lineCount = 0, maxlen = 0;
  char c;
  char line[500];
  char** words = NULL;
  char** pwords = NULL;  
  pwords = (char**)malloc(sizeof(char**));
  int count=0;

  FILE *file = fopen( argv[1], "r" ); 
  if (file == NULL){
    printf("Cannot open file\n");
    exit(1);
  } 
  
puts("Original words order");
while ((c=getc(file))!=EOF)
	putchar(c);
rewind(file);

puts("Shuffled words order");
  while (x<500 && fgets(line,sizeof(line), file) ){
      x++;
	words = printwords(line,&count);
	getwords(&words,&pwords);
	charshuffle(words,count);
	for (i = 0; i <count; i++)
		{  
	printf("%s ", pwords[i]);
		} 
        putchar('\n');   
}
   fclose(file);
   free(pwords);
   return 0;
}
