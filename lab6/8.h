#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define DELIMITER 1
#define VARIABLE  2
#define NUMBER    3

extern char *prog;   /* This one contains the equation for analyzing */
char token[80];
char tok_type;

void eval_exp(double *answer), eval_exp2(double *answer);
void eval_exp3(double *answer), eval_exp4(double *answer);
void eval_exp5(double *answer);
void atom(double *answer);
void get_token(void), putback(void);
void serror(int error);
int isdelim(char c);
void check_char(void);

/* The point of entrance for analyzer. */
void eval_exp(double *answer)
{
  get_token();
  if(!*token) {
    serror(2);
    return;
  }
  eval_exp2(answer);

  if(*token) serror(0);
}

/* Addition or subtraction. */
void eval_exp2(double *answer)
{
  register char  op;
  double temp;

  eval_exp3(answer);
  while((op = *token) == '+' || op == '-') {
    get_token();
    eval_exp3(&temp);
    switch(op) {
      case '-':
        *answer = *answer - temp;
        break;
      case '+':
        *answer = *answer + temp;
        break;
    }
  }
}

/* Multiplication or division. */
void eval_exp3(double *answer)
{
  register char op;
  double temp;

  eval_exp4(answer);
  while((op = *token) == '*' || op == '/') {
    get_token();
    eval_exp4(&temp);
    switch(op) {
      case '*':
        *answer = *answer * temp;
        break;
      case '/':
        if(temp == 0.0) {
          serror(3); /* Division by zero */
          *answer = 0.0;
        } else *answer = *answer / temp;
        break;
    }
  }
}



void eval_exp4(double *answer)
{
  register char  op;

  op = 0;
  if((tok_type == DELIMITER) && *token=='+' || *token == '-') {
    op = *token;
    get_token();
  }
  eval_exp5(answer);
  if(op == '-') *answer = -(*answer);
}


/* The evaluation of the expression in brackets. */
void eval_exp5(double *answer)
{
  if((*token == '(')) {
    get_token();
    eval_exp2(answer);
    if(*token != ')')
      serror(1);
    get_token();
  }
  else
    atom(answer);
}

/* Retrieving the value in brackets. */
void atom(double *answer)
{
  if(tok_type == NUMBER) {
    *answer = atof(token);
    get_token();
    return;
  }
 
}

/* Expression tokens from the input stream. */
void putback(void)
{
  char *t;

  t = token;
  for(; *t; t++) prog--;
}

/* Displaying an error message. */
void serror(int error)
{
  static char *e[]= {
      "Sintax error",
      "Unbalanced brackets",
      "No expression",
      "Division by zero",
      "Invalid Symbol"
  };
  printf("%s\n", e[error]);
  exit(1);
}

/* Returns the next token. */
void get_token(void)
{
  register char *temp;

  tok_type = 0;
  temp = token;
  *temp = '\0';

  if(!*prog) return; /* The expression's termination */
  while(isspace(*prog)) ++prog; /* miss the spaces,
                  tabs and null string */

  if(strchr("+-*/=()", *prog)){
    tok_type = DELIMITER;
    /* turn to the next symbol */
    *temp++ = *prog++;
  }
  else if(isalpha(*prog)) {
    while(!isdelim(*prog)) *temp++ = *prog++;
    tok_type = VARIABLE;
  }
  else if(isdigit(*prog)) {
    while(!isdelim(*prog)) *temp++ = *prog++;
    tok_type = NUMBER;
  }

  *temp = '\0';
}

/* True if  Ó is delimiter. */
int isdelim(char c)
{

  if(strchr(" +-/*=()", c) || c==9 || c=='\r' || c==0)
    return 1;
  return 0;
}

char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    assert(result);
    strcat(strcpy(result, s1), s2);

    return result;
    free(result);
}

void check_char(void)
{
if ( strspn(prog, " 0123456789+-*()/") != strlen(prog) )
serror(4);
}
