#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 255


int countWords(char str[]) {
    int inWord = 0,
        n,
        i,
        nOfWords = 0;

    n = strlen(str);

    for (i = 0; i <= n; i++) {
        if (isalnum(str[i]))
            inWord = 1;
        else
            if (inWord) {
                inWord = 0;
                nOfWords++;
            }
    }

    return nOfWords;
}



int main ()
{
  char str[MAX_SIZE];
  char * pch;
  int i=0,num,wordsNum;
  printf("Enter a string:\n ");
  fgets(str,sizeof(str),stdin);
  printf("Enter a number:\n ");
  scanf("%d",&num);
  
      wordsNum = countWords(str);

    if (wordsNum < num || num < 1 )
        {
        printf("Error!!! The array's element with number %d doesn't exist\n ",num);
        return 1;
        }
    else {

  pch = strtok (str," ,.-");
  for (i=1;i<num;i++)
{
    pch = strtok (NULL, " ,.-");	
}  

printf ("%s\n",pch);
}
  return 0;
}


