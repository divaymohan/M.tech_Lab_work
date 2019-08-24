#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void QuickSort(int *, int, int);
int partition(int *, int, int);
void printList(int *, int);
int noSwaps = 0;
int noComp = 0;
int main(int argc, char const *argv[])
{
	FILE *fp;
	FILE *op;
	fp = fopen(argv[1], "r");
	op = fopen(argv[2], "a");
	int n;
	double sorting_time = 0;
	clock_t start, end;
	fscanf(fp, "%d", &n); //reading no of input values
	int *arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &arr[i]);
	}
	//print element before sorting
	int p = 0;
	int r = n - 1;
	//printList(arr,n);
	//sort the elements/
	for (int i = 0; i < 100; i++)
	{
		start = clock();
		QuickSort(arr, p, r);
		end = clock();
		sorting_time += ((double)(end - start) / CLOCKS_PER_SEC);
	}
	sorting_time = sorting_time / 100;
	fprintf(op, "\nOutput For %s", argv[1]);
	fprintf(op, "\ntime :: %f", sorting_time);
	fprintf(op, "\n no of Swap:: %d", noSwaps);
	fprintf(op, "\n mo of Comparision %d:: ", noComp);

	return 0;
}

void QuickSort(int *arr, int p, int r)
{
	int q;
	if (r - p > 0)
	{
		q = partition(arr, p, r);
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}

int partition(int *arr, int p, int r)
{
	int pivot = arr[r];
	int temp;
	int i = p - 1, j = r;
	int n = r - p + 1;
	while (i < j)
	{
		noComp++;
		if (arr[j] <= pivot)
		{
			temp = arr[++i];
			arr[i] = arr[j];
			arr[j] = temp;
			noSwaps++;
		}
		else
		{
			j--;
		}
	}
	return i;
}
void printList(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
