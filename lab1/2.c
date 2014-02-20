#include <stdio.h>
 
main() {
	int hh, mm, ss;
	int i;
 
	printf("Enter a timestamp (hh:mm:ss): ");
	scanf("%d:%d:%d", &hh, &mm, &ss);
 
	if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59 ) {puts ("Wrong format of timestamp");}
	else if (hh >= 4 && hh < 10 ) {puts ("Good Morning");}
		else // when the years are equal			if (hh  >= 10 && hh < 18) {puts ("Good afternoon");}
			else
				if (hh >= 18 && hh < 23) {puts ("Good evening");}
				else // when the years and months are equal
					{puts ("Good night");}

			
}

