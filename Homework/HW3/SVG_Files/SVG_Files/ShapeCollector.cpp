#include "ShapeCollector.h"

void ClearSyncIgnore()
{
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
}

void ShapeCollector::print(size_t index) const
{
	if (list[index]->getType() == RECTANGLE)
	{
		Rectangle* temp = (Rectangle*)list[index];
		std::cout << "Figure: Rectangle" << std::endl;
		std::cout << "X= " << temp->getPoint(NULL).getX() << std::endl;
		std::cout<<"Y= "<< temp->getPoint(NULL).getY() << std::endl;
		std::cout << "Width= " << temp->getWidth() << std::endl;
		std::cout << "Height= " << temp->getHeight() << std::endl;
		std::cout << "Fill: " << temp->getColor() << std::endl;
	}
	else if (list[index]->getType() == CIRCLE)
	{
		Circle* temp = (Circle*)list[index];
		std::cout << "Figure: Circle" << std::endl;
		std::cout << "CX= " << temp->getPoint(NULL).getX() << std::endl;
		std::cout << "CY= " << temp->getPoint(NULL).getY() << std::endl;
		std::cout << "R= " << temp->getR() << std::endl;
		std::cout << "Fill: " << temp->getColor() << std::endl;
	}
	else if (list[index]->getType() == LINE)
	{
		std::cout << "Figure: Line" << std::endl;
		std::cout << "X1= " << list[index]->getPoint(NULL).getX() << std::endl;
		std::cout << "Y1= " << list[index]->getPoint(NULL).getY() << std::endl;
		std::cout << "X2= " << list[index]->getPoint(ONE).getX() << std::endl;
		std::cout << "Y2= " << list[index]->getPoint(ONE).getY() << std::endl;
		std::cout << "Fill: " << list[index]->getColor() << std::endl;	
	}
}

void ShapeCollector::copy(const ShapeCollector& other)
{
	size_t size = other.list.getSize();
	for (int i = 0; i < size; i++)
	{
		list[i] = other.list[i]->clone();
	}
}

void ShapeCollector::free()
{
	for (int i = 0; i < list.getSize(); i++)
		delete[] list[i];

	list.clear();
}

ShapeCollector::ShapeCollector(Vector<Shape*> list)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		this->list[i] = list[i]->clone();
	}
}

ShapeCollector::ShapeCollector(const ShapeCollector& other)
{
	copy(other);
}

ShapeCollector& ShapeCollector::operator=(const ShapeCollector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

ShapeCollector::~ShapeCollector()
{
	free();
}

void ShapeCollector::print() const
{
	for (int i = 0; i < list.getSize(); i++)
	{
		print(i);
	}
}

void ShapeCollector::createRectangle(char* color, double x, double y, double width, double height)
{
	Shape* temp = new Rectangle(color, x, y, width, height);
	list.pushBack(temp);
}

void ShapeCollector::createCircle(char* color, double r, double x, double y)
{
	Shape* temp = new Circle(color, r, x, y);
	list.pushBack(temp);
}

void ShapeCollector::createLine(char* color, double x1, double y1, double x2, double y2)
{
	Shape* temp = new Line(color, x1, y1, x2, y2);
	list.pushBack(temp);
}

void ShapeCollector::erase(size_t index)
{
	if (index > list.getSize())
		std::cout << "There isn't a figure with such index. Try again!";
	else
	{
		list.popAt(index);
	}
}

void ShapeCollector::translateAllFigures(double vertical, double horizontal)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		if (list[i]->getType() == CIRCLE)
		{
			list[i]->getPoint(NULL).translatePoint(vertical, horizontal);
		}
		else if (list[i]->getType() == RECTANGLE)
		{
			list[i]->getPoint(NULL).translatePoint(vertical, horizontal);
			list[i]->getPoint(ONE).translatePoint(vertical, horizontal);
			list[i]->getPoint(TWO).translatePoint(vertical, horizontal);
			list[i]->getPoint(THREE).translatePoint(vertical, horizontal);
			
		}
		else if (list[i]->getType() == LINE)
		{
			list[i]->getPoint(NULL).translatePoint(vertical, horizontal);
			list[i]->getPoint(ONE).translatePoint(vertical, horizontal);
		}
	}
}

