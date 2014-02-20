#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 8


int main()
{   
	char buf[N+1];
	int i,j;
    srand(time(0));
	for (j=0;j<M;j++)
{
	for (i=0;i<N;i++)
  
	switch(rand()%3) 
	{
	case 0: 
		buf[i]='0'+rand()%('9'-'0'+1);
		break;
	case 1: 
		buf[i]='A'+rand()%('Z'-'A'+1);
		break;
	case 2: 
		buf[i]='a'+rand()%('z'-'a'+1);
		break;

     }
	buf[N]=0;
	puts(buf);
}
return 0;
}
