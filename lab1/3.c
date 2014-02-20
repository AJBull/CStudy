#include <stdio.h>
#define PI 3.14159265
 
int main() {
	char scale;
	float trianglemeasure;
 
	printf("Enter triangle measure value with D(Degrees) or R(Radians) termination: ");
	scanf("%f%c", &trianglemeasure, &scale);
	if (scale == 'D') 
		{
		printf("You've entered the triangle measure in Degrees scale --> %f%c", trianglemeasure, scale);
		printf("\n");
		trianglemeasure = trianglemeasure * (PI / 180.0);
		scale='R';
		printf("trianglemeasure in Radians scale is %f%c", trianglemeasure, scale);
		printf("\n");
		}
	else 
		if (scale == 'R')

{
                printf("You've entered the triangle measure in Radians scale -->  %f%c", trianglemeasure, scale);
                printf("\n");
		trianglemeasure = trianglemeasure * (180.0 / PI);
                scale='D';
                printf("triangle measure in Degrees scale is %f%c", trianglemeasure, scale);
                printf("\n");
		}
	else 

		{
		puts("Wrong format of triangle measure");	
		}		

		return 0;
}
