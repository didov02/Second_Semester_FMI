//Въвежда се цяло число N и после N тригъгълника в равнината, 
//определени от 3 точки(6 координати).Отпечатайте тригълниците сортирани по лицата им.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
	int x, y;
};

struct Triangle
{
	Point A, B, C;
};

void ReadPoint(Point& A)
{
	cin >> A.x >> A.y;
}

double GetArea(Point A, Point B, Point C)
{
	double area = 0;

	double firstSide = sqrt(pow(abs(B.x - A.x),2) + pow(abs(B.y - A.y),2));//AB
	double secondSide = sqrt(pow(abs(C.x - A.x),2) + pow(abs(C.y - A.y),2));//AC
	double thirdSide = sqrt(pow(abs(C.x - B.x),2) + pow(abs(C.y - B.y),2));//BC

	double p = (firstSide + secondSide + thirdSide) / 2;

	area = sqrt(p * (p - firstSide) * (p - secondSide) * (p - thirdSide));

	return area;
}

void Swap(double &x, double &y)
{
	double temp = x;
	x = y;
	y = temp;
}

void SortTriangles(double* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;

	double* trianglesArea = new double[N];
	int counter = 0;

	for (int i = 0; i < N; i++)
	{
		Triangle tempTriangle;

		ReadPoint(tempTriangle.A);
		ReadPoint(tempTriangle.B);
		ReadPoint(tempTriangle.C);

		double area = GetArea(tempTriangle.A, tempTriangle.B, tempTriangle.C);

		trianglesArea[counter++] = area;
	}

	SortTriangles(trianglesArea, counter);

	for (int i = 0; i < counter; i++)
	{
		cout << setprecision(3) << trianglesArea[i] << endl;
	}

	delete[] trianglesArea;

	return 0;
}
