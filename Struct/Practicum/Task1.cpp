//Да се създаде структура която представя комплексно число.
//Създайте функция, която събира две комплексни числа.
//Създайте подходяща функция за извеждане принтиране на комплексни числа.

#include <iostream>

using namespace std;

struct ComplexNumber
{
	double normalPart, complexPart;
};

ComplexNumber Add(const ComplexNumber& firstNum, const ComplexNumber& secondNum)
{
	ComplexNumber together;
	together.normalPart = firstNum.normalPart + secondNum.normalPart;
	together.complexPart = firstNum.complexPart + secondNum.complexPart;

	return together;
}

void Print(const ComplexNumber& num)
{
	cout << "Normal Part: " << num.normalPart << endl;
	cout << "Complex Part: " << num.complexPart <<"*i"<< endl;
}

int main()
{
	ComplexNumber num1;
	cin >> num1.normalPart >> num1.complexPart;

	ComplexNumber num2;
	cin >> num2.normalPart >> num2.complexPart;

	ComplexNumber sum = Add(num1, num2);

	Print(sum);

	return 0;
}
