#include <stdlib.h>
#include <stdio.h>


int **dummy(int **x, int n)
{
	int **y;
	int i;
	int j;

	i = 0;
	y = (int**)malloc(sizeof(int*) * (n + 1));
	while (i < n)
	{
		y[i] = (int*)malloc(sizeof(int) * n);
		j = 0;
		while(j < n)
		{
			y[i][j] = j;
			j++;
		}
		i++;
	}
	y[n] = x[0];
	return(y);
}

int main(int argc, char *argv[])
{
	int n;
	int **x;
	int i;
	int j;

	n = 10;
	i = 0;
	x = (int**)malloc(sizeof(int*) * n);
	while (i < n)
	{
		x[i] = (int*)malloc(sizeof(int) * n);
		j = 0;
		while(j < n)
		{
			x[i][j] = j;
			j++;
		}
		i++;
	}
	i = 0;
	int **temp = x;
	while(i < n)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	x = dummy(x, n);
	i = 0;
	while (i < n + 1)
	{
		j = 0;
		while (j < n)
		{
			printf("%d ", x[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	i = 0;
	while(i < n)
	{
		free(x[i]);
		i++;
	}
	free(x);
}
//sudo apt intall valgrind 
//sudo apt update
//gcc -o ProgramName ProgramName.c
//valgrind --leak-check = full ./ProgramName

