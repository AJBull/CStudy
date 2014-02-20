#include <stdio.h>
#include <string.h>
 
void chomp(char *s)
{
        if(s[strlen(s) - 1] =='\n' || s[strlen(s) - 1] =='\r')
                s[strlen(s) - 1]=0;
}


int main(int argc, char *argv[])
{
    char array[100];
    char *pch;
    char *reverse[20];
    unsigned char index=0;
    char i=0;
    unsigned char length=0;
 
    printf("Enter the string\n");
    fgets(array,100,stdin);
    chomp(array);
    length = strlen(array);
    pch = strtok (array," \0");
    reverse[index++] = pch;
 
    while (pch != NULL)
     {
       pch = strtok (NULL, " ");
       reverse[index++] = pch;
     }
    index--;


    for(i=index-1; i >= 0; i-- )
        printf("%s ",reverse[i]);
 
putchar('\n');


    return 0;
}
