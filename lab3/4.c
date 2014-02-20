

#include <stdio.h>
#include <stdlib.h>


int main() {
  int arr[100], idx=0, d, l=0;
  char *p;
  int sum=0,strsize=0; 
  char *str = calloc(100, sizeof(char));

  puts("Enter a mixed string");
  fgets(str,99,stdin);
;
  for (p = str; *p != 0; p+=l) {
    l = 1;
    if (isdigit(*p)){
      sscanf(p, "%4d%n", &d, &l);//Let's our numbers will be no more then 4 digits ones.
      sum+=arr[idx++] = d;
      
    }   
  }   
  for (l=0; l<idx; l++) {
    printf("%d\n", arr[l]);
  }
printf ("Summ=%d\n",sum);
  return 0;
}


