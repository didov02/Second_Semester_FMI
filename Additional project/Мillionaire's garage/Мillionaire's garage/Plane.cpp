#include "Plane.h"

Plane::Plane(int maxPassengers, int maxSpeed, const MyString& name, VehicleType type, int year, double wingspan, double maxAltitude, const MyString& color, const MyString& model
    , double maxStorage, double maxAirTime) : AirVehicle(maxPassengers, maxSpeed, name, type, year, wingspan, maxAltitude, color, model)
{
    this->maxStorage = maxStorage;
    this->maxAirTime = maxAirTime;
}

Vehicle* Plane::clone() const
{
    return new Plane(*this);
}

AirType Plane::getType() const
{
    return t;
}

void Plane::display() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Wingspan: " << wingspan << std::endl;
    std::cout << "Max Altitude: " << maxAltitude << std::endl;
    std::cout << "Max Storage: " << maxStorage << std::endl;
    std::cout << "Max Airtime: " << maxAirTime << std::endl;
}

double Plane::getMaxStorage() const
{
    return maxStorage;
}

void Plane::setMaxStorate(double maxStorage)
{
    this->maxStorage = maxStorage;
}

double Plane::getMaxAirtime() const
{
    return maxAirTime;
}

void Plane::setMaxAirtime(double airTime)
{
    this->maxAirTime = airTime;
}
