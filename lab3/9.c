#include <stdio.h>
#include <string.h>

int main () {

char str[127];
char sy,msy;
int len=0, i, count=0,maxcount=0;
puts("Enter string:");
fgets(str,127,stdin);
len=strlen(str)-1;
for (i=0;i<len;i++) {
if ( str[i+1] == str[i] )
{
sy=str[i];
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
