#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	fptr = fopen("input.txt", "r");

	int total = 0;

	char line[20]; //20 is an arbitrary limit, the lines have a max of 6 characters
	while(fgets(line, 20, fptr))
	{
		total += strtol(line, NULL, 10) / 3 - 2;
	}

	printf("%d\n", total);

	fclose(fptr);
}