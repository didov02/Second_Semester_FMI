#include "Bank.h"

void ExceptionForAccount(bool isThere)
{
	if (!isThere)
	{
		throw "There isn't an account with such id.";
	}
}

void ExceptionForCustomer(bool isThere)
{
	if (!isThere)
	{
		throw "There isn't a customer with such id.";
	}
}

void ClearSyncIgnore()
{
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
}

void Bank::copy(const Bank& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->address = new char[strlen(other.address) + 1];
	strcpy(this->address, other.address);

	this->customers = other.customers;

	this->log = other.log;

	for (int i = 0; i < other.accounts.getSize(); i++)
	{
		this->accounts.pushBack(other.accounts[i]->clone());
	}
}

void Bank::free()
{
	delete[] name;
	delete[] address;

	size_t accountsCount = accounts.getSize();

	for (int i = 0; i < accountsCount; i++)
		delete accounts[i];

	accounts.clear();

	size_t logCount = log.getSize();

	for (int i = 0; i < logCount; i++)
		delete log[i];

	log.clear();
}

Bank::Bank()
{
	name = nullptr;
	address = nullptr;
}

Bank::Bank(char* newName, char* newAddress, Vector<Customer> newCustomers, Vector<Account*> newAccounts, Vector<char*> newLog)
{
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);

	this->address = new char[strlen(newAddress) + 1];
	strcpy(this->address, newAddress);

	this->customers = newCustomers;

	this->accounts = newAccounts;

	this->log = newLog;
}

Bank::Bank(const Bank& other)
{
	copy(other);
}

Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Bank::~Bank()
{
	free();
}

void Bank::addCustomer(size_t newID, char* newName, char* newAddress)
{
	Customer tempCustomer;
	tempCustomer.setID(newID);
	tempCustomer.setName(newName);
	tempCustomer.setAddress(newAddress);

	customers.pushBack(tempCustomer);

	char* message = new char[MAX_COMMAND];
	strcpy(message, "New customer is added.");

	log.pushBack(message);;
}

void Bank::deleteCustomer(size_t searchingID)
{
	size_t customersCount = customers.getSize();
	size_t wantedID;
	bool isThere = false;

	for (int i = 0; i < customersCount; i++)
	{
		if (searchingID == customers[i].getID())
		{
			wantedID = i;
			isThere = true;
			break;
		}
	}
	
	ExceptionForCustomer(isThere);

	customers.popAt(wantedID);

	char* message = new char[MAX_COMMAND];
	strcpy(message, "Customer is deleted.");

	log.pushBack(message);
}

void Bank::addAccount(char* typeOfAccount, char* newUsername, char* newPassword, char* newIBAN, size_t newID, double newMoney)
{
	Account* tempAccount;
	if (strcmp(typeOfAccount, "Normal") == 0)
	{
		tempAccount = new NormalAccount(newUsername, newPassword, newIBAN, newID, newMoney);
	}
	else if (strcmp(typeOfAccount, "Privilege") == 0)
	{
		std::cout << "What overdraft do you want: ";
		double newOverdraft;
		std::cin >> newOverdraft;

		tempAccount = new PrivilegeAccount(newUsername, newPassword, newIBAN, newID, newMoney, newOverdraft);
	}
	else if (strcmp(typeOfAccount, "Savings") == 0)
	{
		std::cout << "What interest rate do you want: ";
		double newInterestRate;
		std::cin >> newInterestRate;

		tempAccount = new SavingsAccount(newUsername, newPassword, newIBAN, newID, newMoney, newInterestRate);
	}

	accounts.pushBack(tempAccount);

	char* message = new char[MAX_COMMAND];
	strcpy(message, "New account is added.");

	log.pushBack(message);

	ClearSyncIgnore();//!
}

void Bank::deleteAccount(size_t searchingID)
{
	size_t accountsCount = accounts.getSize();
	size_t wantedID;
	bool isThere = false;

	for (int i = 0; i < accountsCount; i++)
	{
		if (searchingID == accounts[i]->getID())
		{
			wantedID = i;
			isThere = true;
			break;
		}
	}

	ExceptionForAccount(isThere);

	accounts.popAt(wantedID);

	char* message = new char[MAX_COMMAND];
	strcpy(message, "Account is deleted.");

	log.pushBack(message);
}

void Bank::listCustomers() const
{
	size_t customersCount = customers.getSize();

	for (int i = 0; i < customersCount; i++)
	{
		std::cout << i + 1 << ". " << customers[i].getName();
		std::cout <<", " << customers[i].getID();
		std::cout <<", " << customers[i].getAddress() << std::endl;
	}

	if (customersCount == 0)
	{
		std::cout << "No customers added yet." << std::endl;
	}
}

void Bank::listAccounts() const
{
	size_t accountsCount = accounts.getSize();

	for (int i = 0; i < accountsCount; i++)
	{
		time_t time = accounts[i]->getTime();
		std::cout << i + 1 << ". " << accounts[i]->getUsername();
		std::cout <<", " << accounts[i]->getID();
		std::cout <<", " << accounts[i]->getIBAN();
		std::cout <<", " << accounts[i]->getBalance();
		std::cout <<", " << ctime(&time) << std::endl;
	}
	
	if (accountsCount == 0)
	{
		std::cout << "No accounts added yet." << std::endl;
	}
}

