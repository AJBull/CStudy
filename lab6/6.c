#include<stdio.h>


int fib_iter(int m,int k,int n)
{
	if(n==0)
		return 0;
	else if (n==1)
		return m;

	else
		return fib_iter(k+m,m,n-1);
}
int fib(int n)
{
	return fib_iter(1,0,n);	
}
int main(int argc, char *argv[])
{
	int i,f,M;
	if(argc!=2)
        {
                puts("usage: ./6 int_number");
                return 1;
        }

    	M=atoi(argv[1]);

	for(i=0;i<=M;i++)
		{
		 printf("%d->%d\n",i,fib(i));
		}
	return 0;
}
