#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
private:
	double overdraft;
public:
	PrivilegeAccount();
	PrivilegeAccount(char*, char*, char*, size_t, double, double);
	PrivilegeAccount(const PrivilegeAccount&);

	bool withdraw(size_t) override;
	void display() const override;

	Account* clone() const override;
};

