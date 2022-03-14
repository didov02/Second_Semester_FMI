//Реализирайте структура User, която да съдържа име, имейл и парола на даден потребител. Всяко поле е с максимална дължина 128 символа. 
//Създайте възможност за записване и четене на потребител в текстов файл.
//Реализирайте структура System, която има масив от User-и. Системата поддържа максимално 100 потребители. 
//Създайте методи за запазване и прочитане на обект от тип System от файл. (Помислете за подходящ формат за записването на данните)
//Имплементирайте проста login система, която поддържа възможност за регистриране на нов потребител и вход в системата.
//След спиране на програмата и повторно пускане, трябва да се запази възможността вече регистрирани потребители да влизат в системата с имейла и паролата си.

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE_USER = 128;
const int MAX_USERS = 100;
const int MAX_COMMAND = 10;

struct User
{
	char name[MAX_SIZE_USER];
	char email[MAX_SIZE_USER];
	char password[MAX_SIZE_USER];
};

struct System
{
	User users[MAX_USERS];
	size_t usersCount = 0;
};

bool checkUserRegister(System system, User user)
{
	for (int i = 0; i < system.usersCount; i++)
	{
		if (system.users[i].email == user.email)
		{
			return true;
		}
	}

	return false;
}

bool checkUserLogin(System system, User user)
{
	for (int i = 0; i < system.usersCount; i++)
	{
		if (system.users[i].email == user.email && system.users[i].password == user.password)
		{
			return true;
		}
	}

	return false;
}

bool createUser(System system,User& user)
{
	bool isThereSuchUser = checkUserRegister(system, user);
	if (isThereSuchUser)
	{
		cout << "There is already an user with the same email." << endl;
		return false;
	}
	
	cout << "Enter name:" << endl;
	cin.getline(user.name, MAX_SIZE_USER);

	cout << "Enter email:" << endl;
	cin.getline(user.email, MAX_SIZE_USER);

	cout << "Enter password:" << endl;
	cin.getline(user.password, MAX_SIZE_USER);

	cout << "Registration successful" << endl;

	return true;
}

void addUser(System& system, User user)
{
	ofstream out;
	out.open("file.txt");

	if (!out.is_open())
	{
		cout << "Error!" << endl;
	}

	out << user.name << endl;
	out << user.email << endl;
	out << user.password << endl << endl;

	out.close();

	system.users[system.usersCount++] = user;
}

void loginUser(System system)
{
	User user;
	cout << "Enter email:" << endl;
	cin.getline(user.email, MAX_SIZE_USER);

	cout << "Enter password:" << endl;
	cin.getline(user.password, MAX_SIZE_USER);

	bool isUserInSystem = checkUserLogin(system, user);

	if (isUserInSystem)
	{
		cout << "Login successful" << endl;
	}
	else
	{
		cout << "Login unsuccessful" << endl << "There is not an user with such email or such password." << endl;
	}
}

//void readFromFile(System& system)
//{
//	ifstream file;
//	file.open("file.txt");
//
//	if (!file.is_open())
//	{
//		cout << "Error!" << endl;
//	}
//
//	char name[MAX_SIZE_USER];
//	char email[MAX_SIZE_USER];
//	char password[MAX_SIZE_USER];
//
//	while (file >> name >> email >> password)
//	{	
//		User user;
//		user.name = name;
//		user.email = email;
//		user.password = password;
//
//		system.users[system.usersCount++] = user;
//	}
//}

int main()
{
	System system;

	//if (system.usersCount == 0)
	//{
	//	readFromFile(system);
	//}

	while (true)
	{
		char command[MAX_COMMAND];
		cout << "Enter command:" << endl;
		cin.getline(command, MAX_COMMAND);

		if (command == "login")
		{
			loginUser(system);
		}
		else if (command == "register")
		{
			User currentUser = system.users[system.usersCount];
			bool check = createUser(system, currentUser);

			if (check)
			{
				addUser(system, currentUser);
			}
		}
		else if (command == "exit")
		{
			cout << "See you later!" << endl;
			break;
		}
		else
		{
			cout << "There is not such command. Please try again. " << endl;
		}
	}

	return 0;
}
