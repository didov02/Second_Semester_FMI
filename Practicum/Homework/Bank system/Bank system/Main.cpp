#include "Bank.h"
#include "Menu.h"

int main()
{
	Bank ourBank;

	std::cout << "What is your bank's name: ";
	char* bankName = new char[MAX_COMMAND];
	std::cin.getline(bankName, MAX_COMMAND);

	std::cout << "What is your bank's address: ";
	char* bankAddress = new char[MAX_COMMAND];
	std::cin.getline(bankAddress, MAX_COMMAND);

	ourBank.setName(bankName);
	ourBank.setAddress(bankAddress);

	Menu();

	while (true)
	{
		bool ignoreIsNeeded = false;

		std::cout << "Your choice:" << std::endl;

		char* command = new char[MAX_COMMAND];
		std::cin.getline(command, MAX_COMMAND);

		if (strcmp(command, "Edit") == 0)
		{
			std::cout << "What would you like to edit: Customer OR Account" << std::endl;

			char* editCommand = new char[MAX_COMMAND];
			std::cin.getline(editCommand, MAX_COMMAND);

			if (strcmp(editCommand, "Customer") == 0)
			{
				std::cout << "Would you like to: " << std::endl;
				std::cout << "Add new customer OR Delete customer" << std::endl;

				char* editCustomer = new char[MAX_COMMAND];
				std::cin.getline(editCustomer, MAX_COMMAND);

				if (strcmp(editCustomer, "Add new customer") == 0)
				{
					std::cout << "New customer's name: ";
					char* name = new char[MAX_COMMAND];
					std::cin.getline(name, MAX_COMMAND);

					std::cout << "New customer's id: ";
					size_t id;
					std::cin >> id;
					ClearSyncIgnore();//!

					std::cout << "New customer's address: ";
					char* address = new char[MAX_COMMAND];
					std::cin.getline(address, MAX_COMMAND);

					ourBank.addCustomer(id, name, address);

					delete[] name;
					delete[] address;
				}
				else if (strcmp(editCustomer, "Delete customer") == 0)
				{
					std::cout << "Customer's id you want to delete: ";
					size_t id;
					std::cin >> id;
					ClearSyncIgnore();//!

					ourBank.deleteCustomer(id);
				}

				delete[] editCustomer;
			}
			else if (strcmp(editCommand, "Account") == 0)
			{
				std::cout << "Would you like to: " << std::endl;
				std::cout << "Add new account OR Delete account" << std::endl;

				char* editAccount = new char[MAX_COMMAND];
				std::cin.getline(editAccount, MAX_COMMAND);

				if (strcmp(editAccount, "Add new account") == 0)
				{
					std::cout << "What account do you want to create: " << std::endl;
					std::cout << "Normal OR Privilege OR Savings." << std::endl;
					char* typeOfAccount = new char[MAX_COMMAND];
					std::cin.getline(typeOfAccount, MAX_COMMAND);

					std::cout << "New account's username: ";
					char* username = new char[MAX_COMMAND];
					std::cin.getline(username, MAX_COMMAND);

					std::cout << "New account's password: ";
					char* password = new char[MAX_COMMAND];
					std::cin.getline(password, MAX_COMMAND);

					std::cout << "New account's IBAN: ";
					char* IBAN = new char[MAX_COMMAND];
					std::cin.getline(IBAN, MAX_COMMAND);

					std::cout << "New account's ID: ";
					size_t id;
					std::cin >> id;

					std::cout << "New account's money: ";
					double money;
					std::cin >> money;

					ourBank.addAccount(typeOfAccount, username, password, IBAN, id, money);

					delete[] username;
					delete[] password;
					delete[] IBAN;
					delete[] typeOfAccount;
				}
				else if (strcmp(editAccount, "Delete account") == 0)
				{
					std::cout << "Account's id you want to delete: ";
					size_t id;
					std::cin >> id;
					ClearSyncIgnore();//!

					ourBank.deleteAccount(id);
				}

				delete[] editAccount;
			}
			else
			{
				std::cout << "No such option. Try again!" << std::endl;
			}

			delete[] editCommand;
		}
		else if (strcmp(command, "List") == 0)
		{
			ignoreIsNeeded = true;

			std::cout << "What would you like to list:" << std::endl;
			std::cout << "- List all customers" << std::endl;
			std::cout << "- List all accounts" << std::endl;
			std::cout << "- List customer account" << std::endl;
			std::cout << "- List log" << std::endl;

			char* listCommand = new char[MAX_COMMAND];
			std::cin.getline(listCommand, MAX_COMMAND);

			if (strcmp(listCommand, "List all customers") == 0)
			{
				ourBank.listCustomers();
			}
			else if (strcmp(listCommand, "List all accounts") == 0)
			{
				ourBank.listAccounts();
			}
			else if (strcmp(listCommand, "List customer account") == 0)
			{
				std::cout << "Wanted id: ";
				size_t id;
				std::cin >> id;
				ClearSyncIgnore();//!

				ourBank.listCustomerAccount(id);
			}
			else if (strcmp(listCommand, "List log") == 0)
			{
				ourBank.listLog();
			}
			else
			{
				std::cout << "No such option. Try again!" << std::endl;
			}

			delete[] listCommand;
		}
		else if (strcmp(command, "Action") == 0)
		{
			std::cout << "Your action: Withdraw from account OR Deposit to account OR Transfer" << std::endl;

			char* actionCommand = new char[MAX_COMMAND];
			std::cin.getline(actionCommand, MAX_COMMAND);

			if (strcmp(actionCommand, "Withdraw from account") == 0)
			{
				std::cout << "How much money do you want to withdraw: ";
				double money;
				std::cin >> money;

				std::cout << "From witch account: ";//searching by id
				size_t id;
				std::cin >> id;
				ClearSyncIgnore();//!

				ourBank.withdrawMoney(id, money);
			}
			else if (strcmp(actionCommand, "Deposit to account") == 0)
			{
				std::cout << "How much money do you want to deposit: ";
				double money;
				std::cin >> money;

				std::cout << "From which account: ";//searching by id
				size_t id;
				std::cin >> id;
				ClearSyncIgnore();//!

				ourBank.depositMoney(id, money);
			}
			else if (strcmp(actionCommand, "Transfer") == 0)
			{
				std::cout << "How much money do you want to transfer: ";
				double money;
				std::cin >> money;

				std::cout << "From which accout: ";//searching by id
				size_t firstID;
				std::cin >> firstID;

				std::cout << "To which account: ";//searching by id
				size_t secondID;
				std::cin >> secondID;
				ClearSyncIgnore();//!

				char* firstIBAN = new char[MAX_COMMAND];
				strcpy(firstIBAN, ourBank.getAccountIBAN(firstID));

				char* secondIBAN = new char[MAX_COMMAND];
				strcpy(secondIBAN, ourBank.getAccountIBAN(secondID));

				ourBank.transfer(money, firstIBAN, secondIBAN);

				delete[] firstIBAN;
				delete[] secondIBAN;
			}
			else
			{
				std::cout << "No such option. Try again!" << std::endl;
			}
		}
		else if (strcmp(command, "Display info for the bank") == 0)
		{
			ourBank.display();
		}
		else if (strcmp(command, "Quit") == 0)
		{
			delete[] command;
			std::cout << "Have a nice day! Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "There isn't such choice. Try again!" << std::endl;
		}

		ourBank.exportLog();

		delete[] command;
		std::cout << std::endl;
	}

	delete[] bankName;
	delete[] bankAddress;
}