#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 11

int main( void )
{
   int i  = 0;
   int a[N];

   int min = 0;
   int max = 0;
   int temp=0;
   int imin=0;
   int imax=0;
   int sum=0;

   srandom( (int) time(NULL) );
   a[0]=random( ) % 100 ;
   min = a[0];

for (i=1;i<N;i++)
     {
       a[i]=(random( )% 100) -(random( )% 100) ;


       printf("%d\n", a[i]);

       if (a[i] > max)
            {
          max = a[i];
          imax=i;
            }
       if (a[i] < min)
            {
          min = a[i];
          imin=i;
            }
    }
if (imin > imax)
{
temp=imax;
imax=imin;
imin=temp;
}
 
for (i=imin+1;i<imax;i++)
{
sum+=a[i];

}
           printf("Min: %d %d\n", min,imin);
            printf("Max: %d %d\n", max,imax);
	    printf("Sum: %d\n",sum);
return 0;
}
