#include "FillShapeCollector.h"

void GetText(int& index, char* buff, char*& fill)
{
	size_t size = 0;

	size_t buffSize = strlen(buff);
	for (int i = index; i < buffSize; i++)
	{
		if (buff[i] == SPACE)
		{
			index = i;
			break;
		}

		fill[size++] = buff[i];
	}
	fill[size] = '\0';
}

void GetColor(int& index, char* buff, char*& fill)
{
	size_t size = 0;

	size_t buffSize = strlen(buff);
	for (int i = index; i < buffSize; i++)
	{
		if (buff[i] == QUATATIONMARKS)
		{
			index = i;
			break;
		}

		fill[size++] = buff[i];
	}
	fill[size] = '\0';
}

double GetNum(int &index, char* buff)
{
	char* num = new char[MAX_COMMAND];
	size_t size = 0;

	size_t buffSize = strlen(buff);
	for (int i = index; i < buffSize ; i++)
	{
		if (buff[i] == QUATATIONMARKS)
		{
			index = i;
			break;
		}

		num[size++] = buff[i];
	}
	num[size] = '\0';

	double number = 0;

	for (int i = 0; i < size; i++)
	{
		number += num[i] - PARSE;
		for (int j = i + 1; j < size; j++)
		{
			number *= 10;
		}
	}

	delete[] num;
	return number;
}

void Fill(ShapeCollector& collect)
{
	std::ifstream file("figures.svg");

	if (!file.is_open())
	{
		throw "An error occurred!";
	} 

	char* buff = new char[BUFF_SIZE];
	size_t length = 0;
	while (!file.eof())
	{
		file.get(buff[length++]);
	}
	buff[--length] = '\0';

	size_t buffSize = strlen(buff);
	for (int i = 0; i < buffSize; i++)
	{
		if (buff[i] == '<' && buff[i+1] != 's')
		{
			i++;
			char* figure = new char[MAX_COMMAND];
			GetText(i, buff, figure);

			if (strcmp(figure, "rect") == 0)
			{
				i++;
				char* temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);

				int startIndex = 3;
				double x = GetNum(startIndex, temp);
				
				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				
				startIndex--;
				double y = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex = 7;
				double width = GetNum(startIndex, temp);

				i ++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex = 8;
				double height = GetNum(startIndex, temp);

				i ++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex = 6;
				char* color = new char[MAX_COMMAND];
				GetColor(startIndex, temp, color);

				collect.createRectangle(color, x, y, width, height);

				delete[] temp;
				delete[] color;
			}
			else if (strcmp(figure, "circle") == 0)
			{
				i++;
				char* temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);

				int startIndex = 4;
				double x = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);

				startIndex--;
				double y = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);

				startIndex = 3;
				double r = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex = 6;
				char* color = new char[MAX_COMMAND];
				GetColor(startIndex, temp, color);

				collect.createCircle(color, r, x, y);

				delete[] color;
				delete[] temp;
			}
			else if (strcmp(figure, "line") == 0)
			{
				i++;
				char* temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);

				int startIndex = 4;
				double x1 = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex--;
				double y1 = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex--;
				double x2 = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex--;
				double y2 = GetNum(startIndex, temp);

				i++;
				delete[] temp;
				temp = new char[MAX_COMMAND];
				GetText(i, buff, temp);
				startIndex = 6;
				char* color = new char[MAX_COMMAND];
				GetColor(startIndex, temp, color);

				collect.createLine(color, x1, y1, x2, y2);

				delete[] color;
				delete[] temp;
			}

			delete[] figure;
		}
	}

	delete[] buff;
	file.close();
}
