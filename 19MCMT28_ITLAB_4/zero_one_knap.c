#include <stdio.h>
#include <stdlib.h>
#define INFINITE -999999
int max(int, int);
int main(int argc, char *argv[])
{
	FILE *in_fp = fopen(argv[1], "r");
	FILE *o_fp = fopen(argv[2], "w");
	int w, n;
	fscanf(in_fp, "%d", &w);
	fscanf(in_fp, "%d", &n);
	int *v, *W;
	v = (int *)malloc(n * sizeof(int));
	W = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		fscanf(in_fp, "%d", &v[i]);
	}
	for (int i = 0; i < n; i++)
	{
		fscanf(in_fp, "%d", &W[i]);
	}

	//just declaring a 2-d array for dynamic approach
	int ks[n + 1][w + 1];
	for (int i = 0; i <= w; i++)
	{
		ks[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ks[i][0] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (i == 0 && j == 0)
			{
				ks[i][j] = 0;
			}
			else if (W[i - 1] > j)
			{
				ks[i][j] = ks[i - 1][j];
			}
			else
			{
				ks[i][j] = max((v[i - 1] + ks[i - 1][j - W[i - 1]]), ks[i - 1][j]);
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			printf("%d\t", ks[i][j]);
		}
		printf("\n");
	}
	fprintf(o_fp, "%d\n", ks[n][w]);

	//Logic to calculate the profit vector or solution vector
	int max = ks[n][w];
	int solVec[n];
	int n1 = n;
	for (int i = 0; i < n; i++)
	{
		solVec[i] = 0;
	}
	while (max != 0)
	{
		if (ks[n][w] == ks[n - 1][w - W[n - 1]] + v[n - 1])
		{
			solVec[n - 1] = 1;
			w = w - W[n - 1];
			max = max - v[n - 1];
			n = n - 1;
		}
		else
		{
			n = n - 1;
		}
	}
	for (int i = 0; i < n1; i++)
	{
		fprintf(o_fp, "%d ", solVec[i]);
	}
	fprintf(o_fp, "\n");
	for (int i = 0; i < n1; i++)
	{
		if (solVec[i] == 1)
			fprintf(o_fp, "%d ", i + 1);
	}

	return 0;
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
