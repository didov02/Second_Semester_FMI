#include "System.h"

void System::copy(const System& other)
{
	size = other.size;
	capacity = other.capacity;

	for (int i = 0; i < size; i++)
		users[i] = other.users[i];
}

void System::free()
{
	delete[] users;
}

void System::resize()
{
	User* temp = new User[capacity *= 2];

	for (int i = 0; i < size; i++)
		temp[i] = users[i];

	delete[] users;
	users = temp;
	temp = nullptr;
}

System::System()
{
	size = 0;
	capacity = 2;

	users = new User[capacity];
}

System::System(const System& other)
{
	copy(other);
}

System& System::operator=(const System& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

System::~System()
{
	free();
}

void System::addUser(const User& user)
{
	bool exist = false;

	for (int i = 0; i < size; i++)
	{
		char* tempEmail = new char[strlen(user.getEmail()) + 1];
		strcpy(tempEmail, user.getEmail());
		if (users[i].isUserAlreadyRegistrated(tempEmail));
		{
			exist = true;
			std::cout << "User with this email is already registrated!" << std::endl;
			delete[] tempEmail;
			break;
		}
		
		delete[] tempEmail;
	}


	if (!exist)
	{
		if (size + 1 >= capacity)
			resize();

		users[size++] = user;
	}
}
void System::removeUser(char* email)
{
	bool exist = false;

	for (int i = 0; i < size; i++)
	{
		if (users[i].isUserAlreadyRegistrated(email))
		{
			exist = true;

			users[i] = users[size - 1];
			users[size - 1].deleteCurrentUser();
			size--;

			break;
		}
	}

	if (!exist)
		std::cout << "There isn't an user with such email. Try again!" << std::endl;
}

void System::printUsers() const
{
	for (int i = 0; i < size; i++)
		users[i].print();
}

void System::login(const User& user) const
{
	bool isLoged = false;

	for (int i = 0; i < size; i++)
	{
		if ((strcmp(users[i].getEmail(), user.getEmail()) == 0) &&
			strcmp(users[i].getPassword(), user.getPassword()) == 0)
		{
			std::cout << "Welcome, " << user.getName() << std::endl;
			isLoged = true;
			break;
		}
	}

	if (!isLoged)
	{
		std::cout << "There isn't such user! Try again!" << std::endl;
	}
}

void System::save(std::ofstream& outFile)
{
	for (int i = 0; i < size; i++)
	{
		outFile << users[i].getName() << std::endl;
		outFile << users[i].getEmail() << std::endl;
		outFile << users[i].getPassword() << std::endl << std::endl;
	}
}
