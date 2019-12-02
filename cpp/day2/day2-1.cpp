#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector<int> LOAD_PROGRAM(string filename);
void VIEW_MEMORY(vector<int> &v);
int EXECUTE_INSTRUCTION(int opcode, int in1pos, int in2pos, int outpos, vector<int> &v);
void EXECUTE_PROGRAM(vector<int> &v);

int main(int argc, char **argv)
{
	if(argc != 2) return 1;
	
	vector<int> instructions = LOAD_PROGRAM(argv[1]);

	//restore gravity assist program
	instructions[1] = 12;
	instructions[2] = 2;

	VIEW_MEMORY(instructions);
	EXECUTE_PROGRAM(instructions);
	cout << endl;
	VIEW_MEMORY(instructions);

	return 0;
}

vector<int> LOAD_PROGRAM(string filename)
{
	vector<int> v;

	ifstream fin;
	fin.open(filename);

	string input;
	while(getline(fin, input, ','))
	{
		v.push_back(stoi(input));
	}

	return v;
}

void VIEW_MEMORY(vector<int> &v)
{
	int size = v.size();
	for(int i = 0; i < size - 1; ++i)
		cout << v[i] << ", ";
	cout << v[size - 1] << endl;
}

int EXECUTE_INSTRUCTION(int opcode, int in1pos, int in2pos, int outpos, vector<int> &v)
{
	if(opcode == 99) //immediately halt
		return 1;
	else if(opcode == 1)
		v[outpos] = v[in1pos] + v[in2pos];
	else if(opcode == 2)
		v[outpos] = v[in1pos] * v[in2pos];

	return 0;
}

void EXECUTE_PROGRAM(vector<int> &v)
{
	int halt;
	for(int i = 0, size = v.size(); i < size; i += 4)
	{
		halt = EXECUTE_INSTRUCTION(v[i], v[i+1], v[i+2], v[i+3], v);
		if(halt) break;
	}
}