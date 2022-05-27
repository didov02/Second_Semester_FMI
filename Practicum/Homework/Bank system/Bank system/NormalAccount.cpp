#include "NormalAccount.h"

NormalAccount::NormalAccount() : Account()
{

}

NormalAccount::NormalAccount(char* newUsername, char* newPassword, char* newIBAN, size_t newID, double newMoney) : 
	Account(newUsername, newPassword, newIBAN, newID, newMoney)
{

}

NormalAccount::NormalAccount(const NormalAccount& other) : Account(other)
{

}

void NormalAccount::display() const
{
	std::cout << "Type of account: Normal" << std::endl;
	std::cout << "IBAN: " << this->IBAN << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "Balance: " << this->amountOfMoney << std::endl;
}

Account* NormalAccount::clone() const
{
	return new NormalAccount(*this);
}
