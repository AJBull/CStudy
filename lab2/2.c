#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
     
        char str[50];
	int s,x;
	int n=0;	
	
	srand(time(0));
	s=rand()%100 + 1;

	do 
	{
        printf("I've thought of a natural number from 1 to 100. Try to guess: ");
        scanf("%d", &x);
	n++;
	if (s<x) printf("Less \n", n);
	if (s>x) printf("More \n", n);
	}
	while (s-x);
	
	printf("You've got it! \n");
	printf("You've spent %d attempts \n", n);

return 0;
}

