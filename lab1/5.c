#include <stdio.h>
#include <string.h>

int main()
{
    int a = 200;
    char string[255];
    int length = strlen(string);

    printf ("Enter a string:");
scanf ("%s", &string);

	printf ("%*s%*c"
            ,((a - length) >> 1) + length // string length + padding spaces
            , string
            , ((a - length) >> 1) + ((a - length) & 1) // tailing spaces
            , ' '
    );
    printf ("\n");
}
