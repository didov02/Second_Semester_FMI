#include "Account.h"

void Account::copy(const Account& other)
{
	this->username = new char[strlen(other.username) + 1];
	strcpy(this->username, other.username);

	this->password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);

	this->IBAN = new char[strlen(other.IBAN) + 1];
	strcpy(this->IBAN, other.IBAN);

	this->id = other.id;

	this->amountOfMoney = other.amountOfMoney;

	timeCreated = other.timeCreated;
}

void Account::free()
{
	delete[] username;
	delete[] password;
	delete[] IBAN;
	id = 0;
	amountOfMoney = 0;
}

Account::Account()
{
	username = nullptr;
	password = nullptr;
	IBAN = nullptr;
	id = 0;
	amountOfMoney = 0;
}

Account::Account(char* newUsername, char* newPassword, char* newIBAN, size_t newID, double newMoney)
{
	this->username = new char[strlen(newUsername) + 1];
	strcpy(this->username, newUsername);

	this->password = new char[strlen(newPassword) + 1];
	strcpy(this->password, newPassword);

	this->IBAN = new char[strlen(newIBAN) + 1];
	strcpy(this->IBAN, newIBAN);

	this->id = newID;

	this->amountOfMoney = newMoney;

	timeCreated = time(NULL);
}

Account::Account(const Account& other)
{
	copy(other);
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Account::~Account()
{
	free();
}

void Account::setUsername(char* newUsername)
{
	this->username = new char[strlen(newUsername) + 1];
	strcpy(this->username, newUsername);
}

void Account::setPassword(char* newPassword)
{
	this->password = new char[strlen(newPassword) + 1];
	strcpy(this->password, newPassword);
}

void Account::setIBAN(char* newIBAN)
{
	this->IBAN = new char[strlen(newIBAN) + 1];
	strcpy(this->IBAN, newIBAN);
}

void Account::setID(size_t newID)
{
	this->id = newID;
}

void Account::setAmountOfMoney(double newMoney)
{
	this->amountOfMoney = newMoney;
}

void Account::setTime()
{
	this->timeCreated = time(NULL);
}

const char* Account::getUsername() const
{
	return username;
}

const char* Account::getPassword() const
{
	return password;
}

const char* Account::getIBAN() const
{
	return IBAN;
}

size_t Account::getID() const
{
	return id;
}

time_t Account::getTime() const
{
	return timeCreated;
}

void Account::deposit(size_t money)
{
	this->amountOfMoney += money;
}

bool Account::withdraw(size_t money)
{
	if (money > amountOfMoney)
	{
		return false;
	}

	this->amountOfMoney -= money;

	return true;
}

void Account::display() const
{
	std::cout << "Username: " << this->username << std::endl;
	std::cout << "IBAN: " << this->IBAN << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Balance: " << this->amountOfMoney << std::endl;
}

double Account::getBalance() const
{
	return amountOfMoney;
}