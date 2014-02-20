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



void ParseEven(char str[], int num)
{
    char s[MAX_SIZE];
    int count=0;
    s[0]='\0';
    char *token = strtok (str, "!;:,.?- ");
    while  (token  !=NULL)
    {
        if (count!=num-1)    { strcat (s,token); strcat (s," "); }
        token = strtok(NULL,"`!;:,.?- ");
        ++count;
    }

    strcpy(str,s);
}


int main() {
    char str[MAX_SIZE];
    int wordsNum,num;

    printf("Enter a string:\n ");
    fgets(str,MAX_SIZE,stdin); 
    printf("Enter a number:\n ");
    scanf("%d",&num);
    wordsNum = countWords(str);
    
    if (wordsNum < num || num < 1 )
	{
	printf("Error!!! The array's element with number %d doesn't exist\n ",num);
        return 1;
	}
    else {
    ParseEven(str,num);
    printf("Result: %s ",str);
}
    return EXIT_SUCCESS;
}

