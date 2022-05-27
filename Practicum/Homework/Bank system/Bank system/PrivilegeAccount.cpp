#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount() : Account()
{
	overdraft = 0;
}

PrivilegeAccount::PrivilegeAccount(char* newUsername, char* newPassword, char* newIBAN,
size_t newID, double newMoney, double newOverdraft) : Account(newUsername, newPassword, newIBAN, newID, newMoney)
{
	this->overdraft = newOverdraft;
}

PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount& other) : Account(other)
{
	this->overdraft = other.overdraft;
}

bool PrivilegeAccount::withdraw(size_t money)
{
	if (money > this->amountOfMoney + overdraft)
	{
		return false;
	}

	this->amountOfMoney -= money;

	return true;
}

void PrivilegeAccount::display() const
{
	std::cout << "Type of account: Privilege" << std::endl;
	std::cout << "IBAN: " << this->IBAN << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Balance: " << this->amountOfMoney << std::endl;
}

Account* PrivilegeAccount::clone() const
{
	return new PrivilegeAccount(*this);
}