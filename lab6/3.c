#include <stdio.h>

static char *itoa_recursive_helper(int value, char* str, int base) {
  if (value <= -base) {
    str = itoa_recursive_helper(value / base, str, base);
    value %= base;
  }
  *str++ = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[-value];
  *str = '\0';
  return str;
}

char* itoa_recursive(int value, char* str, int base) {
  char *original = str;
  if (value < 0) {
    *str++ = '-';
  } else {
    value = -value;
  }
  itoa_recursive_helper(value, str, base);
  return original;
}



int main()
{
int digit=0;
char string[10];

puts("Enter an integer");
scanf("%d",&digit);
itoa_recursive(digit,string,10);
printf("%s\n",string);
return 0;
}
