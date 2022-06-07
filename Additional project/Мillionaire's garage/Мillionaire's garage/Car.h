#pragma once
#include "Garage.h"

class Car : public Garage
{
private:
	char* brand;
	char* model;
	char* fuelType;
public:
	Car();
	Car(char*, size_t, size_t, char*, char*, char*);
	Car(const Car&);
	Car& operator=(const Car&);
	~Car();

	Garage* clone() const override;
	Type getType() const override;

	void setBrand(char*);
	void setModel(char*);
	void setFuelType(char*);

	const char* getBrand() const;
	const char* getModel() const;
	const char* getFuelType() const;
private:
	void copy(const Car&);
	void free();
};

