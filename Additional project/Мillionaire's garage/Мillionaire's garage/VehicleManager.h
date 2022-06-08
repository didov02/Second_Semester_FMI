#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Vector.hpp"

const int BIG_NUMBER = 1000000;

class VehicleManager
{
private:
	Vector<Vehicle*> list;
public:
	VehicleManager();
	VehicleManager(Vector<Vehicle*>);
	VehicleManager(const VehicleManager&);
	VehicleManager& operator=(const VehicleManager&);

	void print() const;
	void createCar(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, MyString color, size_t doorsCount,
		MyString brand, MyString model, MyString fuelType);
	void createTruck(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, MyString color, size_t doorsCount,
		MyString brand, size_t capacity);
	void createMotorcycle(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, MyString color, size_t doorsCount,
		MyString brand, MyString model, MyString frameType);
	void sellVehicle(size_t);
	void showNewestVehicle() const;
	void showOldestVehicle() const;
	void showFastestVehicle() const;
	void printCount() const;
	void save() const;

private:
	void copy(const VehicleManager&);
	void free();
};

