#pragma once
#include "Account.h"

class NormalAccount : public Account
{
private:

public:
	NormalAccount();
	NormalAccount(char*, char*, char*, size_t, double);
	NormalAccount(const NormalAccount&);

	void display() const override;

	Account* clone() const override;
};

