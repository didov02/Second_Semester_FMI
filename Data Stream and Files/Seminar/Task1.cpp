//Напишете програма, която отпечатва собствения си код.

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 1024;

int main()
{
	ifstream file;
	file.open("c++.cpp");

	if (!file.is_open())
	{
		cout << "Error!" << endl;
		return 1;
	}

	while (!file.eof())
	{
		char buffer[MAX_SIZE];
		file.getline(buffer, MAX_SIZE);
		cout << buffer << endl;
	}
	
	file.close();

	return 0;
}
