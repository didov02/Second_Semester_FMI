#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:
	double interestRate;
public:
	SavingsAccount();
	SavingsAccount(char*, char*, char*, size_t, double, double);
	SavingsAccount(const SavingsAccount&);

	bool withdraw(size_t) override;
	void display() const override;

	Account* clone() const override;
};

