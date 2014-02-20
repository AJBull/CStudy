#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define g 9.81

int main() {
    float high,time;
    char mes[100]="Put in high in metres (0 for exit):\n";	
    char buf[BUFSIZ];
    char junk;
    bool ok = false;

    
 while(!ok)
    {
        fputs(mes, stdout);
        fflush(stdout);
        if(fgets(buf, BUFSIZ, stdin) == NULL)
        {
            if(!ferror(stdin))
            {
                fputs("No input available\n", stderr);
                exit(EXIT_FAILURE);
            }
            else
            {
                perror("stdin");
                clearerr(stdin);
                continue;
            }
        }
        if(sscanf(buf, "%f %c\n", &high, &junk) != 1)
        {
            fputs("Incorrect input\n", stderr);
            continue;
        }
        ok = true;
    }
    if (high<0)
	{
	puts("Error");
	return 1;	
	}	

    while(high!=0)
    {
        for(time=00;high > (g*time*time/2); time++){
	usleep(1000000);
        printf("t=%.0f sec --> h=%.1f metres\n", time, (high-g*time*time/2));}
        puts("<<<BABAH>>>");
	break;

    }
    return 0;
}

