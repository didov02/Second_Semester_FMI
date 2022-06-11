#include <iostream>
#include "MyString.h"
#include "VehicleManager.h"

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

	VehicleManager garage;

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

					garage.createCar(maxPassengers, maxSpeed, carsPersonalName, year, color, doors, brand, model, fuel);
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
					
					std::cout << "Max passengers: ";
					size_t maxPassengers;
					std::cin >> maxPassengers;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					//Action
					garage.createMotorcycle(maxPassengers, maxSpeed, motorcyclePersonalName, year, color, 0, brand, model, frameType);
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

					std::cout << "Capacity: ";
					size_t capacity;
					std::cin >> capacity;

					std::cout << "Max speed: ";
					size_t maxSpeed;
					std::cin >> maxSpeed;

					std::cout << "Max passengers: ";
					size_t maxPassengers;
					std::cin >> maxPassengers;

					std::cout << "Created in: ";
					size_t year;
					std::cin >> year;

					std::cout << "Doors count: ";
					size_t doors;
					std::cin >> doors;

					//Action
					garage.createTruck(maxPassengers, maxSpeed, truckPersonalName, year, color, doors, brand, capacity);
				}
				else
				{
					std::cout << "You can't buy such type of vehicle. Try again!" << std::endl;
				}
			}
			else if (typeOfVehicle == "Air")
			{
				std::cout << "What air vehicle do you want to buy: Plane, PrivateJet";
				MyString vehicle;
				std::cin >> vehicle;

				if (vehicle == "Plane")
				{
					/*int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double wingspan,
					double maxAltitude, const MyString& color, const MyString& model, double maxStorage, double maxAirTime*/

					std::cout << "Plane's name: ";
					MyString planeName;
					std::cin >> planeName;

					std::cout << "Plane's max passengers: ";
					int planePassengers;
					std::cin >> planePassengers;

					std::cout << "Plane's max speed: ";
					double planeSpeed;
					std::cin >> planeSpeed;

					std::cout << "Plane's wingspan: ";
					double planeWingspan;
					std::cin >> planeWingspan;

					std::cout << "Plane's max altitude: ";
					double planeAltitude;
					std::cin >> planeAltitude;

					std::cout << "Plane's year of creation: ";
					int planeYear;
					std::cin >> planeYear;

					std::cout << "Plane's color: ";
					MyString planeColor;
					std::cin >> planeColor;

					std::cout << "Plane's model: ";
					MyString planeModel;
					std::cin >> planeModel;

					std::cout << "Plane's max storage: ";
					double planeStorage;
					std::cin >> planeStorage;
					
					std::cout << "Plane's max air time: ";
					double planeAirtime;
					std::cin >> planeAirtime;
					
					garage.createPlane(planePassengers, planeSpeed, planeName, planeYear, planeWingspan, planeAltitude, planeColor, planeModel, planeStorage, planeAirtime);
				}
				else if (vehicle == "PrivateJet")
				{
					/*nt maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double wingspan,
					double maxAltitude, const MyString& color, const MyString& model
				, bool hasDrinkBar, bool hasSleepingRoom*/


					std::cout << "PrivateJet's name: ";
					MyString PrivateJetName;
					std::cin >> PrivateJetName;

					std::cout << "PrivateJet's max passengers: ";
					int PrivateJetPassengers;
					std::cin >> PrivateJetPassengers;

					std::cout << "Plane's max speed: ";
					double PrivateJetSpeed;
					std::cin >> PrivateJetSpeed;

					std::cout << "PrivateJet's wingspan: ";
					double PrivateJetWingspan;
					std::cin >> PrivateJetWingspan;

					std::cout << "Privatejet's max altitude: ";
					double PrivateJetAltitude;
					std::cin >> PrivateJetAltitude;

					std::cout << "Privatejet's year of creation: ";
					int PrivateJetYear;
					std::cin >> PrivateJetYear;

					std::cout << "Privatejet's color: ";
					MyString PrivateJetColor;
					std::cin >> PrivateJetColor;

					std::cout << "Privatejet's model: ";
					MyString PrivateJetModel;
					std::cin >> PrivateJetModel;

					std::cout << "Privatejet's drinkbar: ";
					bool hasDrinkBar;
					std::cin >> hasDrinkBar;

					std::cout << "Privatejet's sleeping room: ";
					double sleepingRoom;
					std::cin >> sleepingRoom;

					garage.createPrivateJet(PrivateJetPassengers, PrivateJetSpeed, PrivateJetName, PrivateJetYear, PrivateJetWingspan, PrivateJetAltitude, PrivateJetColor, PrivateJetModel, hasDrinkBar, sleepingRoom);
				}
				else
				{
					std::cout << "No such vehicle found here\n";
				}


			}
			else if (typeOfVehicle == "Water")
			{

				std::cout << "What water vehicle do you want to buy: Jacht, Sail";
				MyString vehicle;
				std::cin >> vehicle;

				if (vehicle == "Jacht")
				{
					/*int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double length, double width, int crewSize
					, const MyString& color, const MyString& model, bool hasSwimmingPool, int roomsCount*/

					std::cout << "Jacht's name: ";
					MyString jachtName;
					std::cin >> jachtName;

					std::cout << "Jacht's max passengers: ";
					int jachtPassengers;
					std::cin >> jachtPassengers;

					std::cout << "Jacht's max speed: ";
					int jachtSpeed;
					std::cin >> jachtSpeed;

					std::cout << "Jacht's year of creation: ";
					int jachtYear;
					std::cin >> jachtYear;

					std::cout << "Jacht's color: ";
					MyString jachtColor;
					std::cin >> jachtColor;

					std::cout << "Jacht's model: ";
					MyString jachtModel;
					std::cin >> jachtModel;

					std::cout << "Jacht's length: ";
					int jachtLength;
					std::cin >> jachtLength;

					std::cout << "Jacht's width: ";
					int jachtWidth;
					std::cin >> jachtWidth;

					std::cout << "Jacht's crew size: ";
					int jachtCrew;
					std::cin >> jachtCrew;

					std::cout << "Jacht's swimming pool?: ";
					bool jachtSwimmingPool;
					std::cin >> jachtSwimmingPool;

					std::cout << "Jacht's rooms count: ";
					int jachtRooms;
					std::cin >> jachtRooms;

					garage.createJacht(jachtPassengers, jachtSpeed, jachtName, jachtYear, jachtWidth, jachtLength, jachtCrew, jachtColor, jachtModel, jachtSwimmingPool, jachtRooms);

				}
				else if (vehicle == "Sail")
				{
					/*int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double length, double width, int crewSize
					, const MyString& color, const MyString& model, bool hasEngine, int sailsCount*/

					std::cout << "Sail's name: ";
					MyString sailName;
					std::cin >> sailName;

					std::cout << "Sail's max passengers: ";
					int sailPassengers;
					std::cin >> sailPassengers;

					std::cout << "Sail's max speed: ";
					int sailSpeed;
					std::cin >> sailSpeed;

					std::cout << "Sail's year of creation: ";
					int sailYear;
					std::cin >> sailYear;

					std::cout << "Sail's color: ";
					MyString sailColor;
					std::cin >> sailColor;

					std::cout << "Sail's model: ";
					MyString sailModel;
					std::cin >> sailModel;

					std::cout << "Sail's length: ";
					int sailLength;
					std::cin >> sailLength;

					std::cout << "Sail's width: ";
					int sailWidth;
					std::cin >> sailWidth;

					std::cout << "Sail's crew size: ";
					int sailCrew;
					std::cin >> sailCrew;

					std::cout << "Sail's has engine?: ";
					bool sailEngine;
					std::cin >> sailEngine;

					std::cout << "Sail's sail count: ";
					int sailsCount;
					std::cin >> sailsCount;

					garage.createJacht(sailPassengers, sailSpeed, sailName, sailYear, sailWidth, sailLength, sailCrew, sailColor, sailModel, sailEngine, sailsCount);

				}

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
			garage.sellVehicle(index);
		}
		else if (strcmp(option, "Show newest vehicle") == 0)
		{
			garage.showNewestVehicle();
		}
		else if (strcmp(option, "Show oldest vehicle") == 0)
		{
			garage.showOldestVehicle();
		}
		else if (strcmp(option, "Show fastest vehicle") == 0)
		{
			garage.showFastestVehicle();
		}	
		else if (strcmp(option, "Show all vehicles") == 0)
		{
			garage.print();
		}
		else if (strcmp(option, "Count of vehicles") == 0)
		{
			garage.printCount();
		}
		else if (strcmp(option, "Save garage") == 0)
		{
			garage.save();
		}
		else if (strcmp(option, "Quit") == 0)
		{
			std::cout << "Have a nice day! Goodbye!" << std::endl;
			//delete[] option;
			break;
		}

		delete[] option;
	}

	return 0;
}