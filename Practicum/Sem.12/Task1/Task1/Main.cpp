#include "Circle.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "ShapeCollector.h"

const int MAX_SYMBOLS = 20;

void listCommands()
{
	std::cout << "1.Add Figure" << std::endl;
	std::cout << "2.Display Info" << std::endl;
	std::cout << "3.Display Areas" << std::endl;
	std::cout << "4.Quit" << std::endl << std::endl;
}

int main()
{
	ShapeCollector collector;

	listCommands();

	bool quit = false;

	while (!quit)
	{
		std::cout << "Action: ";
		size_t command;
		std::cin >> command;

		if (command == 1)
		{
			std::cout << "What figure do you want to add: Circle, Rectanle, Rhombus or Triangle" << std::endl;

			size_t figure;
			std::cin >> figure;

			if (figure == 1)//Circle
			{
				Point point;

				std::cout << "Point's x value: ";
				std::cin >> point.x;

				std::cout << "Point's y value: ";
				std::cin >> point.y;

				std::cin.ignore();

				std::cout << "What color do you want: ";
				char* color = new char[MAX_SYMBOLS];
				std::cin.getline(color, MAX_SYMBOLS);

				std::cout << "Circle's diameter: ";
				double d;
				std::cin >> d;

				std::cin.ignore();

				Circle temp(point, color, d);

				collector.addItem(temp);

				delete[] color;

			}
			else if (figure == 2)//Rectangle
			{
				Point point;

				std::cout << "Point's x value: ";
				std::cin >> point.x;

				std::cout << "Point's y value: ";
				std::cin >> point.y;

				std::cin.ignore();

				std::cout << "What color do you want: ";
				char* color = new char[MAX_SYMBOLS];
				std::cin.getline(color, MAX_SYMBOLS);

				std::cout << "Side a: ";
				double a;
				std::cin >> a;

				std::cout << "Side b: ";
				double b;
				std::cin >> b;

				std::cin.ignore();

				Rectangle temp(point, color, a, b);

				collector.addItem(temp);

				delete[] color;
			}
			else if (figure == 3)//Rhombus
			{
				Point point;

				std::cout << "Point's x value: ";
				std::cin >> point.x;

				std::cout << "Point's y value: ";
				std::cin >> point.y;

				std::cin.ignore();

				std::cout << "What color do you want: ";
				char* color = new char[MAX_SYMBOLS];
				std::cin.getline(color, MAX_SYMBOLS);

				std::cout << "Side: ";
				double side;
				std::cin >> side;

				std::cout << "Degrees in sin: ";
				double degreesInSin;
				std::cin >> degreesInSin;

				std::cin.ignore();

				Rhombus temp(point, color, side, degreesInSin);

				collector.addItem(temp);

				delete[] color;
			}
			else if (figure == 4)//Triangle
			{
				Point point;

				std::cout << "Point's x value: ";
				std::cin >> point.x;

				std::cout << "Point's y value: ";
				std::cin >> point.y;

				std::cin.ignore();

				std::cout << "What color do you want: ";
				char* color = new char[MAX_SYMBOLS];
				std::cin.getline(color, MAX_SYMBOLS);

				std::cout << "Side a: ";
				double a;
				std::cin >> a;

				std::cout << "Side b: ";
				double b;
				std::cin >> b;

				std::cout << "Side c: ";
				double c;
				std::cin >> c;

				std::cout << "Degrees in sin: ";
				double degreesInSin;
				std::cin >> degreesInSin;

				std::cin.ignore();

				Triangle temp(point, color, a, b, c, degreesInSin);

				collector.addItem(temp);

				delete[] color;
			}
			else
			{
				std::cout << "There isn't such figure!" << std::endl;
			}
		}
		else if (command == 2)
		{
			collector.displayInfo();
		}
		else if (command == 3)
		{
			collector.displayAreas();
		}
		else if (command == 4)
		{
			quit = true;
			std::cout << "Bye bye!" << std::endl;
		}
		else
		{
			std::cout << "Such command is not available. Try again!" << std::endl;
		}
	}


	return 0;
}