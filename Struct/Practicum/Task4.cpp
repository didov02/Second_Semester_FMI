//Създайте функция, която приема група и минимален успех за стипендия и извежда
//сортирани всички студенти, които ще получават стипендия идния семестър.

#include <iostream>

using namespace std;

const int MAX_STUDENTS = 3;

enum Year
{
	first,
	second,
	third,
	fourth
};

struct Student
{
	int facultyNumber;
	Year year;
	double grade;
};

struct CreateGroup
{
	Student students[MAX_STUDENTS];
};

CreateGroup newGroup()
{
	CreateGroup group;
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		cin >> group.students[i].facultyNumber;

		int year;
		cin >> year;
		switch (year)
		{
		case 1: 
			group.students[i].year = first;
			break;
		case 2:
			group.students[i].year = second;
			break;
		case 3:
			group.students[i].year = third;
			break;
		case 4:
			group.students[i].year = fourth;
			break;
		}

		cin >> group.students[i].grade;
	}

	return group;
}

void PrintStudent(Student student)
{
	cout << "Faculty Number: " << student.facultyNumber << endl;

	switch (student.year)
	{
	case first:
		cout << "Year: First" << endl;
		break;
	case second:
		cout << "Year: Second" << endl;
		break;
	case third:
		cout << "Year: Third" << endl;
		break;
	case fourth:
		cout << "Year: Fourth" << endl;
		break;
	}

	cout << "Overall Grade: " << student.grade << endl;
	cout << endl;
}

void Sort(const CreateGroup& group,double lowMark)
{
	double savedMarks[MAX_STUDENTS];
	int counter = 0;

	while (counter < MAX_STUDENTS-1)
	{
		double bestMark = 0;
		
		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			double currentMark = group.students[i].grade;

			if (bestMark < currentMark)
			{
				bool isThisStudentAdded = false;

				if (counter != 0)
				{
					for (int i = 0; i < counter; i++)
					{
						if (savedMarks[i] == currentMark)
						{
							isThisStudentAdded = true;
							break;
						}
					}

				}
				
				if (!isThisStudentAdded)
				{
					bestMark = currentMark;
				}
			}		
		}


		for (int i = 0; i < MAX_STUDENTS; i++)
		{
			if (group.students[i].grade == bestMark && bestMark>=lowMark)
			{
				PrintStudent(group.students[i]);

				savedMarks[counter] = bestMark;
				counter++;
				break;
			}
		}

	}

}

int main()
{
	CreateGroup group = newGroup();
	cout << endl;
	Sort(group, 4.50);

	return 0;
}
