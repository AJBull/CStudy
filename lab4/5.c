#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAX 100
#define LEN 80


  int cmp(const void *a, const void *b)
{
    return (strlen((const char*)a) - strlen((const char*)b));
}



void chomp(char *s)
{
	if(s[strlen(s) - 1] =='\n')
		s[strlen(s) - 1]=0;
}

int main(int argc, char *argv[])
{
	char text[MAX][LEN];
	char *rows[MAX];
	int count=0, i;

	FILE *infp, *outfp;

	if(argc!=3)
	{
		puts("usage: ./5 inputfilename outputfilename");
		return 1;
	}
	infp=fopen(argv[1], "rt");
	if (infp == NULL) {
		puts("INFILE ERROR");
		return 1;
	}
        outfp=fopen(argv[2], "w"); 
       if (outfp == NULL) {
                puts("OUTFILE ERROR");
                return 2;
        }



	while (count<MAX && fgets(text[count], LEN, infp))
	{
		chomp(text[count]);
		rows[count] = text[count];
		count++;
	}

 	qsort(*rows, count, sizeof(char) *LEN, cmp);


	for(i=0; i<count; i++)
	{
		fputs(rows[i], outfp);
		fputs("\n",outfp);
	}
        fclose(infp);
	fclose(outfp);	

	return 0;
}

