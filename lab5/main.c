#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "headfile.h"
int main()
{
	int sym = 3;
	int count = N / 2 * M / 2 / 2;
	char arr[N][M];
	while(1)
	{
		clear(arr);
		generate(arr, sym, count);
		copy(arr);
		system("cls");
		print(arr);
		Sleep(2000);
	}

	return 0;
}

