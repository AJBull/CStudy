#include <stdio.h>
#define M 2.54 
#define N 12

int main() {
        int foots, inches;
        float centimeters;

        printf("Enter height in foots & inches pair: \n");
        scanf("%d %d", &foots, &inches);
	
	if (foots < 0 || inches < 0 || foots > 8 || inches > 11)
	{
		puts("Wrong input values");
		return 1;
	}
	


	centimeters=(foots*N + inches)*M;
	printf("The height in centimeters is %.2f",centimeters);
	printf("\n");

	return 0;
} 
