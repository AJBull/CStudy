#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 11

int main( void )
{
   int i  = 0;
   int a[N];
   int neg = 0;
   int pos = 0;
   int ipos=0;
   int ineg=0;
   int sum=0;

   srandom( (int) time(NULL) );
   a[0]=random( ) % 100 ;

for (i=1;i<N;i++)
     {
       a[i]=(random( )% 100) -(random( )% 100) ;
       printf("%d\n", a[i]);
}
for (i=0;i<N;i++) {
       if (a[i] < 0)
            {
          neg = a[i];
          ineg=i;break;
            }
}
for (i=N-1;i>0;i--) {
       if (a[i] > 0)
            {
          pos = a[i];
          ipos=i;break;
            }
    }
for (i=ineg+1;i<ipos;i++)
{
sum+=a[i];

}
           printf("Neg: %d %d\n", neg,ineg);
            printf("Pos: %d %d\n", pos,ipos);
	    printf("Sum: %d\n",sum);
return 0;
}
