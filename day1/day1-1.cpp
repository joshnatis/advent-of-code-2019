#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("input.txt");

	int total = 0;

	string num;
	while(getline(fin, num))
	{
		total += stoi(num) / 3 - 2;
	}

	cout << total << endl;
	fin.close();

	return 0;
}