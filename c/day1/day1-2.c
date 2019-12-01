#include <stdio.h>
#include <stdlib.h>

int calculateFuel(int num, int *original);

int main()
{
	FILE *fptr;
	fptr = fopen("input.txt", "r");

	int total = 0;

	char line[20]; //20 is an arbitrary limit, the lines have a max of 6 characters
	while(fgets(line, 20, fptr))
	{
		total += calculateFuel(strtol(line, NULL, 10), &total);
	}

	printf("%d\n", total);

	return 0;
}

int calculateFuel(int num, int *original)
{
	int fuel = num / 3 - 2;
	if(fuel <= 0) return 0;

	*original += fuel;
	return calculateFuel(fuel, original);
}