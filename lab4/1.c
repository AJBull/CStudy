#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 80

char *gets_s(char *s, int n) 
{
    int i, c;
    for (i = 0; i < n - 1 && (c = getchar()) != EOF && c != (int)'\n'; i++)
        s[i] = c;
    s[i] = '\0';
    while (n > 1 && c != EOF && c != (int)'\n')
        c = getchar();
    return c != EOF ? s : NULL;
}

  int cmp(const void *a, const void *b) 
{
    return (strlen((const char*)a) - strlen((const char*)b));
}



int main(void) 
{
 char text[MAX][LEN];
 char *rows[MAX];
 int count = 0;
 int t, i, j;

 printf("Put empty string for exit.\n");

 for(t=0; t<MAX; t++)
 {
  printf("%d: ", t);
  memset(text[count], 0, LEN);
  gets_s(text[count], LEN);
  rows[count]=text[count];
  if(!*text[t]) break; 
  count++;
 }

 printf("\nUnsorted:\n");
 for ( i = 0; i < count; i++ )
  printf("%s\n", rows[i]);

 qsort(*rows, count, sizeof(char) *LEN, cmp);

 printf("\nSorted by length:\n");
 for ( i = 0; i < count; i++ )
  printf("%s\n", rows[i]);
 


 return 0;
}
