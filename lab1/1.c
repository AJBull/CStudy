#include <stdio.h>
#include <string.h>

main() {
        char gender;
        float height, weight, mweight, gweight;

        printf("Enter your gender (m/f) : ");
        scanf("%c", &gender);

	if (!(gender == 'm' || gender == 'f'))
		{
		puts ("Wrong gender value");
		return 1;
		}        

	printf("Enter your height(cm) in xxx.x format: ");
        scanf("%f", &height);

  	if (height <= 100 || height > 220)
                {
                puts ("Wrong height value");
                return 1;
                }

        printf("Enter your weight(kg) in xx.x/xxx.x format: ");
        scanf("%f", &weight);

	if (weight <= 30 || weight > 130)
                {
                puts ("Wrong weight value");
                return 1;
                }

	
	mweight=(height-100)*0.9;
	gweight=(height-100)*0.85;



	if ( gender == 'm' && weight < mweight-6 || gender == 'f' && weight < gweight-6 )
		{
			puts ("Eat more");
		}
	else if (gender == 'm' && weight > mweight+6 || gender == 'f' && weight > gweight+6  )
		 {
                        puts ("Eat less");

                 }

	else
		 {
                        puts ("Your weight is OK");
                 }

return 0;
}
