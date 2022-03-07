//От стандартния вход се прочитат три числа. Запишете във файл "result.txt"сумата и произведението им.
//Направете функция, която извежда на стандартния изход разликата на сумата и произведението, прочетени от файла "result.txt".
//Коректността на данните във файла, който четете, е гарантирана.

#include <iostream>
#include <fstream>


using namespace std;

const int MAX_PAIRS = 25;

void GetInFile(int x, int y, int z)
{
	ofstream out;
	out.open("results.txt");

	if (out.is_open())
	{
		out << x + y + z;
		out << " ";
		out << x * y * z;
	}
	else
	{
		cout << "Error!" << endl;
	}

	out.close();
}

void GetOutOfFile()
{
	int sum;
	int multy;

	ifstream in;
	in.open("results.txt");
	
	in >> sum >> multy;

	cout << sum - multy << endl;

	in.close();
}

int main()
{
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	GetInFile(a, b, c);
	GetOutOfFile();

	return 0;

}
