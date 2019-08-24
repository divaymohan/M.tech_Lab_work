#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *bubbleSort(int *, int);
int *insertionSort(int *, int);

int main(int argc, char *argv[])
{

	FILE *r;
	FILE *o;

	r = fopen(argv[1], "r");
	int n;
	fscanf(r, "%d", &n);
	int arr[n], arr1[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(r, "%d", &arr[i]);
		arr1[i] = arr[i];
	}
	clock_t start, end;
	double bubbleTime = 0, insertionTime = 0;
	//calculating bubbleSort Time
	for (int i = 0; i < 100; i++)
	{
		start = clock();
		bubbleSort(arr, n);
		end = clock();
		bubbleTime = bubbleTime + ((double)(end - start) / CLOCKS_PER_SEC);

		start = clock();
		insertionSort(arr1, n);
		end = clock();
		insertionTime = insertionTime + ((double)(end - start) / CLOCKS_PER_SEC);
	}
	bubbleTime = bubbleTime / 100;
	insertionTime = insertionTime / 100;
	o = fopen(argv[2], "a");
	printf("For %d Bubble Sort Time = %f \n", n, bubbleTime);
	printf("For %d Insertion Sort Time = %f\n", n, insertionTime);
	printf("%d", n);
	fprintf(o, "%d ,%f , %f\n", n, bubbleTime, insertionTime);
	fclose(r);
	fclose(o);
}
int *bubbleSort(int *in, int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (in[j] > in[j + 1])
			{
				temp = in[j];
				in[j] = in[j + 1];
				in[j + 1] = temp;
			}
		}
	}
	return in;
}

int *insertionSort(int *in, int size)
{
	int i = 1, key, j;
	while (i < size)
	{
		key = in[i];
		j = i - 1;
		while (j >= 0 && in[j] > key)
		{
			in[j + 1] = in[j];
			j--;
		}
		in[j + 1] = key;
		i++;
	}
	return in;
}
