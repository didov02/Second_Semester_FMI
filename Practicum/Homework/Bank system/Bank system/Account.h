#pragma once
#include <iostream>
#include <ctime>
#include <cstring>

#pragma warning (disable : 4996)

class Account
{
protected:
	char* username;
	char* password;
	char* IBAN;
	size_t id;
	double amountOfMoney;
	time_t timeCreated;
public:
	Account();
	Account(char*, char*, char*, size_t, double);
	Account(const Account&);
	Account& operator=(const Account&);
	virtual ~Account();

	void setUsername(char*);
	void setPassword(char*);
	void setIBAN(char*);
	void setID(size_t);
	void setAmountOfMoney(double);
	void setTime();

	const char* getUsername() const;
	const char* getPassword() const;
	const char* getIBAN() const;
	size_t getID() const;
	time_t getTime() const;

	void deposit(size_t);
	virtual bool withdraw(size_t);
	virtual void display() const;
	double getBalance() const;

	virtual Account* clone() const = 0;
private:
	void copy(const Account&);
	void free();
};


