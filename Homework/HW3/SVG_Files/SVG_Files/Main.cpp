#include "ShapeCollector.h";
#include "FillShapeCollector.h";

const char working[] = "Working";

void Menu()
{
	std::cout << "1.Print" << std::endl;
	std::cout << "2.Create" << std::endl;
	std::cout << "3.Erase" << std::endl;
	std::cout << "4.Translate" << std::endl;
	std::cout << "5.Within" << std::endl;
	std::cout << "6.PointIn" << std::endl;
	std::cout << "7.Areas" << std::endl;
	std::cout << "8.Pers" << std::endl;
	std::cout << "9.Save" << std::endl;
	std::cout << "10.Quit" << std::endl << std::endl;
}

int main()
{
	ShapeCollector collect;
	Fill(collect);

	Menu();

	while (true)
	{
		std::cout << "Your choice: ";
		char* command = new char[MAX_COMMAND];
		std::cin.getline(command, MAX_COMMAND);

		if (strcmp(command, "Print") == 0)
		{
			collect.print();
		}
		else if (strcmp(command,"Create") == 0)
		{
			std::cout << "What figure do you want to create: " << std::endl;
			std::cout << "Rectangle OR Circle OR Line" << std::endl;
			char* figure = new char[MAX_COMMAND];
			std::cin.getline(figure, MAX_COMMAND);

			if (strcmp(figure, "Circle") == 0)
			{
				std::cout << "X= ";
				double cx;
				std::cin >> cx;

				std::cout << "Y= ";
				double cy;
				std::cin >> cy;

				std::cout << "R= ";
				double r;
				std::cin >> r;
				ClearSyncIgnore();

				std::cout << "Color: ";
				char* color = new char[MAX_COMMAND];
				std::cin.getline(color, MAX_COMMAND);

				collect.createCircle(color, r, cx, cy);

				delete[] color;
			}
			else if (strcmp(figure, "Rectangle") == 0)
			{
				std::cout << "X= ";
				double x;
				std::cin >> x;
				
				std::cout << "Y= ";
				double y;
				std::cin >> y;

				std::cout << "Width: ";
				double width;
				std::cin >> width;

				std::cout << "Height: ";
				double height;
				std::cin >> height;
				ClearSyncIgnore();

				std::cout << "Color: ";
				char* color = new char[MAX_COMMAND];
				std::cin.getline(color, MAX_COMMAND);

				collect.createRectangle(color, x, y, width, height);

				delete[] color;
			}
			else if (strcmp(figure, "Line") == 0)
			{
				std::cout << "X1= ";
				double x1;
				std::cin >> x1;

				std::cout << "Y1= ";
				double y1;
				std::cin >> y1;

				std::cout << "X2= ";
				double x2;
				std::cin >> x2;

				std::cout << "Y2= ";
				double y2;
				std::cin >> y2;
				ClearSyncIgnore();

				std::cout << "Color: ";
				char* color = new char[MAX_COMMAND];
				std::cin.getline(color, MAX_COMMAND);

				collect.createLine(color, x1, y1, x2, y2);

				delete[] color;
			}
			else
			{
				std::cout << "You can't create such figure. Try again!" << std::endl;
			}

			delete[] figure;
		}
		else if (strcmp(command,"Erase") == 0)
		{
			std::cout << "Which figure do you want to erase: ";//expects index
			size_t index;
			std::cin >> index;
			ClearSyncIgnore();

			collect.erase(index-1);
		}
		else if (strcmp(command,"Translate") == 0)
		{
			std::cout << "Which figure do you want to translate: ";//answers: all figures OR particular figure
			char* figure = new char[MAX_COMMAND];
			std::cin.getline(figure, MAX_COMMAND);

			std::cout << "Vertical: ";
			double vertical;
			std::cin >> vertical;

			std::cout << "Horizontal: ";
			double horizontal;
			std::cin >> horizontal;
			ClearSyncIgnore();

			if (strcmp(figure, "All figures") == 0)
			{
				collect.translateAllFigures(vertical, horizontal);
			}
			else 
			{
				size_t index = figure[NULL] - PARSE;
				collect.translateFigure(index-1, vertical, horizontal);
			}

			delete[] figure;
		}
		else if (strcmp(command,"Within") == 0)
		{
			std::cout << "Where are we searching figures:" << std::endl;
			std::cout << "In Rectangle OR Circle" << std::endl;
			char* region = new char[MAX_COMMAND];
			std::cin.getline(region, MAX_COMMAND);

			if (strcmp(region, "Circle") == 0)
			{
				std::cout << "X= ";
				double cx;
				std::cin >> cx;

				std::cout << "Y= ";
				double cy;
				std::cin >> cy;

				std::cout << "R= ";
				double r;
				std::cin >> r;
				ClearSyncIgnore();

				collect.withinCircle(r, cx, cy);
			}
			else if (strcmp(region, "Rectangle") == 0)
			{
				std::cout << "X= ";
				double x;
				std::cin >> x;

				std::cout << "Y= ";
				double y;
				std::cin >> y;

				std::cout << "Width: ";
				double width;
				std::cin >> width;

				std::cout << "Height: ";
				double height;
				std::cin >> height;
				ClearSyncIgnore();

				collect.withinRectangle(x, y, width, height);
			}
		}
		else if (strcmp(command, "PointIn") == 0)
		{
			std::cout << "X= ";
			double x;
			std::cin >> x;

			std::cout << "Y= ";
			double y;
			std::cin >> y;
			ClearSyncIgnore();

			collect.pointIn(x, y);
		}
		else if (strcmp(command, "Areas") == 0)
		{
			collect.areas();
		}
		else if (strcmp(command, "Pers") == 0)
		{
			collect.pers();	
		}
		else if (strcmp(command, "Save") == 0)
		{
			collect.save();
		}
		else if (strcmp(command, "Quit") == 0)
		{
			std::cout << "Have a nice day! Goodbye!" << std::endl;
			delete[] command;
			break;
		}
		else
		{
			std::cout << "There isn't such choice. Try again!" << std::endl;
		}

		delete[] command;
	}

}