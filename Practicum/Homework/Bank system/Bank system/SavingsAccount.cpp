#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account()
{
	interestRate = 0;
}

SavingsAccount::SavingsAccount(char* newUsername, char* newPassword, char* newIBAN,
	size_t newID, double newMoney, double newInterestRate) : Account(newUsername, newPassword, newIBAN, newID, newMoney)
{
	this->interestRate = newInterestRate;
}

SavingsAccount::SavingsAccount(const SavingsAccount& other) : Account(other)
{
	this->interestRate = other.interestRate;
}

bool SavingsAccount::withdraw(size_t money)
{
	return false;
}

void SavingsAccount::display() const
{
	std::cout << "Type of account: Savings" << std::endl;
	std::cout << "IBAN: " << this->IBAN << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Balance: " << this->amountOfMoney << std::endl;
}

Account* SavingsAccount::clone() const
{
	return new SavingsAccount(*this);
}



