//Напишете функция, която приема име на съществуващ файл и име и копира съдържанието на същестуващия файл в нов файл.

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 1024;
const int MAX_NAME_SIZE = 20;

void Copy(char name[MAX_NAME_SIZE])
{
	fstream newFile;
	newFile.open("new.txt", ios::app);

	if (!newFile.is_open())
	{
		cout << "Error!" << endl;
	}
	else
	{
		ifstream currentFile(name);

		while (!currentFile.eof())
		{
			char buffer[MAX_SIZE];
			currentFile.getline(buffer, MAX_SIZE);
			newFile << buffer << endl;
		}

		currentFile.close();
	}

	newFile.close();
}

int main()
{
	char name[MAX_NAME_SIZE];
	cin >> name;

	Copy(name);

	return 0;
}