bool ShapeCollector::translateFigure(size_t index, double vertical, double horizontal)
{
	if (index >= list.getSize())
		throw "No such figure!";

	if (list[index]->getType() == CIRCLE)
	{
		list[index]->getPoint(NULL).translatePoint(vertical, horizontal);
	}
	else if (list[index]->getType() == RECTANGLE)
	{
		list[index]->getPoint(NULL).translatePoint(vertical, horizontal);
		list[index]->getPoint(ONE).translatePoint(vertical, horizontal);
		list[index]->getPoint(TWO).translatePoint(vertical, horizontal);
		list[index]->getPoint(THREE).translatePoint(vertical, horizontal);

	}
	else if (list[index]->getType() == LINE)
	{
		list[index]->getPoint(NULL).translatePoint(vertical, horizontal);
		list[index]->getPoint(ONE).translatePoint(vertical, horizontal);
	}
}

void ShapeCollector::withinRectangle(double x, double y, double width, double height) const
{
	Rectangle* check = new Rectangle(nullptr, x, y, width, height);

	for (int i = 0; i < list.getSize(); i++)
	{
		if (list[i]->getType() == CIRCLE)
		{
			Circle* temp = (Circle*)list[i];
			Point center = list[i]->getPoint(NULL);
			
			if (check->isPointIn(center.getX(), center.getX()) &&
				check->isPointIn(center.getX(), center.getY() - temp->getR()) &&
				check->isPointIn(center.getX() + temp->getR(), center.getY()) &&
				check->isPointIn(center.getX() - temp->getR(), center.getY()))
			{
				print(i);
			}
		}
		else if (list[i]->getType() == RECTANGLE)
		{
			Point null = list[i]->getPoint(NULL);
			Point one = list[i]->getPoint(ONE);
			Point two = list[i]->getPoint(TWO);
			Point three = list[i]->getPoint(THREE);
			if (check->isPointIn(null.getX(), null.getY()) &&
				check->isPointIn(one.getX(), one.getY()) &&
				check->isPointIn(two.getX(), two.getY()) &&
				check->isPointIn(three.getX(), three.getY()))
			{
				print(i);
			}
		}
		else if (list[i]->getType() == LINE)
		{
			Point null = list[i]->getPoint(NULL);
			Point one = list[i]->getPoint(ONE);

			if (check->isPointIn(null.getX(), null.getY()) &&
				check->isPointIn(one.getX(), one.getY()))
			{
				std::cout << "Figure: " << list[i]->getType() << std::endl;

				Point newPoint(one.getX(), null.getY());
				double dist1 = newPoint.getDist(null);
				double dist2 = newPoint.getDist(one);
				double length = sqrt(dist1 * dist1 + dist2 * dist2);

				std::cout << "Length: " << length << std::endl;
			}
		}
	}
}

