#include "ShapeCollector.h"

void ClearSyncIgnore()
{
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
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
		list[i]->print();
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
		list[i]->translate(vertical, horizontal);
	}
}

bool ShapeCollector::translateFigure(size_t index, double vertical, double horizontal)
{
	if (index >= list.getSize())
		throw "No such figure!";
	
	list[index]->translate(vertical, horizontal);
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
				list[i]->print();
			}
		}
		else if (list[i]->getType() == RECTANGLE)
		{
			if (check->isPointIn(list[i]->getPoint(NULL).getX(), list[i]->getPoint(NULL).getY()) &&
				check->isPointIn(list[i]->getPoint(ONE).getX(), list[i]->getPoint(ONE).getY()) &&
				check->isPointIn(list[i]->getPoint(TWO).getX(), list[i]->getPoint(TWO).getY()) &&
				check->isPointIn(list[i]->getPoint(THREE).getX(), list[i]->getPoint(THREE).getY()))
			{
				list[i]->print();
			}
		}
		else if (list[i]->getType() == LINE)
		{
			if (check->isPointIn(list[i]->getPoint(NULL).getX(), list[i]->getPoint(NULL).getY()) &&
				check->isPointIn(list[i]->getPoint(ONE).getX(), list[i]->getPoint(ONE).getY()))
			{
				std::cout << "Figure: Line"<< std::endl;

				Point newPoint(list[i]->getPoint(NULL).getX(), list[i]->getPoint(NULL).getY());
				double dist1 = newPoint.getDist(list[i]->getPoint(NULL));
				double dist2 = newPoint.getDist(list[i]->getPoint(ONE));
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

			double dist = sqrt((list[i]->getPoint(NULL).getX() - cx) * (list[i]->getPoint(NULL).getX() - cx) +
				(list[i]->getPoint(NULL).getY() - cy) * (list[i]->getPoint(NULL).getY() - cy));

			if (temp->getR()>=dist+r)
			{
				list[i]->print();
			}
		}
		else if (list[i]->getType() == RECTANGLE)
		{
			if (check->isPointIn(list[i]->getPoint(NULL).getX(), list[i]->getPoint(NULL).getY()) &&
				check->isPointIn(list[i]->getPoint(ONE).getX(), list[i]->getPoint(ONE).getY()) &&
				check->isPointIn(list[i]->getPoint(TWO).getX(), list[i]->getPoint(TWO).getY()) &&
				check->isPointIn(list[i]->getPoint(THREE).getX(), list[i]->getPoint(THREE).getY()))
			{
				list[i]->print();
			}
		}
		else if (list[i]->getType() == LINE)
		{
			if (check->isPointIn(list[i]->getPoint(NULL).getX(), list[i]->getPoint(NULL).getY()) &&
				check->isPointIn(list[i]->getPoint(ONE).getX(), list[i]->getPoint(ONE).getY()))
			{
				std::cout << "Figure: Line" << std::endl;

				Point newPoint(list[i]->getPoint(ONE).getX(), list[i]->getPoint(NULL).getY());
				double dist1 = newPoint.getDist(list[i]->getPoint(NULL));
				double dist2 = newPoint.getDist(list[i]->getPoint(ONE));
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
				list[i]->print();
			}
			else
			{
				std::cout << "Figure: Line" << std::endl;

				Point newPoint(list[i]->getPoint(ONE).getX(), list[i]->getPoint(NULL).getY());
				double dist1 = newPoint.getDist(list[i]->getPoint(NULL));
				double dist2 = newPoint.getDist(list[i]->getPoint(ONE));
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
