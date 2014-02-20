

    #include<stdio.h>
    #include<time.h>

    int Fibonacci(int);
    int main(int argc, char *argv[])
    {
    int n, i = 0, c,f;
    FILE  *outfp;

        if(argc!=3)
        {
                puts("usage: ./5 int_number outputfilename");
                return 1;
        }
        n=atoi(argv[1]);
        if (n < 0) {
                puts("int_number should be non-negative");
                return 1;
        }
        outfp=fopen(argv[2], "w");
        if (outfp == NULL) {
                puts("OUTFILE ERROR");
                return 2;
        }

    printf("Fibonacci series\n");
    for ( c = 0 ; c <= n ; c++ )
    {
    clock_t start = clock();
    f=Fibonacci(i);
    clock_t end = clock();
    double dif = ((double) (end - start)*10) / CLOCKS_PER_SEC;
    printf("%d-->%d-->%f\n", i,f,dif);
    fprintf(outfp, "%d-->%d-->%f\n", i,f,dif);
    i++;
    }
    fclose(outfp);
    return 0;
    }


    int Fibonacci(int n)
    {
    if ( n == 0 )
    return 0;
    else if ( n == 1 )
    return 1;
    else
    return ( Fibonacci(n-1) + Fibonacci(n-2) );
    } 


