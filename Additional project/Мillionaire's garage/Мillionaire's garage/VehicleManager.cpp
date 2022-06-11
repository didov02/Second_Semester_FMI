#include "VehicleManager.h"

void VehicleManager::copy(const VehicleManager& other)
{
	size_t size = other.list.getSize();

	for (int i = 0; i < size; i++)
	{
		list[i] = other.list[i]->clone();
	}
}

void VehicleManager::free()
{
	size_t size = list.getSize();

	for (int i = 0; i < size; i++)
		delete[] list[i];

	list.clear();
}

VehicleManager::VehicleManager()
{
	
}

VehicleManager::VehicleManager(Vector<Vehicle*> other)
{
	this->list = other;
}

VehicleManager::VehicleManager(const VehicleManager& other)
{
	copy(other);
}

VehicleManager& VehicleManager::operator=(const VehicleManager& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

void VehicleManager::print() const
{
	size_t size = list.getSize();

	for (int i = 0; i < size; i++)
	{
		list[i]->display();
	}
}

void VehicleManager::createCar(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount,
	const MyString& brand, const MyString& model, const MyString& fuelType)
{
	list.pushBack(new Car(maxPassengers, maxSpeed, name, year, color, doorsCount, brand, model, fuelType));

	MyString newCar = "Car, ";
	newCar += name;
	newCar += " is added.\n";
	log.pushBack(newCar);
}

void VehicleManager::createTruck(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount,
	const MyString& brand, size_t capacity)
{
	list.pushBack(new Truck(maxPassengers, maxSpeed, name, year, color, doorsCount, brand, capacity));

	MyString newTruck = "Truck, ";
	newTruck += name;
	newTruck += " is added.\n";
	log.pushBack(newTruck);
}

void VehicleManager::createMotorcycle(int maxPassengers, int maxSpeed, const MyString& name, int year, const MyString& color, size_t doorsCount,
	const MyString& brand, const MyString& model, const MyString& frameType)
{
	list.pushBack(new Motorcycle(maxPassengers, maxSpeed, name, year, color, doorsCount,
		brand, model, frameType));

	MyString newMotorcycle = "Truck, ";
	newMotorcycle += name;
	newMotorcycle += " is added.\n";
	log.pushBack(newMotorcycle);
}

void VehicleManager::createPlane(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double wingspan, double maxAltitude, const MyString& color, const MyString& model, double maxStorage, double maxAirTime)
{
}

void VehicleManager::createPrivateJet(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double wingspan, double maxAltitude, const MyString& color, const MyString& model, bool hasDrinkBar, bool hasSleepingRoom)
{
}

void VehicleManager::createJacht(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double width, int crewSize, const MyString& color, const MyString& model, bool hasSwimmingPool, int roomCount)
{
}

void VehicleManager::createSail(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double width, int crewSize, const MyString& color, const MyString& model, bool hasEngine, int sailsCount)
{
}

void VehicleManager::sellVehicle(size_t index)
{
	if (index >= list.getSize())
		throw "Unavailable index!";

	list.popAt(index);

	log.pushBack(MyString("A vehicle was deleted.\n"));
}

void VehicleManager::showNewestVehicle() const
{
	size_t newestVehicleIndex = 0;
	int newestYear = 0;
	size_t size = list.getSize();

	for (int i = 0; i < size; i++)
	{
		if (list[i]->getYear() > newestYear)
		{
			newestYear = list[i]->getYear();
			newestVehicleIndex = i;
		}
	}

	list[newestVehicleIndex]->display();
}

void VehicleManager::showOldestVehicle() const
{
	size_t oldestVehicleIndex = 0;
	int oldestYear = BIG_NUMBER;
	size_t size = list.getSize();

	for (int i = 0; i < size; i++)
	{
		if (list[i]->getYear() < oldestYear)
		{
			oldestYear = list[i]->getYear();
			oldestVehicleIndex = i;
		}
	}

	list[oldestVehicleIndex]->display();
}

void VehicleManager::showFastestVehicle() const
{
	int maxSpeed = 0;
	size_t maxSpeedIndex;

	size_t size = list.getSize();

	for (int i = 0; i < size; i++)
	{
		if (list[i]->getMaxSpeed() > maxSpeed)
		{
			maxSpeed = list[i]->getYear();
			maxSpeedIndex = i;
		}
	}

	list[maxSpeedIndex]->display();
}

void VehicleManager::printCount() const
{
	std::cout << "Vehicles count: " << list.getSize() << std::endl;
}

void VehicleManager::save() const
{
	std::fstream file("actions.txt", std::ios::out);

	if (!file.is_open())
	{
		throw "Undefined behaviour!";
	}

	size_t logSize = log.getSize();

	for (int i = 0; i < logSize; i++)
	{
		file << log[i];
	}

	file.close();
}
