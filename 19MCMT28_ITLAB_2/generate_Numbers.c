#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *r;
	int c, n;
	c = atoi(argv[1]);
	//generate 3000 numbers
	r = fopen(argv[2], "w");
	//random numbers
	fprintf(r, "%d\n", c);
	srand(50);
	for (int i = 0; i < c; i++)
	{
		n = (rand());
		fprintf(r, "%d\n", n);
	}
	fclose(r);
	return 0;
}
