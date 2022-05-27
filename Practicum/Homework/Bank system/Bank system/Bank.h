#pragma once
#include <iostream>
#include <fstream>
#include "Customer.h"
#include "Account.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include "Vector.hpp"
#include <cstring>

#pragma warning (disable : 4996)

const int MAX_COMMAND = 100;

void ClearSyncIgnore();

class Bank
{
private:
	char* name;
	char* address;
	Vector<Customer> customers;
	Vector<Account*> accounts;
	Vector<char*> log;
public:
	Bank();
	Bank(char*, char*, Vector<Customer>, Vector<Account*>, Vector<char*>);
	Bank(const Bank&);
	Bank& operator=(const Bank&);
	~Bank();

	void addCustomer(size_t, char*, char*);
	void deleteCustomer(size_t);
	void addAccount(char*, char*, char*, char*, size_t, double);
	void deleteAccount(size_t);
	void listCustomers() const;
	void listAccounts() const;
	void listCustomerAccount(size_t) const;
	void listLog() const;
	void exportLog() const;
	void transfer(double, char*, char*);
	void display() const;

	void withdrawMoney(size_t, size_t);
	void depositMoney(size_t, size_t);
	const char* getAccountIBAN(size_t);

	void setName(char*);
	void setAddress(char*);
private:
	void copy(const Bank&);
	void free();
};

