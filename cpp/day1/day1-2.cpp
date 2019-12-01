#include <fstream>
#include <iostream>

using namespace std;

int calculateFuel(int num, int total);

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int total = 0;

	string num;
	while(getline(fin, num))
	{
		total = calculateFuel(stoi(num), total);
	}

	cout << total << endl;
	fin.close();

	return 0;
}

int calculateFuel(int num, int total)
{
	int fuel = num / 3 - 2;
	if(fuel <= 0) return total;

	total += fuel;
	return calculateFuel(fuel, total);
}