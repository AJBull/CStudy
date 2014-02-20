# include <stdio.h>

#define M 500
#define N 500

char arr [M][N];

void print()
{
	int i,j;
	for(i=0;i<N;i++) {
		for(j=0;j<M;j++) {
			putchar(' ');
			putchar(arr[i][j]);
		}
		putchar('\n');
	}
}

int pov(int n, int m)
{
	int i,res=1;
	for(i=1;i<=m;i++)
		res=res*n;
	return res;
}

void draw(int y, int x, int k)
{
	int delta=pov(3,k-1);
	if(k==0) {
		arr[y][x]='*';
	} else {
		draw(y,x,k-1);
		draw(y-delta,x,k-1);
		draw(y+delta,x,k-1);
		draw(y,x-delta,k-1);
		draw(y,x+delta,k-1);
	}
	// printf("y-%d,x-%d,delta-%d\n", y,x,delta);
}
int main ()
{
	int k;
	printf("Enter K: ");
	scanf ("%d", &k);
	draw(N/2,M/2,k);
	print();
	return 0;

}
