#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char is_digit ( int x )
{
    return ( ( x <= '9' ) && ( x >='0' ) );
}
char is_char ( char x )
{
    return (! (( x <= '9' ) && ( x >='0' )) );
}
 
void swap ( char *beg, char *end )
{
    char t = *beg;
    *beg = *end;
    *end = t;
}
 
int main(void)
{
    unsigned char size = 0xff;
    char *beg, *end, str[ size ];
    //char *x = "MynameisAlexI'm29yearsoldIwasbornin1983";
    char *x = "1913-isbestyearofRussiain20century";  

    strcpy ( str, x );
    str[ strlen ( x ) ] = '\0';
    beg = &str;end = &str[ strlen ( x ) - 1 ];
 
    while ( beg != end )
    {
        if ( !is_digit( *beg ) )
        {
            beg++;
        }
	else if ( !is_char( *end ) ) 	
        


	{
            end--;
        }

	else
	{
	    swap (beg, end);
	    beg++;end--;
		
	}

    }
    printf ( "%s\n", x );
    printf ( "%s\n", str );
 
    return 0;
}