void Bank::listCustomerAccount(size_t searchingID) const
{
	size_t accountsCount = accounts.getSize();
	bool isThere = false;

	for (int i = 0; i < accountsCount; i++)
	{
		if (searchingID == accounts[i]->getID())
		{
			for (int j = 0; j < customers.getSize(); j++)
			{
				if (searchingID == customers[j].getID())
				{
					isThere = true;
					time_t time = accounts[i]->getTime();
					std::cout <<"- " << accounts[i]->getUsername();
					std::cout << ", " << accounts[i]->getID();
					std::cout << ", " << accounts[i]->getIBAN();
					std::cout << ", " << accounts[i]->getBalance();
					std::cout << ", " << ctime(&time) << std::endl;
					break;
				}
			}

			if (isThere)
				break;
		}
	}

	ExceptionForCustomer(isThere);

	if (accountsCount == 0)
	{
		std::cout << "No accounts added yet." << std::endl;
	}
}

void Bank::listLog() const
{
	size_t logCount = log.getSize();

	for (int i = 0; logCount; i++)
	{
		std::cout << log[i] << std::endl;
	}

	if (logCount == 0)
	{
		std::cout << "Log is empty." << std::endl;
	}
}

void Bank::exportLog() const
{
	std::fstream exportFile("transactions.txt", std::ios::out);

	size_t logCount = log.getSize();

	for (int i = 0; i<logCount; i++)
	{
		exportFile << log[i] << std::endl;
	}

	exportFile.close();
}

void Bank::transfer(double wantedAmount, char* fromIBAN, char* toIBAN)
{
	size_t accountsCount = accounts.getSize();
	bool firstIBANExist = false;
	bool secondIBANExist = false;

	for (int i = 0; i < accountsCount; i++)
	{
		if (strcmp(fromIBAN, accounts[i]->getIBAN()) == 0)
		{
			firstIBANExist = true;
			break;
		}
	}

	if (!firstIBANExist)
	{
		throw "This IBAN does not exist";
	}

	for (int i = 0; i < accountsCount; i++)
	{
		if (strcmp(toIBAN, accounts[i]->getIBAN()) == 0)
		{
			secondIBANExist = true;
			break;
		}
	}

	if (!secondIBANExist)
	{
		throw "This IBAN does not exist";
	}

	for (int i = 0; i < accountsCount; i++)
	{
		if (strcmp(fromIBAN, accounts[i]->getIBAN()) == 0)
		{
			if (accounts[i]->getBalance() - wantedAmount < 0)
			{
				throw "Cannot withdraw such amout of money from this account!";
			}
			else
			{
				accounts[i]->withdraw(wantedAmount);
				char* message = new char[MAX_COMMAND];
				strcpy(message, "New withdraw is made.");

				log.pushBack(message);

				for (int j = 0; j < accountsCount; j++)
				{
					if (strcmp(toIBAN, accounts[j]->getIBAN()) == 0)
					{
						accounts[j]->deposit(wantedAmount);
						char* message = new char[MAX_COMMAND];
						strcpy(message, "New deposit is made.");

						log.pushBack(message);

						break;
					}
				}
			}

			break;
		}
	}

	char* message = new char[MAX_COMMAND];
	strcpy(message, "Transfer is made.");

	log.pushBack(message);
}

void Bank::display() const
{
	std::cout << "Bank name: " << this->name << std::endl;
	std::cout << "Bank address: " << this->address << std::endl;
	std::cout << "Bank customers count: " << customers.getSize() << std::endl;
	std::cout << "Bank account count: " << accounts.getSize() << std::endl;
}

void Bank::withdrawMoney(size_t searchingID, size_t money)
{
	size_t accountsCount = accounts.getSize();
	bool isThere = false;

	for (int i = 0; i < accountsCount; i++)
	{
		if (searchingID == accounts[i]->getID())
		{
			accounts[i]->withdraw(money);
			isThere = true;
			break;
		}
	}

	ExceptionForAccount(isThere);
}

void Bank::depositMoney(size_t searchingID, size_t money)
{
	size_t accountsCount = accounts.getSize();
	bool isThere = false;

	for (int i = 0; i < accountsCount; i++)
	{
		if (searchingID == accounts[i]->getID())
		{
			accounts[i]->deposit(money);
			isThere = true;
			break;
		}
	}

	ExceptionForAccount(isThere);
}

const char* Bank::getAccountIBAN(size_t searchingID)
{
	size_t accountsCount = accounts.getSize();
	bool isThere = false;

	for (int i = 0; i < accountsCount; i++)
	{
		if (searchingID == accounts[i]->getID())
		{
			isThere = true;
			return accounts[i]->getIBAN();
		}
	}

	ExceptionForAccount(isThere);
}

void Bank::setName(char* newName)
{
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void Bank::setAddress(char* newAddress)
{
	this->address = new char[strlen(newAddress) + 1];
	strcpy(this->address, newAddress);
}
