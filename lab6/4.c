#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
long int recSum(long int* arr,int K)
{
  if(K==1)
        return arr[0];
    else
        return recSum(arr,K/2)+
        recSum(arr+K/2,K-K/2);
}

long int sum_array(long int* arr, int K)
{
   int i, sum=0;
   for (i=0; i<K; i++)
   {
	 sum = sum + arr[i];
   }
   return(sum);
   
}



 
int main (int argc, char *argv[])
 
{
    int i=0;
    int N, M;
    long int *str;
    
   if(argc!=2)
        {
                puts("usage: ./4 int_number");
                return 1;
        }
    
    M=atoi(argv[1]);
    N=pow(2,M);
    printf("N = %d\n", N);    
    str = (long int*)malloc(N*sizeof(long int));   
    srand(time(NULL));
    
    for(i=0;i<N;i++) 
        str[i]=rand()%100;

    puts("<<<---Sum counting by cycle method--->>>");
    clock_t start_cycle = clock();
    sum_array(str, N);
    clock_t end_cycle = clock();
    double dif_cycle = ((double) (end_cycle - start_cycle)*10) / CLOCKS_PER_SEC;
    printf("The resulting sum by cycle method is %ld. Counted for %f seconds\n\n", sum_array(str, N), dif_cycle);
    
    puts("<<<---Sum counting by recursive method--->>>");
    clock_t start_rec = clock();
    recSum(str, N);
    clock_t end_rec = clock();
    double dif_rec = ((double) (end_rec - start_rec)*10) / CLOCKS_PER_SEC;
    printf("The resulting sum by recursive method is %ld. Counted for %f seconds\n", recSum(str, N), dif_rec);

    free(str);
    
    return 0;
}
