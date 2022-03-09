//Напишете програма, която отпечатва собствения си код.

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 1024;

int main()
{
	ifstream in;
	in.open("c++.cpp");
	while (!in.eof())
	{
		char buffer[MAX_SIZE];
		in.getline(buffer, MAX_SIZE);
		cout << buffer << endl;
	}

	in.close();

	return 0;
}
