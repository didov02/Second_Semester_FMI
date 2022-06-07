#include <iostream>

const int MAX_SIZE = 50;

void Menu()
{
	std::cout << "1. Buy" << std::endl;
	std::cout << "2. Sell" << std::endl;
	std::cout << "3. Show newest vehicle" << std::endl;
	std::cout << "4. Show oldest vehicle" << std::endl;
	std::cout << "5. Show fastest vehicle" << std::endl;
	std::cout << "6. Show all vehicles" << std::endl;
	std::cout << "7. Count of vehicles" << std::endl;
	std::cout << "8. Save garage" << std::endl;
	std::cout << "9. Quit" << std::endl << std::endl;
}

int main()
{
	Menu();

	while (true)
	{
		std::cout << "Your option: ";

		char* option = new char[MAX_SIZE];
		std::cin.getline(option, MAX_SIZE);

		if (strcmp(option, "Buy") == 0)
		{
			std::cout << "What vehicle do you want to buy: ";//your options: car,motorcycle,boat

			char* vehicle = new char[MAX_SIZE];
			std::cin.getline(vehicle, MAX_SIZE);

			if (strcmp(vehicle, "Car") == 0)
			{
				std::cout << "Car brand: ";
				char* brand = new char[MAX_SIZE];
				std::cin.getline(brand, MAX_SIZE);

				std::cout << "Model: ";
				char* model = new char[MAX_SIZE];
				std::cin.getline(model, MAX_SIZE);

				std::cout << "Fuel: ";
				char* fuelType = new char[MAX_SIZE];
				std::cin.getline(fuelType, MAX_SIZE);

				std::cout << "Color: ";
				char* color = new char[MAX_SIZE];
				std::cin.getline(color, MAX_SIZE);

				std::cout << "Max speed: ";
				size_t maxSpeed;
				std::cin >> maxSpeed;

				std::cout << "Created in: ";
				size_t year;
				std::cin >> year;

				//Action

				delete[] brand;
				delete[] model;
				delete[] fuelType;
				delete[] color;
			}
			else if (strcmp(vehicle, "Motorcycle") == 0)
			{
				std::cout << "Motorcycle brand: ";
				char* brand = new char[MAX_SIZE];
				std::cin.getline(brand, MAX_SIZE);

				std::cout << "Model: ";
				char* model = new char[MAX_SIZE];
				std::cin.getline(model, MAX_SIZE);

				std::cout << "Frame type: ";
				char* frame = new char[MAX_SIZE];
				std::cin.getline(frame, MAX_SIZE);

				std::cout << "Color: ";
				char* color = new char[MAX_SIZE];
				std::cin.getline(color, MAX_SIZE);

				std::cout << "Max speed: ";
				size_t maxSpeed;
				std::cin >> maxSpeed;

				std::cout << "Created in: ";
				size_t year;
				std::cin >> year;

				//Action

				delete[] brand;
				delete[] model;
				delete[] frame;
				delete[] color;
			}
			else if (strcmp(vehicle, "Boat") == 0)
			{
				std::cout << "Model: ";
				char* model = new char[MAX_SIZE];
				std::cin.getline(model, MAX_SIZE);

				std::cout << "At which port is it located: ";
				char* port = new char[MAX_SIZE];
				std::cin.getline(port, MAX_SIZE);

				std::cout << "Color: ";
				char* color = new char[MAX_SIZE];
				std::cin.getline(color, MAX_SIZE);

				std::cout << "Max speed: ";
				size_t maxSpeed;
				std::cin >> maxSpeed;

				std::cout << "Created in: ";
				size_t year;
				std::cin >> year;

				//Action

				delete[] model;
				delete[] port;
				delete[] color;
			}
			else
			{
				std::cout << "You can't buy such type of vehicle. Try again!" << std::endl;
			}

			delete[] vehicle;
		}
		else if (strcmp(option, "Sell") == 0)
		{
			std::cout << "Which vehicle do you want to sell: ";
			size_t index;
			std::cin >> index;

			//Action
		}
		else if (strcmp(option, "Show newest vehicle") == 0)
		{
			
		}
		else if (strcmp(option, "Show oldest vehicle") == 0)
		{

		}
		else if (strcmp(option, "Show fastest vehicle") == 0)
		{

		}
		else if (strcmp(option, "Show all vehicles") == 0)
		{

		}
		else if (strcmp(option, "Count of vehicles") == 0)
		{

		}
		else if (strcmp(option, "Save garage") == 0)
		{

		}
		else if (strcmp(option, "Quit") == 0)
		{
			std::cout << "Have a nice day! Goodbye!" << std::endl;
			delete[] option;
			break;
		}

		delete[] option;
	}
}