//Една група се състои от краен брой студенти, като броят на студентите се задава от вас.
//Създайте структура, която описва група.Структурата също така трябва да пази средния успех на групата.
//Направете функция, която създава група, вземайки информация от стандартния вход.
//Средния успех трябва да се сметне след въвеждане на информацията.
//Напишете функция, която приема група и минимален успех за стипендия, и връща колко студента ще получават стипендия.

#include <iostream>

const int peopleInGroup = 4;

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

struct CreateGroup
{
	Student students[peopleInGroup];
	double overallGradeForTheGroup;
};

double GetOverall(const CreateGroup& group)
{
	double sum = 0;
	for (int i = 0; i < peopleInGroup; i++)
	{
		sum += group.students[i].grade;
	}

	return sum / peopleInGroup;
}

CreateGroup initGroup()
{
	CreateGroup group;
	for (int i = 0; i < peopleInGroup; i++)
	{
		Student student;
		cin >> student.facultyNumber;

		int year;
		cin >> year;
		switch (year)
		{
		case 1:
			student.year = first;
			break;
		case 2:
			student.year = second;
			break;
		case 3:
			student.year = third;
			break;
		case 4:
			student.year = fourth;
			break;
		}

		cin >> student.grade;

		group.students[i] = student;
	}

	group.overallGradeForTheGroup = GetOverall(group);
	return group;
}

int GettingSchoolarship(const CreateGroup& group, double min)
{
	int result = 0;
	for (int i = 0; i < peopleInGroup; i++)
	{
		if (group.students[i].grade > min)
			result++;
	}

	return result;
}

int main()
{
	CreateGroup group = initGroup();
	cout << group.overallGradeForTheGroup << endl;
	int peopleWithSchoolarship = GettingSchoolarship(group, 5.50);
	cout << peopleWithSchoolarship << endl;
}
