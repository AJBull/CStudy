#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256


void bubble_sort(char chars[],int count[]  ,int size)
{
int i=0,j=0,k=0,tempcount=0;
char tempchar='\0';
    for(k=0;k<size;k++)
    for(i=1;i< size;i++)
    {
         for(j=0;j< size-1;j++)
         if(count[j]<count[j+1])
               {
                tempcount=count[j];
                        tempchar=chars[j];
                        count[j]=count[j+1];
                        chars[j]=chars[j+1];
                        count[j+1]=tempcount;
                        chars[j+1]=tempchar;

               }
    }
}



void chomp(char *str)
{
	if (str[strlen(str)-1]=='\n')
	str[strlen(str)-1]=0;
}
int main()
{
	int count[N]={0};
	unsigned char str[N];
        int i=0,totalcharcount=0;
	char chars[N]={0};
	puts("Hello, enter a string:");
	fgets(str,N,stdin);
	chomp(str);

while (str[i]){
	totalcharcount++;
	chars[str[i]]=str[i];
        count[str[i]]++;
        i++;
}

bubble_sort(chars,count,N);

    printf("Frequency Table\n");
    printf("----------------\n");
    printf("Char\tCount\t %% of Total\n");
    printf("--------------------------------\n");
    printf("All\t%d\n",totalcharcount);
    for ( i = 0; i < N; i++)
    if(count[i]>0) 
    printf("%c\t%d\t%.2f\n",chars[i],count[i],(float)count[i]/totalcharcount*100);		


return 0;
}
