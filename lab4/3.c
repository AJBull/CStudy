#include<stdio.h>
#include<string.h>

void chomp(char *s)
{
        if(s[strlen(s) - 1] =='\n' || s[strlen(s) - 1] =='\r' )
                s[strlen(s) - 1]=0;
}

int main()
{
 char str[100];
 char *p,*t;
 printf("Your string : ");
 fgets(str,sizeof(str),stdin);
 chomp(str);
 for(p=str ; *p!= '\0' ; p++);
  for(t=str, p-- ; p>=t; )
  {
    if(*p==*t)
    {
        p--;
        t++;
    }
    else
        break;
  }
  
  if(t>p)
       printf("\nPalindrome\n");
  else
       printf("\nNot a palindrome\n");
  return 0;
}
