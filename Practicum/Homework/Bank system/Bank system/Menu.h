#pragma once
#include <iostream>

void Menu()
{
	std::cout << "1.Edit" << std::endl;
	std::cout << "	a.Customer" << std::endl;
	std::cout << "		i.Add new customer" << std::endl;
	std::cout << "		ii.Delete customer" << std::endl;
	std::cout << "	b.Account" << std::endl;
	std::cout << "		i.Add new account" << std::endl;
	std::cout << "		ii.Delete account" << std::endl;
	std::cout << "2. List" << std::endl;
	std::cout << "	a.List all customers" << std::endl;
	std::cout << "	b.List all accounts" << std::endl;
	std::cout << "	c.List customer account" << std::endl;
	std::cout << "	d.List log" << std::endl;
	std::cout << "3. Action" << std::endl;
	std::cout << "	a.Withdraw from account" << std::endl;
	std::cout << "	b.Deposit to account" << std::endl;
	std::cout << "	c.Transfer" << std::endl;
	std::cout << "4. Display info for the bank" << std::endl;
	std::cout << "5. Quit" << std::endl << std::endl;
}