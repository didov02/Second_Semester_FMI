#include <iostream>
#include "MyString.h"

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
			std::cout << "What type of vehicle do you want to buy: ";//your options: ground, air, water

			MyString typeOfVehicle;
			std::cin >> typeOfVehicle;

			if (typeOfVehicle == "Ground")
			{
				std::cout << "What ground vehicle do you want to buy: ";//your options: car, motorcycle, truck

				MyString vehicle;
				std::cin >> vehicle;

				if (vehicle == "Car")
				{
					std::cout << "Car's name: ";
					MyString carsPersonalName;
					std::cin >> carsPersonalName;

					std::cout << "Brand: ";
					MyString brand;
					std::cin >> brand;

					std::cout << "Model: ";
					MyString model;
					std::cin >> model;

					std::cout << "Fuel: ";
					MyString fuel;
					std::cin >> fuel;

					std::cout << "Color: ";
					MyString color;
					std::cin >> fuel;

					std::cout << "Max speed: ";
					int maxSpeed;
					std::cin >> maxSpeed;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					std::cout << "Doors count: ";
					size_t doors;
					std::cin >> doors;

					std::cout << "Max passengers: ";
					int maxPassengers;
					std::cin >> maxPassengers;


					//Action
				}
				else if (vehicle == "Motorcycle")
				{
					std::cout << "Motorcycle's name: ";
					MyString motorcyclePersonalName;
					std::cin >> motorcyclePersonalName;

					std::cout << "Brand: ";
					MyString brand;
					std::cin >> brand;

					std::cout << "Model: ";
					MyString model;;
					std::cin >> model;

					std::cout << "Frame type: ";
					MyString frameType;
					std::cin >> frameType;

					std::cout << "Color: ";
					MyString color;
					std::cin >> color;

					std::cout << "Max speed: ";
					size_t maxSpeed;
					std::cin >> maxSpeed;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					//Action
				}
				else if (vehicle == "Truck")
				{
					std::cout << "Truck's name: ";
					MyString truckPersonalName;
					std::cin >> truckPersonalName;

					std::cout << "Brand: ";
					MyString brand;
					std::cin >> brand;

					std::cout << "Color: ";
					MyString color;
					std::cin >> color;

					std::cout << "Max speed: ";
					size_t maxSpeed;
					std::cin >> maxSpeed;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					std::cout << "Doors count: ";
					size_t doors;
					std::cin >> doors;

					//Action
				}
				else
				{
					std::cout << "You can't buy such type of vehicle. Try again!" << std::endl;
				}
			}
			else if (typeOfVehicle == "Air")
			{

			}
			else if (typeOfVehicle == "Water")
			{

			}
			else
			{

			}
			
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