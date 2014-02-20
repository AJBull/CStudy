#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "headfile.h"
void generate(char (*arr)[M], char sym, int count)
{
	int i, j;

	while(count)
	{
		i = rand() % (N / 2);
		j = rand() % (M / 2);
		if (arr[i][j] == ' ')
		{
			arr[i][j] = sym;
			count--;
		}
	}
}
void clear(char (*arr)[M])
{
	int i, j;
	
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			arr[i][j] = ' ';
}
void copy(char (*arr)[M])
{
	int i, j;

	for(i = 0; i < N/2; i++)
		for(j = 0; j < M/2; j++)
		{
			arr[i][M - j - 1] = arr[i][j];
			arr[N - i - 1][j] = arr[i][j];
			arr[N - i - 1][M - j - 1] = arr[i][j];
		}
}
void print(char (*arr)[M])
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
}
