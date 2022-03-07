//Да се напише подходящо параметризирана функция lengthOfFile(...) която връща колко символа има в текстов файл.

#include <iostream>
#include <fstream>

using namespace std;

size_t LengthOfFile(const char fileName[])
{
	ifstream in;
	in.open(fileName);
	
	size_t counter = 0;

	if (in.is_open())
	{
		char symbol;

		while (!in.eof())
		{
			symbol = in.get();
			if (symbol != -1)
			{
				counter++;
			}
		}
	}

	return counter;
}

int main()
{
	char* nameOfFile = new char[20];
	cin.getline(nameOfFile, 20);

	cout << LengthOfFile(nameOfFile) << endl;
	
	return 0;
  
}
