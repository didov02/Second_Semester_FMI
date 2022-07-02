#include "User.h"

void User::copy(const User& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	
	email = new char[strlen(other.email) + 1];
	strcpy(email, other.email);
	
	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);
}

void User::free()
{
	delete[] name;
	delete[] email;
	delete[] password;
}

User::User()
{
	name = new char[1];
	name[0] = '\0';
	
	email = new char[1];
	email[0] = '\0';
	
	password = new char[1];
	password[0] = '\0';
}

User::User(char* name, char* email, char* password)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

User::User(const User& other)
{
	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

void User::setName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void User::setEmail(char* email)
{
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}

void User::setPassword(char* password)
{
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

const char* User::getName() const
{
	return name;
}

const char* User::getEmail() const
{
	return email;
}

const char* User::getPassword() const
{
	return password;
}

bool User::isUserAlreadyRegistrated(char* email) const//check with email
{
	if (strcmp(this->email, email) == 0)
		return true;

	return false;
}

void User::print() const
{
	std::cout << "User's name: " << name << std::endl;
	std::cout << "User's email: " << email << std::endl;
	std::cout << "User's password: " << password << std::endl << std::endl;
}

void User::deleteCurrentUser()
{
	this->free();
}
