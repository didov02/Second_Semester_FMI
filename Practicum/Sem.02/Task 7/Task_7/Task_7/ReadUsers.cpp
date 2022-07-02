#include "ReadUsers.h"

void readUsers(std::ifstream& inFile, System& system)
{
	while (!inFile.eof())
	{
		char* buff = new char[MAX_SIZE];
		inFile.getline(buff, MAX_SIZE);

		if (buff[0] != '\n')
		{
			User temp;
			temp.setName(buff);

			char* email = new char[MAX_SIZE];
			inFile.getline(email, MAX_SIZE);
			temp.setEmail(email);

			char* password = new char[MAX_SIZE];
			inFile.getline(password, MAX_SIZE);
			temp.setPassword(password);

			system.addUser(temp);

			delete[] email;
			delete[] password;
		}

		delete[] buff;
	}
}