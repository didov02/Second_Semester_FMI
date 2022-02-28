//Създайте структура описваща студент.Всеки студент се определя чрез :
//
//факултетен номер(петцифрени цели числа).
//курс(∀студент е в първи, втори, трети или четвърти курс).
//средна оценка за курса.
//
//Създайте подходящо параметризирана функция initStudent(...); която въвежда коректни данни за студент.
//Да се напише функция, която принтира студент.
//Може да използвате помощни функции.

#include <iostream>

using namespace std;

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

Student initStudent(int fn, Year currentYear, double currentGrade)
{
	Student currentStudent;
	currentStudent.facultyNumber = fn;
	currentStudent.year = currentYear;
	currentStudent.grade = currentGrade;

	return currentStudent;
}

void PrintInfo(const Student& student)
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
	default:
		cout << "Year: Error" << endl;
		break;
	}

	cout << "Overall Grade: " << student.grade << endl;
}

int main()
{
	Student student;
	Year year = second;
	int falcultyNum = 12356;
	double grade = 5.67;

	student = initStudent(falcultyNum, year, grade);

	PrintInfo(student);

	return 0;
}
