#include <stdio.h>
#include <string.h>

int main () {

char str[127];
char *pstr;
char sy,msy;
int len=0, i, count=0,maxcount=0;
puts("Enter string:");
fgets(str,127,stdin);
pstr=str;
len=strlen(pstr)-1;
for (i=0;i<len;i++) {
if ( pstr[i+1] == pstr[i] )
{
sy=pstr[i];
count++;
}
else {
if (count>maxcount)
{
msy=sy;
maxcount=count;
}
sy='\0';
count=0;
}
}
printf("%d\t",maxcount+1);
for(i=0;i<maxcount+1;i++)
{
printf("%c",msy);
}
putchar('\n');
return 0;
}
