#include "OffersCollector.h"

const int MAX_SYMBOLS = 25;

void CommandList()
{
	std::cout << "1.Add offer" << std::endl;
	std::cout << "2.Show all offers" << std::endl;
	std::cout << "3.Does a company exist" << std::endl;
	std::cout << "4.Show all company which provide better payment" << std::endl;
	std::cout << "5.Quit" << std::endl;
}

int main()
{
	bool quit = false;

	OffersCollector list;

	while (!quit)
	{
		std::cout << "Your choice: ";
		size_t option;
		std::cin >> option;

		std::cin.ignore();

		if (option == 1)//Add offers
		{
			std::cout << "Company's name: ";
			char* name = new char[MAX_SYMBOLS];
			std::cin.getline(name, MAX_SYMBOLS);

			std::cout << "Programers' count: ";
			size_t programers;
			std::cin >> programers;

			std::cout << "Days off: ";
			size_t daysOff;
			std::cin >> daysOff;

			std::cout << "Payment: ";
			double payment;
			std::cin >> payment;

			std::cin.ignore();

			Offers offer(name, programers, daysOff, payment);

			list.addOffer(offer);

			delete[] name;
		}
		else if (option == 2)//Show all offers
		{
			list.showAllOffers();
		}
		else if (option == 3)//Does a company exist
		{
			std::cout << "Company's name: ";
			char* name = new char[MAX_SYMBOLS];
			std::cin.getline(name, MAX_SYMBOLS);

			list.firmExisting(name);

			delete[] name;
		}
		else if (option == 4)//Show all company which provide better payment
		{
			std::cout << "Minimum payment: ";
			size_t payment;
			std::cin >> payment;

			std::cin.ignore();

			list.printOffersWithGreaterPayment(payment);
		}
		else if (option == 5)//Quit
		{
			std::cout << "Have a nice day! Goodbye!" << std::endl;
			quit = true;
		}
	}
}