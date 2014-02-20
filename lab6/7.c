#include <stdlib.h> 
#include <stdio.h> 


 
#define MEN 2 
#define LF 10 
#define SPACE 32 
#define ORIGINAL_dedale 0 
#define dedale_WITH_PATH 1

 
	int sorties_x;
	int sorties_y;
 
int** dedale; int sizex = 0, sizey = 0; 
int load_dedale() {
	int i, j, filesize = 0, x = 0, y = 0;
	char * cc;
	FILE *F;
	//Attampting to open text file for reading
	F = fopen("dedale.txt","rt");
	if( F==NULL )
		return 0;
        fseek(F, 0, SEEK_END); // seek to end of file
	filesize = ftell(F); // get current file pointer
	fseek(F, 0, SEEK_SET); // seek back to beginning of file
	//Making up array to store the bites from file:
	cc = (char*)malloc(sizeof(char)*filesize);
	//Loading teh bites from file to array
	for(i=0;i!=filesize;i++)
		cc[i] = getc(F);
	fclose(F);
	//Evaluating the sizes of labirynth matrix:
	i = 0;
	while(cc[i] != LF)
	{
		if(cc[i] != SPACE)
			sizex++;
		i++;
	}
	sizey = filesize/(sizex*2);
	//Labiynth matrix initializing:
	dedale = (int**)malloc(sizeof(int*)*sizey);
	while(y != sizey)
		dedale[y++] = (int*)malloc(sizeof(int)*sizex);
	//Fill the labirynth matrix the datas from file
	i=0;
	for(y = 0;y!=sizey;y++)
	{
		for(j=0;j!=sizex;j++)
		{
			dedale[y][x] = cc[i]-48;
			x++;
			i+=2;
		}
		x=0;
	}
	return 1;
}
 
int temp = MEN; int check(int x, int y) {
	int cnt = 0;
	if(x != 0 && dedale[y][x-1] == 0)
	{
		dedale[y][x-1] = temp+1;
		cnt++;
	}
	if(x != sizex-1 && dedale[y][x+1] == 0)
	{
		dedale[y][x+1] = temp+1;
		cnt++;
	}
	if(y != 0 && dedale[y-1][x] == 0)
	{
		dedale[y-1][x] = temp+1;
		cnt++;
	}
	if(y != sizey-1 && dedale[y+1][x] == 0)
	{
		dedale[y+1][x] = temp+1;
		cnt++;
	}
	return cnt;
}
 
int search_exit() {
	int x, y;
	sorties_x = 0;
	sorties_y = 0;
	y = 0;
	for(x = 0; x!=sizex; x++)
		if(dedale[y][x] == 0)
		{
			sorties_x = x;
			sorties_y = y;
			return 1;
		}
	y = sizey-1;
	for(x = 0; x!=sizex; x++)
		if(dedale[y][x] == 0)
		{
			sorties_x = x;
			sorties_y = y;
			return 1;
		}
	x = 0;
	for(y = 0; y!=sizey; y++)
		if(dedale[y][x] == 0)
		{
			sorties_x = x;
			sorties_y = y;
			return 1;
		}
	x = sizex-1;
	for(y = 0; y!=sizey; y++)
		if(dedale[y][x] == 0)
		{
			sorties_x = x;
			sorties_y = y;
			return 1;
		}
	return 0;
}
 
void print_dedale(char mode) {
	int x,y;
	for(y = 0; y!=sizey; y++)
	{
		for(x = 0; x!=sizex; x++)
		{
			if(dedale[y][x] == MEN)
				printf("M");
			else
			if(mode == 1 && dedale[y][x] == 0)
				printf("*");
			else
			if(dedale[y][x] > MEN)
				printf("0"); 
			else
				printf("%d",dedale[y][x]);
		}
		putchar('\n');
	}
}
 
int main() {
	int x, y, paths = 0, i = 1, steps, cnt = 0;
	if(load_dedale() == 0)
	{
		puts("\nFile dedale.txt not found.");
		return 0;
	}
	//Putting the labirynth matrix to console:
	printf("Labirynth:\r\n (%d x %d)\r\n",sizex, sizey);
	print_dedale(ORIGINAL_dedale);
	//Description:
	puts("\r\nM - Man\r\n1 - Wall\r\n0 - Gangway"); 
	//If there is no the edge element, which value is null, the labirynth is stubby
	if(search_exit() == 0)
	{
		puts("\r\nThe labirynth is stubby.");
		return 0;
	}
	printf("\r\n The exit coordinates:\r\nX =%d; Y =%d ",sorties_x,sorties_y);
	//Finding shortest way to labirynth exit:
	while(1)
	{
		
		for(y = 0; y!=sizey; y++)
		{
			for(x = 0; x!=sizex; x++)
			{
				if(dedale[y][x] == temp)
					paths += check(x,y); 
			}
		}
		if(paths == 0)
		{
			puts("\r\nThe labirynth is stubby.");
			return 0;
		}
 
		paths = 0;
		if(dedale[sorties_y][sorties_x] == 0)
			temp++;
		else
			break;
	}
	//Path to exit with length 'steps':
	steps = dedale[sorties_y][sorties_x];
	dedale[sorties_y][sorties_x] = 0;
	x = sorties_x;
	y = sorties_y;
	//Tracing the way by zeros:
	while(1)
	{
		if(x != 0 && dedale[y][x-1] == steps-i)
		{
			if(dedale[y][x-1] == 2)
				break;
			dedale[y][x-1] = 0;
			x--;
		}
		if(x != sizex-1 && dedale[y][x+1] == steps-i)
		{
			if(dedale[y][x+1] == 2)
				break;
			dedale[y][x+1] = 0;
			x++;
		}
		if(y != 0 && dedale[y-1][x] == steps-i)
		{
			if(dedale[y-1][x] == 2)
				break;
			dedale[y-1][x] = 0;
			y--;
		}
		if(y != sizey-1 && dedale[y+1][x] == steps-i)
		{
			if(dedale[y+1][x] == 2)
				break;
			dedale[y+1][x] = 0;
			y++;
		}
		i++;
	}
	printf("\r\nSymbol '*' - passed element:\r\n");
	print_dedale(dedale_WITH_PATH);
	printf("\r\nThe labirynth has been passed for %d steps\r\n",steps-2); 
	return 0;
}
