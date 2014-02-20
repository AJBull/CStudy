#include <stdio.h>
    
    printn(c, n){
            while( --n >= 0 )
                    putchar(c);
    }
    int main(argc, argv) char *argv[];
    {
			 int lines; /* number of triangle's lines */
             int nline; /* The string's number */
             int naster; /* The quantity of asterisks in line */
             int i;
	puts("Enter the number of string for triangle drawing");
	scanf("%d",&lines);
	
            if( argc > 1 )
                    lines = atoi( argv[1] );
            for( nline=0; nline < lines ; nline++ ){
                    naster = 1 + 2 * nline;
                    /* Leading spaces */
                    printn(' ', lines-1 - nline);
                    /* asterisks */
                    printn('*', naster);
                    /* string return */
                    putchar( '\n' );
            }
            return 0; }
