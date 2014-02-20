
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "8.h"

char *prog;
void eval_exp(double *answer);

int main(int argc, char *argv[])
{
  int i=0;
  double answer;
  char *p = NULL;
  p = (char *) realloc(p, argc * sizeof(char));
  if(!p) {
    printf("Ошибка при выделении памяти.\n");
    exit(1);
  }


    
    for (i=1; i<argc; i++)
    {
        p=join(p,argv[i]);
    }
    prog = p;
    check_char();
    eval_exp(&answer);
    printf("Результат: %.2f\n", answer);
    free(p);
  return 0;
}


