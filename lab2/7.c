    #include <stdio.h>
    #include <stdlib.h>
    int main()
    {
    int i;
    char TC; /* Character variable to count text and load ASCII array */
    int TL = 0; /* Counters the number of characters in the entered text line */
    int AA[128] = {0}; /* Array which stores the frequency of the the characters in
    the entered text line that corresponds with its ASCII value.*/
    printf("Enter a line of text: ");
    TC = getchar();	//CC-1
    while (TC != '\n')	//CC-1
    {
    TL++; /* Counts each character */
    AA[(int)TC]++; /* Increments array element that corresponds with the character's
    ASCII value */ //CC-3 it's better to type cast though it will work
    TC = getchar();
    }
    printf("Frequency Table\n");
    printf("----------------\n");
    printf("Char\tCount\t %% of Total\n");
    printf("--------------------------------\n");
    printf("All\t%d\n",TL);
    for ( i = 0; i < 127; i++)
    if(AA[i]>0)	//modified portion
    printf("%c\t%d\t%.2f\n",i,AA[i],(float)AA[i]/TL*100);
    return 0;
    }

