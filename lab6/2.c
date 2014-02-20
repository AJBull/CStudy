#include<stdio.h>
#include<stdlib.h>


typedef unsigned long long col; 
col collatz(col number, unsigned * 
count, col * kmax) {
	if (number == 1) return 1;
	else {
		(*count)++;
		if (number % 2) {
			col know = number*3+1;
			if (know>*kmax) *kmax=know;
			return collatz(know, count, kmax);
		}
		else
			return collatz(number / 2, count, kmax);
	}
}
int main() {
	unsigned count=1, max=1, i=2, value=1;
	char c;
	while (1) {
		count = 1; //Cos "1" should be included into the sequence
		col kmax=1;
		collatz(i, &count, &kmax);
		if (count > max) {
			max = count;
			value = i;
			printf("The next longest Collatz's sequence is of %u\n with maximum number of %llu for %u\n\n", max, kmax, value);
			puts("Press any key for continuing and 'q' for exit");
			c=getchar();
			if (c == 113) exit(0);
			puts("Wait, please");
			
		}
		i++;
	}
	return 0;
}