void ShapeCollector::withinCircle(double r, double cx, double cy) const
{
	Circle* check = new Circle(nullptr, r, cx, cy);

	for (int i = 0; i < list.getSize(); i++)
	{
		if (list[i]->getType() == CIRCLE)
		{
			Circle* temp = (Circle*)list[i];
			Point center = list[i]->getPoint(NULL);

			if (check->isPointIn(center.getX(), center.getX()) &&
				check->isPointIn(center.getX(), center.getY() - temp->getR()) &&
				check->isPointIn(center.getX() + temp->getR(), center.getY()) &&
				check->isPointIn(center.getX() - temp->getR(), center.getY()))
			{
				print(i);
			}
		}
		else if (list[i]->getType() == RECTANGLE)
		{
			Point null = list[i]->getPoint(NULL);
			Point one = list[i]->getPoint(ONE);
			Point two = list[i]->getPoint(TWO);
			Point three = list[i]->getPoint(THREE);
			if (check->isPointIn(null.getX(), null.getY()) &&
				check->isPointIn(one.getX(), one.getY()) &&
				check->isPointIn(two.getX(), two.getY()) &&
				check->isPointIn(three.getX(), three.getY()))
			{
				print(i);
			}
		}
		else if (list[i]->getType() == LINE)
		{
			Point null = list[i]->getPoint(NULL);
			Point one = list[i]->getPoint(ONE);

			if (check->isPointIn(null.getX(), null.getY()) &&
				check->isPointIn(one.getX(), one.getY()))
			{
				std::cout << "Figure: " << list[i]->getType() << std::endl;

				Point newPoint(one.getX(), null.getY());
				double dist1 = newPoint.getDist(null);
				double dist2 = newPoint.getDist(one);
				double length = sqrt(dist1 * dist1 + dist2 * dist2);

				std::cout << "Length: " << length << std::endl;
			}
		}
			
	}
}

void ShapeCollector::pointIn(double x, double y)
{
	for (int i = 0; i < list.getSize(); i++)
	{
		if (list[i]->isPointIn(x, y))
		{
			if (list[i]->getType() == RECTANGLE || list[i]->getType() == CIRCLE)
			{
				print(i);
			}
			else
			{
				Point null = list[i]->getPoint(NULL);
				Point one = list[i]->getPoint(ONE);

				std::cout << "Figure: " << list[i]->getType() << std::endl;

				Point newPoint(one.getX(), null.getY());
				double dist1 = newPoint.getDist(null);
				double dist2 = newPoint.getDist(one);
				double length = sqrt(dist1 * dist1 + dist2 * dist2);

				std::cout << "Length: " << length << std::endl;
			}
		}
	}
}

void ShapeCollector::areas() const
{
	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << i + 1 << ". " << list[i]->getArea() << std::endl;
	}
}

void ShapeCollector::pers() const
{
	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << i + 1 << ". " << list[i]->getPer() << std::endl;
	}
}

void ShapeCollector::save() const
{
	std::fstream file("figures.svg", std::ios::out);

	if (!file.is_open())
	{
		throw "An error occurred!";
	}

	file << "<svg>" << std::endl;

	for (int i = 0; i < list.getSize(); i++)
	{
		if (list[i]->getType() == RECTANGLE)
		{
			Rectangle* temp = (Rectangle*)list[i];
			file << "<rect ";
			file << "x=\"" << temp->getPoint(NULL).getX()<<"\" ";
			file << "y=\"" << temp->getPoint(NULL).getY()<<"\" ";
			file << "width=\"" << temp->getWidth() << "\" ";
			file << "length=\"" << temp->getHeight() << "\" ";
			file << "fill=\"" << temp->getColor() << "\" />" << std::endl;
		}
		else if (list[i]->getType() == CIRCLE)
		{
			Circle* temp = (Circle*)list[i];
			file << "<circle ";
			file << "cx=\"" << temp->getPoint(NULL).getX() << "\" ";
			file << "cy=\"" << temp->getPoint(NULL).getY() << "\" ";
			file << "r=\"" << temp->getR() << "\" ";
			file << "fill=\"" << temp->getColor() << "\" />" << std::endl;
		}
		else if (list[i]->getType() == LINE)
		{
			Line* temp = (Line*)list[i];
			file << "<line ";
			file << "x1=\"" << temp->getPoint(NULL).getX() << "\" ";
			file << "y1=\"" << temp->getPoint(NULL).getY() << "\" ";
			file << "x2=\"" << temp->getPoint(ONE).getX() << "\" ";
			file << "y2=\"" << temp->getPoint(ONE).getY() << "\" ";
			file << "fill=\"" << temp->getColor() << "\" />" << std::endl;
		}
	}

	file << "</svg>";

	file.close();

	std::cout << "File successfully saved!" << std::endl;
}
